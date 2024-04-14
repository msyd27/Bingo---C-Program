#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/*
void inputFile(){

}

*/
int arr[5][5] = {};

bool isInteger(char number[])
{
   int x = 0;

   for (; number[x] != 0; x++)
   {
      if (!isdigit(number[x]))
         return false;
   }
   return true;
}

int fileExist(char *filename)
{
   FILE *file;

   if (file = fopen(filename, "r"))
   {
      fclose(file);
      return 1;
   }
   return 0;
}

int findDuplicates(int array[], char *filename)
{
   for (int i = 0; i < 25; i++)
   {
      for (int j = i + 1; j < 25; j++)
      {
         if (array[i] == array[j])
         {
            printf("\n%s has bad format(dup)", filename);
            exit(4);
         }
      }
   }

   return 0;
}

int numberOfLines(char *filename, int count)
{
   FILE *file;

   file = fopen(filename, "r");
   char line[20];
   int count1 = 0;
   /*
   while (!feof(file))
   {
      fgets(line, 20, file);
      count1++;
   }
   */
   if (count != count1)
   {
      printf("%s has bad formatl", filename);
      exit(4);
   }
}

int printArrayFromFile(char *filename)
{
   FILE *file;

   file = fopen(filename, "r");
   int const row = 5;
   int const col = 5;
   int card1[25];
   char singleline[100];

   char *num;

   int h, w;
   h = 0;
   while (!feof(file))
   {
      w = 0;
      fgets(singleline, 100, file);
      num = strtok(singleline, " ");
      while (num != NULL)
      {
         //printf("%s\n", num);
         arr[h][w] = atoi(num);
         w++;
         num = strtok(NULL, " ");
      }
      h++;
   }

   int k;
   k = 0;
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         card1[k] = arr[i][j];
         k++;
         if (arr[2][2] != 00)
         {
            printf("%s has bad format1", filename);
            exit(4);
         }
         if (((arr[i][0] > 15) != 0) && ((arr[i][0] > 1) != 0))
         {
            printf("%s has bad format1", filename);
            exit(4);
         }
         if (((arr[i][1] > 30) != 0) && ((arr[i][1] > 16) != 0))
         {
            printf("%s has bad format16", filename);
            exit(4);
         }
         if (((arr[i][2] > 45) != 0) && ((arr[i][2] > 31) != 0))
         {
            printf("%s has bad format16", filename);
            exit(4);
         }
         if (((arr[i][3] > 60) != 0) && ((arr[i][3] > 46) != 0))
         {
            printf("%s has bad format16", filename);
            exit(4);
         }
         if (((arr[i][4] > 75) != 0) && ((arr[i][4] > 61) != 0))
         {
            printf("%s has bad format(up)", filename);
            exit(4);
         }

         else
         {
            printf("%d ", arr[i][j]);
         }
      }
      printf("\n");
   }
   findDuplicates(card1,filename);
   printf("\n");
   printf("\n");

   for (int i = 0; i < 25; i++)
      printf("%d ", card1[i]);
   return 0;
}

int numberCount(char *filename)
{
   FILE *file;

   file = fopen(filename, "r");

   char ch;
   int wordCount = 0;

   while ((ch = fgetc(file)) != EOF)
   {
      if (ch != ' ' && ch != '\n')
         wordCount++;
   }
   printf("%d\n", wordCount);
   if (wordCount != 50)
   {
      printf("%d\n", wordCount);
      printf("%s has bad formatw", filename);
      exit(4);
   }
}

int main(int argc, char *argv[])
{

   if (!fileExist(argv[2]))
   {
      printf("CardFile not readable or doesn't exist");
      exit(3);
   }
   if (!isInteger(argv[1]))
   {
      printf("Invalid seed (first command line argument is not an integer)");
      exit(2);
   }
   if (argc < 3)
   {
      printf("Wrong number of command-line arguments (not 2)");
      exit(1);
   }
   else if (argc > 3)
   {
      printf("Wrong number of command-line arguments (not 2)");
      exit(1);
   }
   else
   {
      //numberOfLines(argv[2], 6);
      numberCount(argv[2]);
      printArrayFromFile(argv[2]);
      printf("\nTwo arguments have been passed");
   }
}