#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 1001

int fib_with_digits(int n);

int answer[MAX_DIGITS], prev[MAX_DIGITS], prev_minus[MAX_DIGITS];

int main()
{
    int number;
    number = fib_with_digits(1000); //1000 digit fibonacci
    printf("%d",number);
    return 0;
}

int fib_with_digits(int n){
    int i, current_term=2, result, carry=0, current_pos=0, msb_pos1 = 0, msb_pos2 = 0, largest_msb;
    answer[0] = 1;
    prev[0] = 1;
    prev_minus[0] = 1;
    while(current_pos < n){
        if(msb_pos1 > msb_pos2)
          largest_msb = msb_pos1;
        else
           largest_msb = msb_pos2;

     /*   if(current_pos1 > current_pos2)
           largest = current_pos1;
        else
           largest = current_pos2;  */

        for(i=0, carry=0, current_pos=0; i <= largest_msb; i++){
            result = prev[i] + prev_minus[i] + carry;
            if(i == largest_msb){
                while(result > 0){
                answer[current_pos++] = result % 10;
                result /= 10;
            }
        }
            else{
               answer[current_pos++] = result % 10;
               carry = result/10;
            }
    }
        current_term++;
        //copy prev[] to prev_minus[], and answer[] to prev[]
        for(i=0; i<=msb_pos1; i++)
           prev_minus[i] = prev[i];
        msb_pos2 = msb_pos1;
        for(i=0; i < current_pos; i++)
           prev[i] = answer[i];
        msb_pos1 = current_pos - 1;
}

  return current_term;
}
