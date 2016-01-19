#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;
unsigned int answer;

void main()
{
    startTime = clock();

    endTime = clock();

    printf("Answer is: %d", answer);

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
