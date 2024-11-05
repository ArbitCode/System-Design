#include "Book.h"

Book::Book(Attributes* attr)
:attr(attr){}
Book::~Book() { delete attr; }
Attributes *Book::get_attributes() const { return attr; }
bool Book::is_equal(const Book *book)
{
  if(book->attr->is_match(attr))
  {
    return true;
  }
  return false;
}
