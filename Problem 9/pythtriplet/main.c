#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000
int main()
{
    long a, b, c, temp1, temp2;
    long long product;
    int i, j;
    for(i = 1; i < LIMIT; i++){
        temp1 = 500000 - (1000* i);
        temp2 = 1000 - i;
        if(temp1 % temp2 == 0){
           b = i;
           a = temp1 / temp2;
           c = 1000 - (a + b);
           temp1 = a*a + b*b;
           if(temp1 == (c*c))
           break;
        }
    }
    product = a*b*c;
    printf("%ld %ld %ld %lld",a, b, c,product);
    return 0;
}
