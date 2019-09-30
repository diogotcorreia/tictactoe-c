// C-based Tic-Tac-Toe game by Diogo Correia and João Joaquim

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define constants
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Function declaration
void clear_screen();
void rules_instructions();
void start_board();
void print_board();
void start_game();
void execute_play();
char verify_winner();
bool is_tie();
void game_end(char winner);

// Board array and starting function
char matrix[3][3];

// This boolean defines which player is playing.
// False means Player 1 (X)
// True means Player 2 (O)
bool turn = false;

// The winner of the game.
char winner = ' ';

// The main function. This is what handles the game start.
int main()
{
  clear_screen();
  rules_instructions();
  start_board();
  start_game();
  return 0;
}

// Prints the instructions to the console.
void rules_instructions()
{
  printf("\n Welcome to this C-based Tic-Tac-Toe game by Diogo Correia and João Joaquim!\n");
  printf("\n In order to win the game, you must have three of your characters aligned, either vertically, horizontally or diagonally.\n");
  printf("\n Player 1 plays with 'X' and Player 2 with 'O'.");
  printf("\n To select a square, type the number of the square.\n");
  printf("\n Press CTRL + C at any time to exit.\n");
  printf("\n Good luck! \n\n\n");
}

// Initializes an empty board.
void start_board()
{
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      matrix[i][j] = ' ';
}

// Prints the current board to the console.
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
    if (k != 2)
    {
      printf("\n---|---|---\n");
    }
  }
  printf("\n\n");
}

// Cleans the screen.
void clear_screen()
{
  system("@cls||clear");
}

// Handles the game logic.
void start_game()
{
  char winner = ' ';
  // Keep the game running while no one wins and there is no tie.
  do
  {
    print_board();
    execute_play();
    clear_screen();
    winner = verify_winner();
    printf("Winner: %c\n", winner);
  } while (winner == ' ' && !is_tie());
  print_board();
  game_end(winner);
}

// Executes a round on the game.
void execute_play()
{
  int square;
  printf("Player %d (%c) turn: ", turn ? 2 : 1, turn ? 'O' : 'X');
  scanf("%d", &square);
  int row, column;
  row = floor((square - 1) / 3);
  column = (square - 1) % 3;
  if (matrix[row][column] != ' ')
  {
    printf("Invalid play! That square has already been taken!\n");
    execute_play();
    return;
  }
  matrix[row][column] = turn ? 'O' : 'X';
  turn = !turn;
}

// Checks if there is a winner. Does not check ties.
char verify_winner()
{
  int possibilities[8][3] = {
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
      {0, 3, 6},
      {1, 4, 7},
      {2, 5, 8},
      {0, 4, 8},
      {2, 4, 6},
  };
  int i;
  for (i = 0; i < 8; i++)
  {
  }
  //Verify rows

  if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2])
  {
    return matrix[0][0];
  }

  if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2])
  {
    return matrix[1][0];
  }

  if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2])
  {
    return matrix[2][0];
  }

  //Verify columns

  if (matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0])
  {
    return matrix[0][0];
  }

  if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1])
  {
    return matrix[0][1];
  }

  if (matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2])
  {
    return matrix[0][2];
  }

  //Verify diagonals

  if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
  {
    return matrix[0][0];
  }

  if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
  {
    return matrix[0][2];
  }
  return ' ';
}

// Checks if there is a tie.
bool is_tie()
{
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      if (matrix[i][j] == ' ')
        return false;
  return true;
}

// Ends the game.
void game_end(char winner)
{
  switch (winner)
  {
  case 'X':
    printf("\nPlayer 1 won!\n");
    break;
  case 'O':
    printf("\nPlayer 2 won!\n");
    break;
  default:
    printf("\nIt's a tie!\n");
  }
}
