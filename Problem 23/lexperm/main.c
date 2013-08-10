#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBER 1000000

long factorial(int n);

int main()
{
    int numbers[10];
    int i, j;
    long current_number=0;
    for(i=0; i < 10; i++){
        numbers[i] = i;
    }
    for(i=0;current_number < MAX_NUMBER; i++){

    }
    return 0;
}

long factorial(int n){
   int i;
   long result;
   for(i=1; i<=n; i++){
       result *= i;
   }
   return result;
}
