#include "curl/curl.h"
#include <cstdio>
#include <time.h>

clock_t startTime;
clock_t endTime;
unsigned int answer;

void main()
{
    startTime = clock();

    float tempShift = 273.15;
    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, "https://community-open-weather-map.p.rapidapi.com/weather?id=4119403&units=%2522imperial%2522&q=Little%20Rock%252C%20US");

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "x-rapidapi-host: community-open-weather-map.p.rapidapi.com");
    headers = curl_slist_append(headers, "x-rapidapi-key: 4fc24b1155msh74b976c53fbe648p192d4fjsn4f40b47dbb41");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    CURLcode ret = curl_easy_perform(hnd);

    endTime = clock();

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
