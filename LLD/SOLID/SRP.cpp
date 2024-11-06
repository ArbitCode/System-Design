#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* it can be desiged poorly if we compare book's attribute in book class. or print book into caltalogue class.
  solution: class attribute is responsible for delegates, SRP for attributes.*/

class Attributes
{
public:
  Attributes(const std::string &name, const std::string &author_fname, const std::string &author_lname)
      : title(name), author_fname(author_fname), author_lname(author_lname) {}

  std::string getTitle() const { return title; }
  std::string getAuthorFName() const { return author_fname; }
  std::string getAuthorLName() const { return author_lname; }

  bool isEqual(const Attributes &attrs) const
  {
    // Case-insensitive comparison lambda
    auto compare = [](char ch1, char ch2)
    {
      return std::tolower(static_cast<unsigned char>(ch1)) == std::tolower(static_cast<unsigned char>(ch2));
    };

    // Compare title
    if (!std::equal(title.begin(), title.end(), attrs.title.begin(), attrs.title.end(), compare))
      return false;

    // Compare author first name
    if (!std::equal(author_fname.begin(), author_fname.end(), attrs.author_fname.begin(), attrs.author_fname.end(), compare))
      return false;

    // Compare author last name
    if (!std::equal(author_lname.begin(), author_lname.end(), attrs.author_lname.begin(), attrs.author_lname.end(), compare))
      return false;

    return true;
  }
  friend std::ostream& operator<<(std::ostream& ostr, const Attributes& attrs)
  {
    ostr << "{";
    ostr << "'Title': " << attrs.title;
    ostr << ", 'Author Name': " << attrs.author_fname;
   if(!attrs.author_fname.empty())
     ostr << " ";
   ostr << attrs.author_lname;
   ostr << "}" << std::endl;
   return ostr;
  }

private:
  std::string title;
  std::string author_fname;
  std::string author_lname;
};

class Book
{
public:
  Book(Attributes *book_attrs) : attrs(book_attrs) {}
  ~Book() { delete attrs; }
  Attributes *getAttribute() const { return attrs; }

private:
  Attributes *attrs;
};

class Catalogue
{
public:
  void add(Book *book)
  {
    if (book)
      book_list.emplace_back(book);
  }

  std::vector<Book *> find(const Book *targetBook) const
  {
    std::vector<Book *> matches;
    for (const auto book : book_list)
    {
      if (book->getAttribute()->isEqual(*targetBook->getAttribute()))
      {
        matches.emplace_back(book);
      }
    }
    return matches;
  }

private:
  std::vector<Book *> book_list;
};



// TESTER
void fill(Catalogue *bookself)
{
  bookself->add(new Book(new Attributes("CPP", "Jonkins", "Whopins")));
  bookself->add(new Book(new Attributes("cpp", "", "Whopins")));
}

void test(Catalogue *bookself)
{
  Book *searchBook = new Book(new Attributes("CPP", "", "whopins"));
  std::vector<Book *> match = bookself->find(searchBook);
  delete searchBook;
  std::cout << "Matches: " << std::endl;
  for (auto book : match)
  {
    std::cout << *book->getAttribute();
  }
}

int main()
{
  Catalogue *bookself = new Catalogue();
  fill(bookself);
  test(bookself);
  delete bookself;
}
