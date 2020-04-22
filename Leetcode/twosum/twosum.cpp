/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <cstdio>
#include <time.h>
clock_t startTime;
clock_t endTime;

struct Result {
    int x,y;
};
Result answer;

Result brutetwosum(int array[], int targetNum)
{
    int aLen = (sizeof(array) / sizeof((array[0])) );
    Result indexes = {0,0};


    for(int i=0; i < aLen; i++) {
        for(int j=1; j < aLen; j++) {
            if(array[i] + array[j] == targetNum && i != j) {
                printf("i: %i, j: %i\n", i,j);
                indexes.x = i;
                indexes.y = j;
                return indexes;
            }
        }
    }
    // printf("value: %i[%i] + value: %i[%i] = target %i",
    //        array[indexes.x],indexes.x,
    //        array[indexes.y],indexes.y,
    //        targetNum);
    indexes = {-1,-1}; // If
    return indexes;
}

Result subtracttwosum(int array[], int targetNum)
{
    int aLen = (sizeof(array) / sizeof((array[0])) );
    Result indexes = {0,0};

    for(int i=0; i < aLen; i++) {
        if(array[i] < targetNum) {
            for(int j=i; j < aLen; j++) {
              // Since you have to be less then the targetNum nothing before
              //    this number so it can't be possible for the match to
              //    be before this index.

                int temp = targetNum - array[i]; // find actual value for answer
                if (array[j] == temp && j != i) {
                    indexes.x = i;
                    indexes.y = j;
                    return indexes;
                }
            }
        }
    }
    indexes = {-1,-1};
    return indexes;
}

void main()
{
    startTime = clock();
    int test[] = {2,7,11,15};

    answer = brutetwosum(test, 9);
        if(answer.x != -1)
            printf("Brute Answer is indexes: %d | %d\n", answer.x, answer.y);
        else printf("Brute: No indexes add to equal the given target\n");


    answer = subtracttwosum(test, 9);
        if(answer.x != -1)
            printf("Subtract Answer is indexes: %d | %d\n", answer.x,answer.y);
        else printf("Subtrct: No indexes add to equal the given target\n");


    endTime = clock();

//    if(answer.x != -1)
//        printf("Answer is indexes: %d | %d", answer.x, answer.y);
//    else printf("No indexes add to equal the given target");

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
