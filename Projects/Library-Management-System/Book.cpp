#include "Book.h"

Book::Book(std::string n) : book_title(n) {}

std::string Book::get_book_title()
{
  return book_title;
}
