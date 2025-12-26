#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

enum State : unsigned char {
    FREE = ' ',
    X    = 'X',
    O    = 'O',
};

 */

#include <stdio.h>
int row, column, i; //  variables to store user input

// 2D array to store the status of the game board
// {0} means set all members of the array to 0
// X = 1 , O = 2 , empty = 0
int board[3][3] = {0};

// for main function can know this function
void start_game(int *row, int *corum, int board[3][3]);
void generate_board(int board[3][3]);

int main()
{
   // make table tictactoe
   for (i = 0; i < 3; i++)
   {
      printf("  %-2s| %-2s| %-2s\n", "G", "A", "Y");
      if (i < 2)
      {
         printf(" ---+---+--- \n");
      }
   }

   // send adress of row and column to function
   start_game(&row, &column, board);

   // generate the board again
   generate_board(board);

   return 0;
}

// this function to start the game
void start_game(int *row, int *column, int board[3][3])
{
   // ask user where to start
   printf("\n Where do you want to start? (row column) (0,1,2): ");
   scanf("%d %d", row, column);

   // for testing purpose, print out the user input
   printf("you chose row %d and column %d\n", *row, *column);

   // write user input to array
   // X = 1 , O = 2 , empty = 0
   board[*row][*column] = 1; // assuming 1 represents a move by the player
}

// X = 1 , O = 2 , empty = 0
void generate_board(int board[3][3])
{
   char symbol[] = {' ', 'X', 'O'};

   for (i = 0; i < 3; i++)
   {
      printf("  %-2c| %-2c| %-2c\n",
             symbol[board[i][0]],
             symbol[board[i][1]],
             symbol[board[i][2]]);
      if (i < 2)
      {
         printf(" ---+---+--- \n");
      }
   }
}
