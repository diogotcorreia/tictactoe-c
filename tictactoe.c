#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare all variables

/**
 * Stores all the board information
 * 0 means empty
 * 1 means player 1 (X)
 * 2 means player 2 (O)
 * 
 * board[0][1] indicates the value of the first row and second column
*/
int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

// Declare all methods

void start_game();

void print_board();

void clear_screen();

int main()
{
  start_game();
  return 0;
}

void start_game()
{
  print_board();
}

void print_board()
{
  //clear_screen();
  // Loop through board
  int i, j;

  /* output each array element's value */
  for (i = 0; i < 3; i++)
  {

    for (j = 0; j < 3; j++)
    {
      int gridItem = board[i][j];
      char out = gridItem == 0 ? 'e' : gridItem == 1 ? 'X' : 'O';
      printf("%c", out);
    }
    printf("\n\u0196\n");
  }
}

void clear_screen()
{
  system("@cls||clear");
}