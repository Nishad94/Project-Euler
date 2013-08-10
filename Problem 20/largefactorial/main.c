#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAYSIZE 100
void factorial(int n);
void print_factorial(void);
long sum_of_digits(void);

int answer[MAX_ARRAYSIZE], last_digit_pos;

int main()
{
    int number;
    long sum;
    printf("Enter number : ");
    scanf("%d",&number);
    putchar('\n');
    factorial(number);
    print_factorial();
    sum = sum_of_digits();
    printf("\nSum of digits = %ld",sum);
    return 0;
}

void factorial(int n){
   int result, carry=0, currentbit_pos=0, msb_pos=0, i;
   answer[0] = 1;
   for(i=1; i <= n; i++){
      for(currentbit_pos=0, carry=0; currentbit_pos <= msb_pos; ){
         result = (answer[currentbit_pos] * i) + carry;
         if(currentbit_pos == msb_pos){
             while(result > 0){
                answer[currentbit_pos++] = result % 10;
                result /= 10;
             }
             msb_pos = currentbit_pos - 1;
         }

         else{
            answer[currentbit_pos++] = result % 10;
            carry = result / 10;
         }
      }
   }
   answer[currentbit_pos] = '\0';
   last_digit_pos = --currentbit_pos;
   return;
}

void print_factorial(void){
    int i;
    for(i=last_digit_pos; i>=0; i--)
       printf("%d",answer[i]);
    printf("\n");
    return;
}

long sum_of_digits(void){
   long sum=0;
   int i;
   for(i=last_digit_pos; i>=0; i--)
     sum += answer[i];
   return sum;
}
