// @author Dustin Specht | Project Euler Question 1
// Question| Find the sum of all the multiples of 3 or 5 below 1000.
#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

int MAX = 1000;
int searchMultiplesof[] = {3, 5}; // maybe do seperate vars for each?
int sum = 0;

void main()
{
   startTime = clock();
   int numMultiplesFound = 0;
   for(int numToTry = 1; numToTry < MAX; numToTry++)
   {
        if(numToTry % searchMultiplesof[0] == 0 || numToTry % searchMultiplesof[1] == 0) // 3 or 5
        {
            sum += numToTry;
        }
   }
   endTime = clock();
   printf("The total sum is: %d", sum);

   float diff((float)endTime - (float)startTime);
   printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);
}
