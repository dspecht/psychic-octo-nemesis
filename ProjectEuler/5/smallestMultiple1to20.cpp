//@author Dustin Specht
//Smallest multiple that is even divisible by all numbers 1 - 20

#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;
typedef unsigned int uint;

uint mult = 20;

bool testMult()
{
    bool isGood = true;
    for(uint i = 20; i >= 1; i--)
    {
        if(mult % i != 0)
        {
            isGood = false;
        }
    }
    return isGood;
}

void main()
{
    startTime = clock();
    bool finished = false;
    while(!finished)
    {
        if(testMult())
        {
            printf("the smallest multi is : %d", mult);
            finished = true;
        }
        else
        {
            mult += 20;
        }
    }
    endTime = clock();
    float diff((float)endTime - (float)startTime);
    printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);
}

