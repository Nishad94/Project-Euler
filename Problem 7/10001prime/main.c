#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 1000001

long long primes[1000003];

int main()
{
    long i, j, temp2, serialno=0;
    long div, temp;
    for(i = 0; i <= LIMIT; i++)
       primes[i] = i;
    primes[0] = -1;
    primes[1] = -1;
    temp2 = sqrt(LIMIT);
    for(i = 2; i <= temp2; i++){
       while((primes[i] == -1) && (i<=LIMIT))
           i++;
       for(j = primes[i]; (temp = j*primes[i]) <= LIMIT; j++){
           primes[temp] = -1;
       }
    }
    for(i = 2; i <= LIMIT; i++){
       if(primes[i] == -1)
        ;
       else{
         serialno++;
         if(serialno == 6)
         break;
       }
    }
    printf("%lld",primes[i]);
    return 0;
}
