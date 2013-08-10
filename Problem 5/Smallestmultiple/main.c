#include <stdio.h>
#include <stdlib.h>
#define LIMIT 20
//To find LCM of numbers 1..20;

int main()
{
    long numbers[21], lcm=1;
    int i, j, factor;
    for(i=0; i <= LIMIT; i++)
       numbers[i] = i;

    for(i = 2; i <= LIMIT; i++){
       if(numbers[i] != 1){
          lcm *= numbers[i];
          factor = numbers[i];
          for(j = 2; j <= LIMIT; j++){
              if(numbers[j] % factor == 0)
                 numbers[j] /= factor;
          }
       }

    }
    printf("%ld",lcm);
    return 0;
}
