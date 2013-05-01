#include <stdio.h>
#include <stdlib.h>
#define fc fib_current
#define fp fib_prev
#define fpp fib_before_prev
#define LIMIT 4000000

long long fib_total(long low, long high) {
    long fc=2,fp = 2,fpp = 1;
    long long total=0;
    while(fc <= high){
            if(!(fc & 1))
            total += fc;
        fc = fp + fpp;
        fpp = fp;
        fp = fc;
    }

    return total;
}

int main()
{
    long long sum;
    sum = fib_total(1,LIMIT);
    printf("%lld\n",sum);
    return 0;
}
