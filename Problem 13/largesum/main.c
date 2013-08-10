#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1,*fp2;
    fp1 = fopen("input.in","r");
    fp2 = fopen("output.out","w");
    int numbers[100][50], sum[70], c, i=0, j=0, k=0;
    long carry=0, temp=0;
    while((c = fgetc(fp1)) != EOF){
         if(c == '\n'){
           i++;
           j=0;
         }
         else{
            //printf("%d %d\n",i,j);
            numbers[i][j] = (c - '0');
            j++;
         }
    }
    for(j=49; j>0; j--){
       for(i=0;i<100;i++){
         carry += numbers[i][j];
       }
       sum[k] = (carry%10);
       k++;
       carry /= 10;
    }
    //first column
    for(i=0;i<100;i++)
      carry += numbers[i][j];
      printf("%d",carry);
    while(carry > 0){
       sum[k] = (carry % 10);
       k++;
       carry /= 10;
    }
    k--;
    while(temp<10){
    fprintf(fp2,"%d",sum[k]);
    k--;
    temp++;
    }
    fprintf(fp2,"\n");
    for(k=0; k<10; k++)
    fprintf(fp2,"%d",sum[k]);
    return 0;
}
