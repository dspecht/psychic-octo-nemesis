#include <cstdio>
#include <time.h>

#include <thread>
#include <chrono>

#include "das_string.h"
#include "libmpv/client.h"

#define INI_IMPLEMENTATION
#include "ini.h"

clock_t startTime;
clock_t endTime;

bool alarmTriggered = false;

struct Time {
    int year;
    int month;
    int day;

    int hour;
    int min;
    //int sec;
};

Time cTime = {};
Time aTime = {};

void GetCurrentTime() {
    time_t currTime;
    struct tm localTime;

    time(&currTime);
    localtime_s(&localTime, &currTime);

    cTime.year  = localTime.tm_year +1900;
    cTime.month = localTime.tm_mon +1;
    cTime.day   = localTime.tm_mday;

    cTime.hour  = localTime.tm_hour;
    cTime.min   = localTime.tm_min;
//    cTime.sec   = localTime.tm_sec;

    printf("%i/%i/%i | %i:%i\n\n", cTime.month, cTime.day, cTime.year,
            cTime.hour,cTime.min);
}

void mpvCheckError(int status) {
    if (status < 0) {
        printf("mpv API error: %s\n", mpv_error_string(status));
        //exit(1);
    }
}

bool SetupMpv(mpv_handle *mpv) {
    bool result = false;

    if(mpv) {
        mpvCheckError( mpv_set_option_string(mpv, "input-default-bindings", "yes"));
        mpv_set_option_string(mpv, "input-vo-keyboard", "yes");
        int tmp =1;
        mpvCheckError(mpv_set_option(mpv, "osc", MPV_FORMAT_FLAG, &tmp));
        mpvCheckError( mpv_initialize(mpv)); // Actually create the instance

        mpvCheckError(mpv_set_property_string(mpv, "volume", "70"));

        result = true;
    }

    return result;
}

bool CheckAlarmTime() {
    bool result = false;
    GetCurrentTime();

    if(cTime.year  == aTime.year  &&
       cTime.month == aTime.month &&
       cTime.day   == aTime.day)
    {
        if(cTime.hour == aTime.hour &&
           cTime.min  == aTime.min)
        {
            result = true;
        }
    }

    // Check if the month/day has already passed
    if(cTime.month < aTime.month ||
       cTime.day   < aTime.day)
    { printf("Your month or day is off | Please set a valid alarm"); }

    return result;
}

void main() {
    startTime = clock();
// TEMP Alarm Time for testing
    aTime.year   = 2020;
    aTime.month  = 4;
    aTime.day    = 16;

    aTime.hour   = 15;
    aTime.min    = 18;

    //Setup mpv context and control options
    //
    //If this goes into a GUI program this will probably change since
    //  we will want to control the input then but for now it is fine
    mpv_handle *mpv = mpv_create();
    if(!SetupMpv(mpv)){
        printf("Failed to create mpv_handle");
    }

    while(!CheckAlarmTime()) {
        // Look at doing this differently But I did not want to include windows.h
        // so included Thread and Chrono  since they don't seem that big
        std::this_thread::sleep_for( std::chrono::minutes(1));
    }

    const char *cmd[] = {"loadfile",
      "C:/Users/drive/Music/Overkill/The Grinding Wheel/02 - Goddamn Trouble.mp3"
        , NULL};
    mpvCheckError(mpv_command(mpv, cmd));

    // Let it play, and wait until the user quits.
    while (1) {
        mpv_event *event = mpv_wait_event(mpv, 10000);
        printf("event: %s\n", mpv_event_name(event->event_id));
        if (event->event_id == MPV_EVENT_SHUTDOWN)
            break;
    }

    endTime = clock();

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
