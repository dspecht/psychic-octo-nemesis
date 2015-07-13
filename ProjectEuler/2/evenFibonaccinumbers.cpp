// @author Dustin Specht
// Question| By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
#include <cstdio>

unsigned int fibNum1 = 0;
unsigned int fibNum2 = 1;
unsigned int currentFoundFib = 0;
unsigned int MAX = 4000000; // 4 Million

unsigned int totalSum = 0;

void main()
{
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

    printf("The sum is: %d", totalSum);
}
