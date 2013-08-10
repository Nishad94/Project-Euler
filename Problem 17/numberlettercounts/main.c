#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
int number;
char spelling[15];
int length;
} num_db;

int main()
{
    FILE *fi, *fo;
    fi = fopen("input.in","r");
    fo = fopen("output.out","w");
    num_db db[30];
    int c, i=0, j, temp, one_to_nine_addn=0, ten_to_nineteen=0, total_addn_99=0, total=0;
    while(1){
      if(fscanf(fi,"%d",&db[i].number) == EOF){
         db[i].number = -1;
         break;
      }
      fscanf(fi,"%s",db[i].spelling);
      db[i].length = strlen(db[i].spelling);
      i++;
    }
    for(j=0; j < i; j++){
       fprintf(fo,"%d %s %d\n",db[j].number, db[j].spelling, db[j].length);
    }
    for(j=0; j < i; j++){
       if(db[j].number < 10){
          one_to_nine_addn += db[j].length;
       }
       else if(db[j].number < 20){
          ten_to_nineteen += db[j].length;
       }
       if(((db[j].number % 10) == 0) && (db[j].number != 10) && (db[j].number < 100)){
          total_addn_99 += (db[j].length*10);
       }
    }
    total_addn_99 += ((one_to_nine_addn * 9) + ten_to_nineteen);
    total += total_addn_99; //first 99 nos
    total += (3*99*9); //number of and's
    total += (900*7); //900 hundred's
    total += (9*total_addn_99); //additional occurences of 1 to 99
    for(j=0; j < i; j++){
        if(db[j].number < 10){
             total += (100*db[j].length); //occurence of 1,2 ,3.. each hundred times till 1000 after 1-99
        }
    }
    total += 11; //1000
    fprintf(fo,"\n Total length of digits from 1 to 1000 = %d",total);
    fclose(fi);
    fclose(fo);
    return 0;
}
