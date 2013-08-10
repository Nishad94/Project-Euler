/*
Project Euler
Problem 10: Summation of Primes
*/
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 2000000

long long primes[2000002]; //global variable allocation due to memory limits.. look for this online!

int main()
{
    long long sum=0, i, j;
    for(i=0; i <= LIMIT; i++)
    primes[i] = i;
    primes[0] = -1;
    primes[1] = -1;
    for(i = 2; i <= LIMIT; i++){
       while((primes[i] == -1) && (i <= LIMIT))
          i++;
       sum += primes[i];
       if(i <= LIMIT) {
           for(j = primes[i]; (primes[i] * j) <= LIMIT; j++){
               primes[(primes[i]*j)] = -1;
            }
       }
    }
    printf("%lld", sum);
    return 0;
}
