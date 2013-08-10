#include <stdio.h>
#include <stdlib.h>
//1st Jan 1901 = Tuesday
int main()
{
    int day[7] = {0}, years, month[12], current_first = 5;
    int i, flag=0;
    for(i=0; i<=6; i++){
       if(i%2==0)
          month[i] = 31;
       else
          month[i] = 30;
    }
    month[1] = 28;
    for(i=7; i<12; i++){
       if(i%2==0)
          month[i] = 30;
        else
           month[i] = 31;
    }
    for(i=0; i<12; i++)
       printf("%d ",month[i]);
    for(years=1; years < 101; years++){
        if(years%4==0)
           month[1] = 29;
        else
           month[1] = 28;
         for(i=0; i<12; i++){
             if(i == 0){
                 flag = 1;
                 i = 12;
             }
               if(month[i-1] == 31){
                   current_first = (current_first + 3) % 7;
               }
               else if(month[i-1] == 30){
                  current_first = (current_first + 2) % 7;
               }
               else if(month[i-1] == 29){
                  current_first = (current_first + 1) % 7;
               }
               else
                   ;

                day[current_first]++;
                if(flag == 1){
                   i = 0;
                   flag = 0;
                }
         }
    }
    printf("%d",day[6]);
    return 0;
}
