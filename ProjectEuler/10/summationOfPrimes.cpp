#include <cstdio>
#include <time.h>
#include <stdint.h>
#include <malloc.h>

clock_t startTime;
clock_t endTime;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

u64 sqrt_u64(u64 n)
{
    u8 shift = 1;
    unsigned long long res, s;

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
    unsigned long long i;
    unsigned long long j;
    unsigned long long sqrt = sqrt_u64(limit);

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

void main()
{
    unsigned long long max = 2000000;
    unsigned long long answer = 0;
    startTime = clock();
    u8* sieve = primeSieve(max);
    for(u64 i = 0; i < max; i++)
    {
        if(sieve[i] == 1)
            answer += i;
    }
    endTime = clock();

    printf("Answer is: %lld", answer);

    double diff((double)endTime - (double)startTime);
    printf("\n\ntask completed in %f seconds", double(diff)/CLOCKS_PER_SEC);
}
