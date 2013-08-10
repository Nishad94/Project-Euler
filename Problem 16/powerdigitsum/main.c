#include <stdio.h>
#include <stdlib.h>
#define max_pow 1000
int main()
{
    int number[10000]={0}, temp_pos, carry, i, last_digit_pos=0, temp;
    number[0] = 1;
    for(i=1; i<= max_pow; i++){
       temp_pos = 0;
       carry = 0;
       while(temp_pos <= last_digit_pos){
           temp = ((number[temp_pos] * 2) + carry);
           if(temp >= 10){
              number[temp_pos] = temp % 10;
              carry = temp/10;
              if(temp_pos == last_digit_pos)
                 last_digit_pos++;
              temp_pos++;
           }
           else{
             number[temp_pos] = temp;
             carry = 0;
             temp_pos++;
           }
       }
       }
       for(i=last_digit_pos,temp=0; i>=0; i--){
       printf("%d",number[i]);
       temp += number[i];
       }
       printf(" %d",temp);
       return 0;
}
