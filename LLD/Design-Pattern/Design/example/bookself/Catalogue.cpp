#include "Catalogue.h"
#include "Book.h"

void Catalogue::add(Attributes *const attrs)
{
  bookList.emplace_back(new Book(attrs));
}

std::vector<Book *> Catalogue::find(const Attributes& target_attrs) const
{
  std::vector<Book *> matches;
  for (auto book : bookList)
  {
    auto book_attrs = book->get_attributes();
    if (book_attrs->is_match(&target_attrs))
    {
      matches.emplace_back(book);
    }
  }
  return matches;
}
