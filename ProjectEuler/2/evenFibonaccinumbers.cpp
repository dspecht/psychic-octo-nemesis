// @author Dustin Specht
// Question| By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

unsigned int fibNum1 = 0;
unsigned int fibNum2 = 1;
unsigned int currentFoundFib = 0;
unsigned int MAX = 4000000; // 4 Million

unsigned int totalSum = 0;

void main()
{
    startTime = clock();
    do
    {
        currentFoundFib = fibNum1 + fibNum2;
        fibNum2 = fibNum1;
        fibNum1 = currentFoundFib;

        if(currentFoundFib % 2 == 0)
        {
            totalSum += currentFoundFib;
        }

    }
    while(currentFoundFib <= MAX);
    endTime = clock();

    printf("The sum is: %d", totalSum);

    float diff((float)endTime - (float)startTime);
    printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);
}
