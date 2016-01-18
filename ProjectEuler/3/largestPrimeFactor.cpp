// Question| What is the largest prime factor of the number 600851475143 ?3
#include <stdio.h>
#include <time.h>
clock_t startTime;
clock_t endTime;
int main()
{
    startTime = clock();
    // Define Vars
    long long i, sqi;
    long long value, startingValue = 600851475143LL;
    long long max = 0LL;

    //Init base vars
    i   = 2LL;
    sqi = 4LL; //i*i

    //Set value to be the starting value (startingValue),
    //See if the square of i is less then or equal to the value
    //(2 * i) + 1 + sqi         (starting would be 2*2+2+4 = 4+2+4 = 6+4 = 10
    //i gets incremented to 3 after it gets used here
    for(value = startingValue; sqi <= value ; sqi +=  2LL * i++ + 1LL)
    {
        while(value % i == 0LL)
        {
            value /= (max=i);
        }
    }

    //checks to see if value is not 1 or the starting value
    if(value != 1LL && value != startingValue)
    {
        max = value;
    }

    //if it got to 0 that means the startingValue was prime therfor the largest prime factor
    if(max == 0LL)
    {
        max = startingValue;
    }

    endTime = clock();
    printf("%lld\n", max);

    float diff((float)endTime - (float)startTime);
    printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);

    return 0;
}
