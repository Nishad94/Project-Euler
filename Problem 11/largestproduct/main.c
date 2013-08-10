#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    int i, j, temp_i, temp_j, matrix[20][20], counter=0;
    long long largest_product=0, product=1;
    //Reading 20*20 grid
    for(i=0; i<20; i++){
       for(j=0; j<20; j++){
           fscanf(fp1,"%d",&matrix[i][j]);
           printf("%d ",matrix[i][j]);
       }
       printf("\n");
    }
    /*Horizontal largest product*/
    for(i=0; i<20; i++){
       for(j=0; j<17; j++){
           counter=0;
           product=1;
           temp_i=i;
           temp_j=j;
            while(counter < 4){
                product *= matrix[temp_i][temp_j];
                temp_j++;
                counter++;
            }
            if(product > largest_product)
              largest_product = product;
       }
    }
    //Vertical largest product
    for(j=0; j<20; j++){
        for(i=0; i<17; i++){
            counter=0;
            product=1;
            temp_i=i;
            temp_j=j;
            while(counter < 4){
                  product *= matrix[temp_i][temp_j];
                  temp_i++;
                  counter++;
            }
            if(product > largest_product)
              largest_product = product;
        }
    }
    //Diagonal largest product,top left to bottom right
    for(i=0; i<17; i++){
        for(j=0; j<17; j++){
            counter=0;
            product=1;
            temp_i = i;
            temp_j = j;
            while(counter < 4){
                product *= matrix[temp_i][temp_j];
                temp_i++;
                temp_j++;
                counter++;
            }
            if(product > largest_product)
            largest_product = product;
        }
    }
    //Diagonal largest product,top right to bottom left
    for(i=0; i<17; i++){
       for(j=19; j>2; j--){
            counter=0;
            product=1;
            temp_i = i;
            temp_j = j;
            while(counter < 4){
                product *= matrix[temp_i][temp_j];
                temp_i++;
                temp_j--;
                counter++;
            }
            if(product > largest_product)
            largest_product = product;
       }
    }
    fprintf(fp2,"%lld",largest_product);
    return 0;
}
