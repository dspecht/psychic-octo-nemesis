//@author Dustin Specht
//Find the sum of the squares of the first 100 natural numbers,
//Find the square of the sum of the first 100 natural numbers,
//Find the difference bewteen the sum of the square and the square of the sum
#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

typedef unsigned int uint;

void main()
{
    startTime = clock();
    uint sumofSquares = 0;
    uint squareofSums = 0;
    uint difference = 0;
    for(uint i = 1; i <= 100; i++)
    {
        sumofSquares += i*i;
        squareofSums += i;
    }
    squareofSums *= squareofSums;
    difference = squareofSums - sumofSquares;

    endTime = clock();
    printf("Answer : %d", difference);

    float diff((float)endTime - (float)startTime);
    printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);
}
