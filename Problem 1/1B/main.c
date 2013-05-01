#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define NUM1 3
#define NUM2 5          // Sum of multiples of 3 and 5 are to be calculated below 1000
#define LIMIT 1000000000

/*
Sum(S) of multiples of a number k uptil n: k +2k +3k +4k...+ int(n-1/k)*k.
(n/k)*k is an integral value just lesser than or equal to n.
S = k(1+2+3+4+...+p), where p = n-1/k
S = k.p.(p+1) / 2
*/
long long sum(int k, int n){
   long long p, S;
   p = (n - 1)/k;
   S = k * p * (p+1) / 2;
   return S;
}

int main()
{
    long long Total;
    clock_t start = clock();
    Total = sum(NUM1,LIMIT) + sum(NUM2,LIMIT) - sum(NUM1*NUM2,LIMIT);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%lld %f",Total,seconds);
    return 0;
}
