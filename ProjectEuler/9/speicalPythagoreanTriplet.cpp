#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

unsigned int MAX = 1000

void main()
{
    startTime = clock();

    unsigned int a, b, c;
    a = 1; b = 2; c = 3;
    unsigned int answer = 0;
    while(a+b+c != MAX && a+b+c <= MAX
    {
        if(a < b && b < c)
        {
            while(b < MAX-2)
            {
                while(c < MAX-3)
                {
                    if(a+b+c == MAX)
                    {
                        answer = a*b*c;
                        continue;
                    }
                    c++;
                }
                c = (b+2);
                b++;
            }
            b = (a+2);
            a++;
        }
    }

    endTime = clock()

    if(answer)
        printf("Answer is: %d", answer);

    float diff((float)endTime - (float)startTime);
    printf("task completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
