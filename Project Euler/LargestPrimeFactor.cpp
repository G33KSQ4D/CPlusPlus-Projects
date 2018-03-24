#include <iostream>
#include <cmath>

bool isPrime(int number);

int main(int argc, char *argv[])
{
    long long max_num = 1000000;
    long long largest_prime = 0;

    for (int i = max_num / 2; i > 0; i--)
    {
        if (isPrime(i))
        {
            largest_prime = i;
            break;
        }
    }

    std::cout << largest_prime << std::endl;
}

bool isPrime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0) return false;
    }
    return true;
}