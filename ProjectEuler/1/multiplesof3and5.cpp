// @author Dustin Specht | Project Euler Question 1
// Question| Find the sum of all the multiples of 3 or 5 below 1000.
#include <cstdio>

int MAX = 1000;
int searchMultiplesof[] = {3, 5}; // maybe do seperate vars for each?
int sum = 0;

void main()
{
   int numMultiplesFound = 0;
   for(int numToTry = 1; numToTry < MAX; numToTry++)
   {
        if(numToTry % searchMultiplesof[0] == 0 || numToTry % searchMultiplesof[1] == 0) // 3 or 5
        {
            sum += numToTry;
        }
   }
   printf("The total sum is: %d", sum);
}
