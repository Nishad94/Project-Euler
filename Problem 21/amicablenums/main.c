#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUMBER 10000

long sumOfDiv(int n);

int main()
{
    int i;
    long d1, d2;
    long sum=0;
    for(i=1; i <= MAX_NUMBER;i++){
       d1 = sumOfDiv(i);
       d2 = sumOfDiv(d1);
       if((d2==i) && (d1!=i))
          sum += i;
    }
    printf("%ld",sum);
    return 0;
}

long sumOfDiv(int n){
   int root, i;
   long sum=1;
   root = sqrt(n);
   root++;
   for(i=2; i <= root; i++){
       if(n % i == 0){
          sum += i;
          sum += (n/i);
       }
   }
   return sum;
}
