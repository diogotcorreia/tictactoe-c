//C-based Tic-Tac-Toe game by Diogo Correia and João Joaquim

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <conio.h>

// Functions declaration

void clear_screen();
void rules_instructions();
void start_board();
void print_board();

//Main

int main()
{
  clear_screen();
  rules_instructions();
  start_board();
  print_board();
  return 0;
}

// Declare all functions

//Instruction printing function

void rules_instructions()
{
  printf("\n Welcome to this C-based Tic-Tac-Toe game by Diogo Correia and Joao Joaquim!\n");
  printf("\n In order to win the game, you need to have three of your characters aligned, either vertically, horizontally or diagonally.\n");
  printf("\n Player 1 plays with 'X' and Player 2 with 'O'.\n");
  printf("\n Press CTRL+C at any time to exit.\n");
  printf("\n Good luck! \n\n\n");
}

//Board array and starting function

char matrix[3][3];

void start_board()
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      matrix[i][j] = ' ';
    }
  }
}

//Board printing function

void print_board()
{
  int k;
  for (k = 0; k < 3; k++)
  {
    printf(" %c | %c | %c ", matrix[k][0], matrix[k][1], matrix[k][2]);
    if (k != 2)
    {
      printf("\n---|---|---\n");
    }
  }
  printf("\n");
}

//Screen clearing function

void clear_screen()
{
  system("@cls||clear");
}
