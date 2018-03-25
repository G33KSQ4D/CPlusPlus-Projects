#include <string>

class Book
{
  std::string book_title;

public:
  Book(std::string n);
  std::string get_book_title();
};
