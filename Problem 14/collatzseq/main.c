#include <stdio.h>
#include <stdlib.h>
#define LARGEST 1000000
int main()
{
    long i,chain,largest_chain=1,largest_num,temp_num;
    for(i=2; i<=LARGEST;i++){
        chain=0;
        temp_num=i;
        while(temp_num != 1){
        if(temp_num%2){          //odd
            temp_num *= 3;
            temp_num++;        //n = 3n + 1
            chain++;
        }
        else{
           temp_num /= 2;
           chain++;
        }
        }
        if(chain > largest_chain){
           largest_chain = chain;
           largest_num = i;
        }
    }
    printf("%ld",largest_num);
    return 0;
}
