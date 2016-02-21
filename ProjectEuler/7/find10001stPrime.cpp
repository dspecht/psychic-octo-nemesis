//@author Dustin Specht
// Find the 10,001'st prime number

#include <cstdio>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef uint8_t  u8;
typedef uint32_t u32;
typedef uint64_t u64;

clock_t startTime;
clock_t endTime;

u64 sqrt_u64(u64 n)
{
    u8 shift = 1;
    u64 res, s;

    while((1<<shift) < n) shift += 1;
    res = (1<<((shift>>1) +1));
    for(;;)
    {
        s = (n/res +res)/2;
        if (s >= res) return res;
        res = s;
    }
}

u8* primeSieve(u64 limit)
{
    u8 *sieve; // sieve pointer to be returned
    u64 i;
    u64 j;
    u64 sqrt = sqrt_u64(limit);

    sieve = (u8*)calloc((limit+1),  sizeof(u8));
    if(sieve == NULL)
    { printf("Calloc failed to allocate requested memory"); }

    sieve[0] = 0;
    sieve[1] = 0;
    sieve[2] = 1;

    //set all evens after 2 to be not prime (set odd numbers to prime for now
    for(i=3; i < limit; i++)
    {
        if (i % 2 == 0) sieve[i] = 0;
        else sieve[i] = 1;
    }

    //unset odds that are not prime
    for(i=3; i <= (sqrt+1); i += 2)
    {
        if(sieve[i]==1)
        {
            j = i*3; // if i is prime then a multiple of the prime is not prime
            while(j < limit)
            {
                sieve[j] = 0;
                j += 2*i;
            }
        }

    }
    return sieve;
}

u64 getNPrime(u64 nPrime, u64 limit)
{
    u64 counter = 1;
    u8 *sieveArray = primeSieve(limit);
    u64 *primeArray = (u64*)calloc(nPrime+1, sizeof(u64));
    if(primeArray == NULL)
    { printf("Calloc failed to allocate requested memory"); }

    for(u64 i = 0; i <= limit; i++)
    {
        if((1 & sieveArray[i]) == 1)
        {
            if(!(counter > nPrime))
            {
                primeArray[counter] = i;
                counter++;
            }
        }
    }

    u64 prime = primeArray[nPrime];

    free(primeArray); // clean up even though we don't need this just for a precaution
    free(sieveArray);  // clean up even though we don't need this just for a precaution

    return prime;
}

int main()
{
    startTime = clock();
    u64 limit = 125000;
    u64 nPrime = 10001;
    u64 primeTarget = getNPrime(nPrime, limit);

    printf("\nnth prime is : %lld", primeTarget);
    endTime = clock();

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);
    return 0;
}
