#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<boost/lexical_cast.hpp>

/* Sperate the concerns */

class Journal
{
  std::string title;
  std::vector<std::string> entries;

public:
  Journal(const std::string &name) : title(name){}
  std::vector<std::string> getEntries() const { return entries; }
  void add(const std::string &blogs) {
    static int count = 1;
    entries.emplace_back(boost::lexical_cast<std::string>(count++) + " : " + blogs);
  }
};

class PersistantManager
{
public:
  void save(const Journal &journal, const std::string &filename)
  {
    std::ofstream fstr(filename);
    for (auto blog : journal.getEntries())
    {
      fstr << blog << std::endl;
    }
  }
};

int main()
{
  Journal *j = new Journal("My Diaries");
  PersistantManager *pm = new PersistantManager();
  j->add("I eat bug.");
  j->add("I cries yesterday");
  pm->save(*j, "myFile.txt");
  delete j;
  delete pm;
  return 0;
}
