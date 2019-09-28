//C-based Tic-Tac-Toe game by Diogo Correia and João Joaquim

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <conio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

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
  int k, l;
  for (k = 0; k < 3; k++)
  {
    for (l = 0; l < 3; l++)
    {
      switch (matrix[k][l])
      {
      case 'X':
        printf(" " ANSI_COLOR_RED "%c" ANSI_COLOR_RESET " ", matrix[k][l]);
        break;
      case 'O':
        printf(" " ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET " ", matrix[k][l]);
        break;
      default:
        printf(" " ANSI_COLOR_YELLOW "%d" ANSI_COLOR_RESET " ", k * 3 + l + 1);
      }
      if (l != 2)
      {
        printf("|");
      }
    }
    //printf(" " ANSI_COLOR_RED "%c" ANSI_COLOR_RESET " | %c | %c ", matrix[k][0], matrix[k][1], matrix[k][2]);
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

/**
 * Handles all the game logic.
 * */
void start_game()
{
}
