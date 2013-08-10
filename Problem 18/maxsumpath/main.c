#include <stdio.h>
#include <stdlib.h>
#define rows 100

long long max(int i, int j);

long long grid[100][100];

int main()
{
    FILE *fi, *fo;
    fi = fopen("input.in","r");
    fo = fopen("output.out","w");
    int i, j;
    long long largest_sum=0;
    for(i=0; i<rows; i++){
        for(j=0; j<=i; j++)
           fscanf(fi,"%d",&grid[i][j]);
    }
    for(i=0; i<rows; i++){
       for(j=0; j<=i; j++){
          grid[i][j] += max(i,j); //grid(i,j) can be added to i-1,j or i-1,j-1 . We want the max sum.
          printf("%lld ",grid[i][j]);
       }
       printf("\n");
    }
    for(i = (rows-1),j=0; j <= i; j++){
      if(grid[i][j] > largest_sum)
         largest_sum = grid[i][j];
    }
    fprintf(fo,"%lld",largest_sum);
    return 0;
}

long long max(int i, int j){
    if(i == 0)
        return 0;
    else if(j == 0)
        return grid[i-1][j];
    else if(j == i)
        return grid[i-1][j-1];
    else {
        if(grid[i-1][j] > grid[i-1][j-1])
           return grid[i-1][j];
        else
           return grid[i-1][j-1];
    }
}
