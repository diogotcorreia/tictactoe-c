//C-based Tic-Tac-Toe game by Diogo Correia and João Joaquim

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//#include <conio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Variable declaration

void clear_screen();
void rules_instructions();
void start_board();
void print_board();
void start_game();
void execute_play();
char verify_winner();
void game_end();

//Board array and starting function

char matrix[3][3];

// This boolean defines which player is playing.
// False means Player 1 (X)
// True means Player 2 (O)

bool turn = false;

//Winner

char winner = ' ';

//Main

int main() {
  clear_screen();
  rules_instructions();
  start_board();
  start_game();
  return 0;
}

//Instruction printing function

void rules_instructions() {
  printf("\n Welcome to this C-based Tic-Tac-Toe game by Diogo Correia and Joao Joaquim!\n");
  printf("\n In order to win the game, you must have three of your characters aligned, either vertically, horizontally or diagonally.\n");
  printf("\n Player 1 plays with 'X' and Player 2 with 'O'.\n");
  printf("\n Press CTRL + C at any time to exit.\n");
  printf("\n Good luck! \n\n\n");
}

//Board starting function

void start_board() {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      matrix[i][j] = ' ';
    }
  }
}

//Board printing function

void print_board() {
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
  printf("\n\n");
}

//Screen clearing function

void clear_screen()
{
  system("@cls||clear");
}

//Game logic handling functions
 
void start_game()
{
  // TODO while no one has won or it's a tie, repeat
  do {
    verify_winner();
    winner = verify_winner();
    if (winner != ' ') {
      break;    
    }
    print_board();
    execute_play();
    clear_screen();
  } while (winner == ' ');
    if (winner != ' ') {
    print_board();  
    game_end();
  }
}

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

//Winner checking function

char verify_winner() {

  //Verify rows

  if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]) {        
    return matrix[0][0];  
  } 

  if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]) {
    return matrix[1][0];
  }    

  if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]) {
    return matrix[2][0];
  } 

  //Verify columns
  
  if (matrix[0][0] == matrix [1][0] && matrix[0][0] == matrix[2][0]) {       
    return matrix[0][0];
  }
     
  if (matrix[0][1] == matrix [1][1] && matrix[0][1] == matrix[2][1]) {       
    return matrix[0][1];
  }

  if (matrix[0][2] == matrix [1][2] && matrix[0][2] == matrix[2][2]) {       
    return matrix[0][2];
  }

  //Verify diagonals
  
    if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) {      
      return matrix[0][0]; 
    }
    
    if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) {    
      return matrix[0][2];  
    }
}

//Game ending function

void game_end() {
  winner = verify_winner();
  if (winner == 'X') {
    printf("\nPlayer 1 won!\n");
  }  
  if (winner == 'O') {
    printf("\nPlayer 2 won!\n");
  } 
}

