#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

unsigned int MAX = 1000;
unsigned int answer = 0;

unsigned int solve()
{
    unsigned int a, b, c;
    a = 1;
    for(;a < MAX/3; a++)
    {
        for(b=a+1; b < MAX/2; b++)
        {
            c = MAX - a - b;
            if((a*a) + (b*b) == (c*c))
                return(a*b*c);
        }
    }
    return 0;
}

void main()
{
    startTime = clock();
    answer = solve();
    endTime = clock();
    printf("\nAnswer is: %d", answer);

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
