#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_prime 20 //max number of primes to calculate
typedef struct primes
{
    int number;
    int occurence;
}
Primes;

int main()
{
    Primes pn[max_prime];
    int i, j, k=1, temp1, n, divisors;
    long product, final_prod;
    pn[0].number = 2;
    for(i=2; k < max_prime; i++){
        temp1 = sqrt(i);
        temp1++;
        for(j=2; j<=temp1; j++){
            if(i%j==0)
               break;
        }
        if(j > temp1){
            pn[k].number = i;
            k++;
        }
    }
    for(n=10; ;n++){
        product = n * (n+1);
        product /= 2;
        final_prod = product;
        divisors = 1;
        for(k=0;k<max_prime;k++)
        pn[k].occurence=0;
        k=0;
        while(product > 1 && k < max_prime){
                while(product % pn[k].number == 0){
                    pn[k].occurence++;
                    product /= pn[k].number;
                }
                k++;
        }
        for(k=0; k<max_prime; k++){
           divisors *= (pn[k].occurence + 1);
        }
        if(divisors >= 500)
        break;
    }
    printf("%ld",final_prod);
    return 0;
}
