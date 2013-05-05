/*
Author: Nishad94
Program: To compute largest palindrome that is a product of 2 3-digit numbers
Problem4
*/
#include <stdio.h>
#include <stdlib.h>

int isPal(long num);

int main()
{
    long a, b, n1, n2, product, largest_pal = 0;
    for(a = 999; a >= 900; a--){
        for(b = a; b >= 900; b--){
            product = a * b;
            if(product > largest_pal){
                        if(isPal(product)){
                            largest_pal = product;
                            n1 = a;
                            n2 = b;
                        }
            }
        }
    }
    printf("%ld = %ld * %ld",largest_pal,n1, n2);
    return 0;
}

int isPal(long num){
    int i, j, num_reverse[8];
    for(i = 0; num > 0 ; i++){
        num_reverse[i] = num % 10;
        num /= 10;
    }
    num_reverse[i] = '\0';
    for(j = 0, i -= 1; j < i; j++,i--){
        if(num_reverse[j] != num_reverse[i])
              return 0;
    }
    return 1;
}
