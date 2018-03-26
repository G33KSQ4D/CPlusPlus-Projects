#include <iostream>
#include <ctime>
#define WIDTH 10
#define HEIGHT 10

int main(int argc, char *argv[])
{
  char board[HEIGHT][WIDTH];

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

  for (int y=0; y<HEIGHT; y++)
  {
    for (int x=0; x<WIDTH; x++)
    {
      std::cout << board[y][x] << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}
