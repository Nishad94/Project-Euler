#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("input","r");
    int i, j;
    int c;
    long product=1, num[1000], largest = 1;
    for(i=0; i < 1000; i++){
       while((c = fgetc(fp)) == '\n')
       ;
       num[i] = c - '0';
    }
    for(i=0; i < 1000; i++){
     for(j = i; j < (i+5); j++)
       product *= num[j];

     if(product > largest)
     largest = product;

     product = 1;
    }
    printf("%lld",largest);
    return 0;
}
