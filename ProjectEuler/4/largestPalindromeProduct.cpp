//@author Dustin Specht
//Find the largest palindrome made from the product of two 3-digit numbers.
//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

void main()
{
    startTime = clock();
    unsigned int product = 0;
    unsigned int totalproduct = 0;
    unsigned int productArray[6] = {0};
    unsigned int largerstPalindrome = 0;

    for(int i = 999; i > 100; i--)
    {
        for(int j = 101; j < 1000; j++)
        {

            totalproduct = i * j;
            product = totalproduct;
            for(int k = 0; k < 6; k++)
            {
                //printf("\n %d", product);
                //printf("iterator: %d", k);
                productArray[k] = product % 10;
                product /= 10;
            }

            if((productArray[0] == productArray[5])
            && (productArray[1] == productArray[4])
            && (productArray[2] == productArray[3])
            && (productArray[3] == productArray[2])
            && (productArray[4] == productArray[1])
            && (productArray[5] == productArray[0]))
            {
                if (!productArray[5] == 0) // only show relevent 6 digit solutions
                    printf("\nIs palidrome: %d\n", totalproduct);
                if(totalproduct > largerstPalindrome) {largerstPalindrome = totalproduct;}
            }
        }
    }
    endTime();

    printf("LARGEST PALINDROME: %d", largerstPalindrome);

    float diff((float)endTime - (float)startTime);
    printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);
}
