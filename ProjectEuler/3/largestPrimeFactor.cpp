// @author Dustin Specht
// Question| What is the largest prime factor of the number 600851475143 ?
#include <cstdio>
#include <cstdint>

int numberToFactor = 225;
int factors[512] = {0};
int numberOfFactorsFound = 1;
int largestPrimeFactor = 1;
int primeFactorList[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,58,61,67,71,73,79,83,89,97};// Prime factors 1 - 100

bool checkFactorizationCorrect()
{
    bool factorizationIsCorrect = false;
    int total = 1;

    printf("numberOfFactorsFound: %d\n", numberOfFactorsFound);

    for(int i = 0; i < numberOfFactorsFound; i++)
    {
        total = total * factors[i];
        //printf("%d ", total);

        if(factors[i] > largestPrimeFactor)
        {
            largestPrimeFactor = factors[i];
        }
    }

    if (total == numberToFactor)
    {
        printf("\nSUCCESS: largest prime factor is: %d\n", largestPrimeFactor);
        factorizationIsCorrect = true;
    }

    return factorizationIsCorrect;
}

void main()
{
    factors[0] = 1;
    bool factorNotFound = true;
    int iter = 0;
    bool finished = false;

    while(!finished)
    {
        while(factorNotFound)
        {
            if(numberToFactor % primeFactorList[iter] == 0) // divides evenly
            {
                printf("Factor Found %d\n", primeFactorList[iter]);

                factors[numberOfFactorsFound] = primeFactorList[iter];

                numberToFactor = numberToFactor / primeFactorList[iter];

                factorNotFound = false;
                numberOfFactorsFound += 1;
                iter = 0;
            }
            else
            {
                printf("Tried prime number: %d\n", primeFactorList[iter]);
                iter++;
            }
        }

        factorNotFound = true;
        finished = checkFactorizationCorrect();
    }
}

