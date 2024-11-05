#pragma once
#include <string>
#include <iostream>
#include "Attributes.h"

class Book{
  public:
    Book(Attributes* attr);
    ~Book();
    Attributes *get_attributes() const;
    bool is_equal(const Book* book);

  private:
    Attributes *attr;
};

inline std::ostream& operator<<(std::ostream& ostr, const Book& book)
{
  std::cout << book.get_attributes() << std::endl;
  return ostr;
}
