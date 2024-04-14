#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "listP.h"


bool isInteger(char number[]);
int fileExist(char* filename);
int correctNumberOfLines(char* filename, int count);


int main(int argc, char *argv[]) {
   if(!fileExist(argv[2])){
      printf("CardFile not readable or doesn't exist");
      exit(3);
   }
   if(!isInteger(argv[1])){
      printf("Invalid seed (first command line argument is not an integer)");
      exit(2);
   }
   if(argc<3){
      printf("Wrong number of command-line arguments (not 2)");
      exit(1);
   }
   else if(argc>3){
      printf("Wrong number of command-line arguments (not 2)");
      exit(1);
   }
   else{
      correctNumberOfLines(argv[2],2);
      printf("Two arguments have been passed");
   }

}

/*
void inputFile(){

}

*/

bool isInteger(char number[]){
   int x = 0;

   for (;number[x] != 0; x++)
   {
      if (!isdigit(number[x]))
         return false;
   }
   return true;
}

int fileExist(char* filename)
{
    FILE *file;
    
    if (file = fopen(filename, "r")) 
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int correctNumberOfLines(char* filename, int count)
{
   FILE *file;

   file = fopen(filename, "r");
   char line[20];
   int count1 = 0;

   while(!feof(file)){
      fgets(line,20,file);
      count1++;
   }

   if (count == count1)
   {
      printf("File has correct lines");
   }
   else{
      printf("Card Bad Format (Wrong number of lines)");
      exit(4);
   }
}

void getArrayFromFile(char* filename)
{
   FILE *file;

   file = fopen(filename, "r");

   int row = 0;
   int col = 0;
   int card[row][col];
   char *line;
   char *num;

   while (!feof(file))
   {
      fscanf(file,"%s",line);
      num = strtok(line, " ");
      while (num != NULL)
      {
         card[row][col] = atoi(num);
         col++;
         num = strtok(line, " ");
      }
      printf("\n");
      row++;
   }
   
   for (int i = 0; i<row; i++)
    {
        for (int j = 0; j<col; j++){
            card[i][j] = 0;
            printf("%d ",card[i][j]);
        }
        printf("\n");
    }
   return 0;
}


