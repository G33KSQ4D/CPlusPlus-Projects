#include <iostream>
#include <ctime>
#define WIDTH 10
#define HEIGHT 10

void generate_board(char board[HEIGHT][WIDTH]);
void print_board(char board[HEIGHT][WIDTH]);
int get_neighbouring_live_cells(int *x, int *y, char board[HEIGHT][WIDTH]);

int main(int argc, char *argv[])
{
  // Initializing game grid
  char board[HEIGHT][WIDTH];

  // Generating random live cells in the grid
  generate_board(board);

  // Printing the grid cause why not
  print_board(board);

  int x = 0, y = 0;
  std::cout << get_neighbouring_live_cells(&x, &y, board) << std::endl;



  return 0;
}

void generate_board(char board[HEIGHT][WIDTH])
{
  srand(time(0));
  for (int y=0; y<HEIGHT; y++)
  {
    for (int x=0; x<WIDTH; x++)
    {
      // A neater way of doing if else - less clumpy
      // 25% chance of being 1
      // Interval [0-4[
      (rand()%4==1) ? board[y][x]='O' : board[y][x]=' ';
    }
  }
}

void print_board(char board[HEIGHT][WIDTH])
{
  for (int y=0; y<HEIGHT; y++)
  {
    for (int x=0; x<WIDTH; x++)
    {
      std::cout << board[y][x] << " ";
    }

    std::cout << std::endl;
  }
}

int get_neighbouring_live_cells(int *x, int *y, char board[HEIGHT][WIDTH])
{
  int neighbouring_live_cells = 0;

  try {
    if (board[*y][*x-1] == 'O') neighbouring_live_cells++; // Left
    if (board[*y][*x+1] == 'O') neighbouring_live_cells++; // Right
    if (board[*y-1][*x+1] == 'O') neighbouring_live_cells++; // Top
    if (board[*y+1][*x] == 'O') neighbouring_live_cells++; // Bottom

    if (board[*y-1][*x-1] == 'O') neighbouring_live_cells++; // Top Left
    if (board[*y-1][*x+1] == 'O') neighbouring_live_cells++; // Top Right
    if (board[*y+1][*x-1] == 'O') neighbouring_live_cells++; // Bottom Left
    if (board[*y+1][*x+1] == 'O') neighbouring_live_cells++; // Bottom Right
  } catch (...) {
    std::cout << "Damn" << std::endl;
  }

  return neighbouring_live_cells;
}

















