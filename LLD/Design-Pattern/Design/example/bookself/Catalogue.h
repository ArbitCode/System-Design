#pragma once

#include "Book.h"
#include <vector>

class Catalogue{
  public:
    void add(Attributes *const attrs);
    std::vector<Book *> find(const Attributes& target_attrs) const;

  private:
    std::vector<Book *> bookList;
};
