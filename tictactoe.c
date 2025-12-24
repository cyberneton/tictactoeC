/*
 make table tictactoe in this file

    |   |
 ---+---+---
    |   |
 ---+---+---
    |   |

 */

#include <stdio.h>

int row, column; //  variables to store user input

// 2D array to store the status of the game board
// {0} means set all members of the array to 0
int board[3][3] = {0};

// for main function can know this function
void start_game(int *row, int *corum);

int main()
{
   // make table tictactoe
   for (int i = 0; i < 3; i++)
   {
      printf("  %-2s| %-2s| %-2s\n", "G", "A", "Y");
      if (i < 2)
      {
         printf(" ---+---+--- \n");
      }
   }

   // send adress of row and column to function
   start_game(&row, &column);

   return 0;
}

// this function to start the game
void start_game(int *row, int *column)
{
   // ask user where to start
   printf("\n Where do you want to start? (row column): ");
   scanf("%d %d", &row, &column);

   // for testing purpose, print out the user input
   printf("you chose row %d and column %d\n", row, column);

   // write user input to array 
   
};
