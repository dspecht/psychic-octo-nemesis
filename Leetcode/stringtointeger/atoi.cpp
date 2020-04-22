/*  LEETCODE #8
 * implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the
first non-whitespace character is found. Then, starting from this character, takes
an optional initial plus or minus sign followed by as many numerical digits as
possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral
number, or if no such sequence exists because either str is empty or it contains
only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out
of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/

#include <cstdio>
#include <malloc.h>
#include <time.h>
clock_t startTime;
clock_t endTime;
unsigned int answer;

inline unsigned int getStringLength(char* input) {
    unsigned int length = 0;
    while(*input++ != 0) {++length;}
    return length;
}

char*
copyString(char* input)
{
    unsigned int length = getStringLength(input);
    char* result = {(char*)calloc((length +1), sizeof(char))};
    if(length != 0)
    {
        for(unsigned int i = 0; i < length; i++)
        {
            result[i] = input[i];
        }
    }
    else { result = {}; }
    return result;
}


//Nx10^n
int Npow10(int N, int n){
  N <<= n;
  while(n--) N += N << 2;
  return N;
}

int atoi() {
    //String.c_str to get normal c string data
    //int = sLen = String.Length + 1;
    //char* input = new char [String.length()+1];
    //inputString = String.c_str;
    int sLen = 10;
    char* input = "    +1337 ";

    char nString[10];
    int counter = 0;

    //clean whitespace from front
    for(int i = 0; i < sLen; i++) {
        if(input[i] != ' ') {
            nString[counter] = input[i];
            counter++;
        }
    }

    sLen = counter;
    counter = 0;
    char sign;
    char numstring[10];

    if(nString[0] == '+' || nString[0] == '-') {
        sign = nString[0];
    }

    int j = 0;
    if(sign) { j = 1; }

    for(; j < sLen; j++) {
        if(nString[j] >= 48 && nString[j] <= 57) { // 0 - 9 is ascii 48 to 57
            numstring[counter] = nString[j];
            counter++;
        }
        else{
            break; // If not a number stop since we only want the first intergal array
        }
    }

    if(counter == 0) {
        return 0;
    }


    sLen = counter;
    counter = 0;

    int result[10] = {};

    for(int i = 0; i < sLen; i++) {
        switch(numstring[i]) {
            case 48: result[counter] = 0;
            case 49: result[counter] = 1;
            case 50: result[counter] = 2;
            case 51: result[counter] = 3;
            case 52: result[counter] = 4;
            case 53: result[counter] = 5;
            case 54: result[counter] = 6;
            case 55: result[counter] = 7;
            case 56: result[counter] = 8;
            case 57: result[counter] = 9;
            default: break;
        }
        counter++;
    }

    int answer = 0;
    for(int i = 0; i < sLen; i++) {
        answer += result[i] * Npow10(10, sLen - i - 1);
    }

    return answer;
}

void main() {
    startTime = clock();

    printf("result: %d", atoi());

    endTime = clock();

    //printf("Answer is: %d", answer);

    float diff((float)endTime - (float)startTime);
    printf("\n\ntask completed in %f seconds", float(diff)/CLOCKS_PER_SEC);;
}
