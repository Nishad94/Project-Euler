#include <stdio.h>
#include <stdlib.h>
#define DIGITS 10

long factorial(int n);

int main()
{
    int i, number[DIGITS], current_digit, shift, temp;
    long reqd_n = 1000000, temp_fact;
    for(i=0; i<DIGITS; i++){
       number[i] = i;
    }
    for(current_digit=0; ;current_digit++){
      temp_fact = factorial(DIGITS - current_digit - 1);
      shift = reqd_n / temp_fact;
      if(reqd_n % temp_fact == 0){
         shift--;
         temp = number[(current_digit+shift)];
         while(shift){
            number[current_digit + shift] = number[current_digit + shift - 1];
            shift--;
         }
         number[current_digit] = temp;
         for(i=0; i<=current_digit;i++)
           printf("%d",number[i]);
         for(i=(DIGITS - 1); i > current_digit; i--)
           printf("%d",number[i]);
         exit(1);
      }
      else if(reqd_n == 1){
         for(i=0; i < DIGITS; i++)
            printf("%d",number[i]);
        exit(1);
      }
      else{
         temp = number[(current_digit+shift)];
         while(shift){
            number[(current_digit + shift)] = number[(current_digit + shift - 1)];
            shift--;
         }
         number[current_digit] = temp;
         reqd_n %= temp_fact;
      }
    }
    return 0;
}

long factorial(int n){
  int i = 2;
  long result=1;
  while(i <= n){
    result *= i;
    i++;
  }
  //printf("%ld\n",result);
  return result;
}
