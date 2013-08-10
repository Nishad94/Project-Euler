#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define NUM1 3
#define NUM2 5          // Sum of multiples of 3 and 5 are to be calculated below 1000
#define LIMIT 1000

/*
Project Euler Problem 1
Simple iterative version
*/

int main()
{
    long long Total = 0;
    int i;
    //clock_t start = clock();
    for(i = 1; i < LIMIT; i++)
        if(((i % NUM1) == 0) || ((i % NUM2) == 0))
             Total += i;
    //clock_t end = clock();
    //float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%lld",Total);
    return 0;
}
