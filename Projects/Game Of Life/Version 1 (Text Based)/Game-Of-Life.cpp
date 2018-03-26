#include <iostream>
#include <ctime>    // for time(0)
#include <chrono>   // std::chrono::nanoseconds(#), ::seconds(#)
#include <thread>   // std::this_thread::sleep_for, ::sleep_until
#define WIDTH 20
#define HEIGHT 20

void generate_board(char board[HEIGHT][WIDTH]);
void print_board(char board[HEIGHT][WIDTH]);
int get_neighbouring_live_cells(char board[HEIGHT][WIDTH], int *x, int *y);
bool will_cell_live(char board[HEIGHT][WIDTH], int *x, int *y);
// void update_cell_state(char board[HEIGHT][WIDTH]);
void clr_scr();

int main(int argc, char *argv[])
{
  // Initializing game grid
  char board[HEIGHT][WIDTH];

  // Amount of time to wait every generation
  int time_between_generations = 1;

  // Generating random live cells in the grid
  generate_board(board);

  // 100 generations
  for (int i = 1; i <= 100; i++)
  {
    clr_scr();
    // Printing the grid cause why not
    print_board(board);

    // This is the prototype for the function "will_cell_live"
    for (int y=0; y<HEIGHT; y++)
    {
      for (int x=0; x<WIDTH; x++)
      {
        // Sets cell either to alive or dead depending on it's neighbours
        if (will_cell_live(board, &x, &y))
        {
          board[y][x] = 'O';
        } else
        {
          board[y][x] = ' ';
        }
      }
    }

    std::cout << "Generation: " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(time_between_generations));
  }

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

int get_neighbouring_live_cells(char board[HEIGHT][WIDTH], int *x, int *y)
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

bool will_cell_live(char board[HEIGHT][WIDTH], int *x, int *y)
{
  int neighbouring_live_cells = get_neighbouring_live_cells(board, x, y);
  bool is_alive = (board[*y][*x]=='O') ? true : false;

  if (is_alive)
  {
    // neighbouring_live_cells [0, 2[
    if (neighbouring_live_cells >= 0 &&
    neighbouring_live_cells < 2) { return false; }
    // neighbouring_live_cells [4, 8]
    else if (neighbouring_live_cells >= 4 &&
    neighbouring_live_cells <= 8) { return false; }
    // neighbouring_live_cells [2, 3]
    else if (neighbouring_live_cells >= 2 &&
    neighbouring_live_cells <= 3) { return true; }
  } else { // At this point you know the cell is dead
    if (neighbouring_live_cells == 3) return true;
  }
  return false; // This shouldn't execute
}

void clr_scr()
{
  // "this is a special keyword that translates as clearing of screen.. "
  // https://stackoverflow.com/questions/17335816/clear-screen-using-c#32008479
  std::cout << "\033[2J\033[1;1H";
}
