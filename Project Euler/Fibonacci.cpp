// March 20th, 2018

// Prints the fibonacci sequence;
// To fix: Don't supply (10, 1, 1); THe ones in teh arguments

#include <iostream>
#include <vector>

// Make the function return a vector
int fib (int recur, int a, int b)
{
    if (recur >= 1)
    {
        // std::cout << a << ", ";
        return a + (recur -= 1, b, a + b);
    }
}

int main()
{
    std::vector<int> fib_sequence { 1, 1 };
    fib_sequence.push_back(fib(10, 1, 1));

    return 0;
}
