// Create March 25th, 2018

// Todo change library being from a vector to something else
// Maybe linked list so I can delete from anywhere. I don't know..
// Gonna go play minecraft

#include <iostream>
#include <vector>
#include "Book.h"

void print_books_in_library(std::vector<Book> books_in_library);
void add_book_to_library(std::vector<Book> *books_in_library);
void remove_book_from_library(std::vector<Book> *books_in_library);
void clr_scr();

int main(int argc, char *arv[])
{
  char user_input;
  bool exited_library = false;

  // Creating books so the library isn't empty
  Book red_pyramid("The Red Pyramid");
  Book perc_jackson("Percy Jackson and The Lighting Thief");
  Book how_the_world_started("How The World Started");

  // Addings books to the "library"
  std::vector<Book> books_in_library {
    {
      red_pyramid,
      perc_jackson,
      how_the_world_started
    }
  };

  std::cout << "Welcome to a library management system!\n" << std::endl;

  while ( !exited_library )
  {
    clr_scr();
    std::cout << \
"\tMain Menu            \n \
----------------------- \n \
1. View books           \n \
2. Add a book           \n \
3. Remove a book        \n \
4. Leave library        \n \
----------------------- \n \
Option: ";
    std::cin >> user_input;

    switch( user_input )
    {
      case '1':
        print_books_in_library(books_in_library);
        break;
      case '2':
        add_book_to_library(&books_in_library);
        break;
      case '3':
        remove_book_from_library(&books_in_library);
        break;
      case '4':
        exited_library = true;
        break;
    }
  }

  std::cout << "\nCome again!" << std::endl;

  return 0;
}

void print_books_in_library(std::vector<Book> books_in_library)
{
  clr_scr();

  std::vector<Book>::iterator p_book;
  int                         book_number = 1; // Makes removing easier
  std::string                 pause_program;

  std::cout << "The current books in the library are: " << std::endl;

  // Using iterators from STL to print books
  for (p_book = books_in_library.begin();
       p_book != books_in_library.end(); p_book++)
  {
    std::cout << "Book " << book_number << ": " << p_book->get_book_title() << std::endl;
    book_number++;
  }

  // "Pauses" the program so user can see the books
  // This is a temporary fix I don't know what to do
  std::cout << "\nPlease write something and press enter to continue..." << std::endl;
  std::cin >> pause_program;
}

// Pass vector as reference so it does not create a copy of it and it can be modified directly
void add_book_to_library(std::vector<Book> *books_in_library)
{
  std::string book_name;

  std::cout << "Enter the name of the book: ";
  std::cin >> book_name;

  Book new_book(book_name);

  books_in_library->push_back(new_book);

  std::cout << "Book created!" << std::endl;
}

void remove_book_from_library(std::vector<Book> *books_in_library)
{

}

void clr_scr()
{
  // "this is a special keyword that translates as clearing of screen.. "
  // https://stackoverflow.com/questions/17335816/clear-screen-using-c#32008479
  std::cout << "\033[2J\033[1;1H";
}
