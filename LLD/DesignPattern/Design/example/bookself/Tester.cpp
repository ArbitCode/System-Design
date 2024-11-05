#include "Catalogue.h"

void fill(Catalogue *bookself)
{
  AttributeMap pair3 = {
      {KEY::KIND, KIND::FICTION},
      {KEY::TITLE, std::string("to kill a Mockingbird")},
      {KEY::LAST, std::string("Lee")},
      {KEY::FIRST, std::string("Harper")},
      {KEY::YEAR, 1960},
      {KEY::GENRE, GENRE::ADENTURE},
      {KEY::REGION, REGION::INDIA},
      {KEY::SUBJECT, SUBJECT::PAINTING}};
  bookself->add(new Attributes(new AttributeMap(pair3)));
}

void test(Catalogue *bookself)
{
  AttributeMap pair2 = {
      {KEY::KIND, KIND::FICTION},
      {KEY::SUBJECT, SUBJECT::PAINTING}};

  Book *book = new Book(new Attributes(new AttributeMap(pair2)));
  std::cout << "Find Book: " << *book << std::endl;
  std::vector<Book *> matches = bookself->find(*book->get_attributes());
  if(matches.size())
  {
    std::cout << "Matches:" << std::endl;
    for (auto book : matches)
    {
      std::cout << book->get_attributes() << std::endl;
    }
  }
  else
  {
    std::cout << "No Match" << std::endl;
  }
}

int main()
{
  Catalogue *bookself = new Catalogue();
  fill(bookself);
  test(bookself);
}
