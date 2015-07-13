//@author Dustin Specht
//Smallest multiple that is even divisible by all numbers 1 - 20

#include <cstdio>
typedef unsigned int uint;

uint mult = 20;

bool testMult()
{
    bool isGood = true;
    for(uint i = 20; i >= 1; i--)
    {
        if(mult % i != 0)
        {
            isGood = false;
        }
    }
    return isGood;
}

void main()
{
    bool finished = false;
    while(!finished)
    {
        if(testMult())
        {
            printf("the smallest multi is : %d", mult);
            finished = true;
        }
        else
        {
            mult += 20;
        }
    }
}

