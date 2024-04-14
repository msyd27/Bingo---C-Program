#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "listp.h"


// Initialize 2-D Array to use for getting CardFile integers
int card[5][5] = {};
char mark[5][5] = {};

int callList[75];


// Function to generate random number based on seed --------------------------
int number_generator(char *arg1){
  int seed = *arg1 - '0';
  srand(seed);
  int count = 0;
  for(int i=0;i<count;i++){
    int random_number = rand();
    printf("%d\n", random_number);
    count++;
  }
  return 0;
}

// helper function that checks if it is an integer, used for invalid seed error
bool isInteger(char number[]){
   int x = 0;

   for (;number[x] != 0; x++)
   {
      if (!isdigit(number[x]))
         return false;
   }
   return true;
}

// Function to check if file exist for exit 3
int fileExist(char *filename)
{
   FILE *file;

   if (file = fopen(filename, "r"))
   {
      return 1;
   }
   return 0;
}

// Function to print what's on the card ---------------------------------------
int file_content_printer(char *filename){
  FILE *fp;

  fp = fopen(filename, "r");
  if (fp == NULL){
    printf("file does not exist/cannot open file\n");
    exit(0);
  }

  char c;

  c = fgetc(fp);
  while(c != EOF){
    printf("%c", c);
    c = getc(fp);
  }

  fclose(fp);
  return 0;
}
// Function that counts the characters of the file to check the format, used in exit 4
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
   if (wordCount != 50)
   {
      printf("%s has bad format", filename);
      exit(4);
   }
   return 0;
}

// Function to check for duplicates in an array
int findDuplicates(int array[], char *filename)
{
   // For loop goes through each element in the entire card(length = 25) array
   for (int i = 0; i < 25; i++)
   {
      for (int j = i + 1; j < 25; j++)
      {
         if (array[i] == array[j])
         {
            printf("\n%s has bad format", filename);
            exit(4);
         }
      }
   }

   return 0;
}

// Function that gets the content of CardFile and puts it into an 2-D array
int printArrayFromFile(char *filename)
{
   FILE *file;

   file = fopen(filename, "r");
   //Initializing Variables
   int const row = 5;
   int const col = 5;
   // A single Array Variable was made that was used to find duplicates (see findDuplicates())
   int card1[25];
   char singleline[100];

   char *num;
   
   // Variables used to put elements into Array
   int x, y;
   x = 0;
   // while loop for the file
   while (!feof(file))
   {
      y = 0;
      // after getting a line, strtok() is used to break the string at every integer
      fgets(singleline, 100, file);
      num = strtok(singleline, " ");
      // while loop to add each integer to the 2-D Array
      while (num != NULL)
      {
         // atoi() is used to convert the string to int value for 2-D Array
         card[x][y] = atoi(num);
         y++;
         num = strtok(NULL, " ");
      }
      x++;
   }


   // initialize counter/index that will put the 2-D elements into a 1-D Array
   int k;
   k = 0;
   // For loop that will check for bad formats and print the 2-D Array
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         // Put 2-D Array elements into 1-D array,(used for duplicates)
         card1[k] = card[i][j];
         k++;
         // Check that the middle number is 00
         if (card[2][2] != 00)
         {
            printf("%s has bad format", filename);
            exit(4);
         }
         // Check is the column 1 contains 5 unique integers in [01-15]
         if (((card[i][0] > 15) != 0) && ((card[i][0] > 1) != 0))
         {
            printf("%s has bad format", filename);
            exit(4);
         }
         // Check is the column 2 contains 5 unique integers in [16-30]
         if (((card[i][1] > 30) != 0) && ((card[i][1] > 16) != 0))
         {
            printf("%s has bad format", filename);
            exit(4);
         }
         // Check is the column 3 contains 5 unique integers in [31-45]
         if (((card[i][2] > 45) != 0) && ((card[i][2] > 31) != 0))
         {
            printf("%s has bad format", filename);
            exit(4);
         }
         // Check is the column 4 contains 5 unique integers in [46-60]
         if (((card[i][3] > 60) != 0) && ((card[i][3] > 46) != 0))
         {
            printf("%s has bad format", filename);
            exit(4);
         }
         // Check is the column 5 contains 5 unique integers in [61-75]
         if (((card[i][4] > 75) != 0) && ((card[i][4] > 61) != 0))
         {
            printf("%s has bad format", filename);
            exit(4);
         }
         // Print the Array
         else
         {
            printf("%02d ", card[i][j]);
         }
      }
      printf("\n");
   }
   // Function findDuplicates() is called to make sure there are unique numbers
   findDuplicates(card1, filename);

   return 0;
}

// Function to mark the card but was not successful
int markCard()
{
   int zero = 0;
   for (int i = 0; i < (sizeof callList / sizeof callList[0]); i++)
   {
      for (int x = 0; x < 5; x++)
      {
         for (int y = 0; y < 5; y++)
         {
            if (callList[i] == card[x][y])
            {
               mark[x][y] = 'm';
            }
            // Mark the zero in the middle
            else if (zero == card[x][y])
            {
               mark[x][y] = 'm';
            }
            else
            {
               mark[x][y] = ' ';
            }
         }
      }
   }
}

// Function that updates the array and prints it.
int updateArray(int array[][5])
{
   // Nested For loop to go through each element in the 2-D Array
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         // Print marked element
         if (mark[i][j] = 'm')
         {
            printf("%02dm ", card[i][j]);
         }
         // If it is unmakred print the element
         else
         {
            printf("%02d  ", card[i][j]);
         }
      }
      printf("\n");
   }
}

// Function that check if the Card is won
int getWinner()
{
   // Nested For loop for each element in 2-D Array
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         // Check if all 5 numbers in row are marked
         if ((mark[i][0] == 'm') && (mark[i][1] == 'm') && (mark[i][2] == 'm') && (mark[i][3] == 'm') && (mark[i][4] == 'm'))
         {
            printf("WINNER");
            exit(0);
         }
         // Check if all 5 numbers in col are marked
         if ((mark[0][j] == 'm') && (mark[1][j] == 'm') && (mark[2][j] == 'm') && (mark[3][j] == 'm') && (mark[4][j] == 'm'))
         {
            printf("WINNER");
            exit(0);
         }
         // Check if all 4 corners are marked
         if ((mark[0][0] == 'm') && (mark[0][4] == 'm') && (mark[4][0] == 'm') && (mark[4][4] == 'm'))
         {
            printf("WINNER");
            exit(0);
         }
      }
   }
   // If not, then game is lost.
   printf("GAME OVER");
   exit(0);
}

// main ----------------------------------------------------------------------
int main(int argc, char **argv)
{

   char *arg1 = argv[1];
   char *filename = argv[2];

   if (!fileExist(argv[2]))
   {
      printf("%s is nonexistent or unreadable\n", argv[2]);
      exit(3);
   }
   if (!isInteger(argv[1]))
   {
      printf("Expected Integer seed but got %s\n", argv[1]);
      exit(2);
   }
   if (argc < 3)
   {
      printf("Usage: A2 seed cardFile\n");
      exit(1);
   }
   else if (argc > 3)
   {
      printf("Usage: A2 seed cardFile\n");
      exit(1);
   }
   else
   {
      numberCount(argv[2]);

      printf("seed: %s, filename: %s\n", arg1, filename);
      number_generator(arg1);

      markCard();
      printf("L   I   N   U   X\n");
      printArrayFromFile(filename);
      printf("enter any non-enter key for Call (q to quit): ");

      char c;
      scanf("%c", &c);
      while (c != 'q')
      {
         system("cls");
         printf("CallList:\n\n");
         printf("L   I   N   U   X\n");
         updateArray(card);

         getWinner();
         printf("\n");
         printf("\nenter any non-enter key for Call (q to quit): ");
         scanf("%c", &c);
      }
   }
}


