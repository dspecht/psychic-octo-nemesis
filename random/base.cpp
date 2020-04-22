// Given an array of integers, find the most frequent integer
// Write a method that takes an array of integers and returns an integer
// {1, 2, 3, 3} => 3
// {1,2,3} => 1 (or 2 or 3)

#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;
unsigned int answer;

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

struct dict
{
    int key;
    int amount;
};

int findMostCommonInt(int array[], int length)
{
    dict *results = new dict[length];

    for(int i = 0; i <= length; i++)
    {
        for(int j = 0; j <= length; j++)
        {
            if (array[i] == results[j].key)
            {
                results[j].amount += 1;
            }
        }
    }

    int slot = 0;

    for(int i = 0; i <= length; i++)
    {
        if(results[i].amount > results[slot].amount) slot = i;
    }

    return results[slot].key; // The actual number that was the most frequent
}

void main()
{
    startTime = clock();

    int x[] = {1,1,2,2,3,3,3,5,5,7,7,7,7,7,7,7,7,7,7};
    int l = ArrayCount(x);

    answer = findMostCommonInt(*x, l);

    endTime = clock();

    printf("Answer is: %d", answer);

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
