#include <iostream>

/*
  Liskov Substitution: if does not voilet then Inheritance is valid.
  Liskov Substitution voilates since oject of ContractEmployee does not satisfy getBonus.
*/

class PoorDesign
{
  int salary = 100;
  int bonus = 0;

public:
  virtual int getSalary() { return salary; }
  virtual int getBonus() { return bonus; }
};

class Employee : public PoorDesign
{
};

class ContractEmployee : public PoorDesign
{
public:
  int getBonus() { throw std::invalid_argument("Bonus is not allowed!"); }
};

int main()
{
  PoorDesign *person = new ContractEmployee();
  try
  {
    std::cout << "Salary: " << person->getSalary() << std::endl;
    std::cout << "Bonus: " << person->getBonus() << std::endl;
  }
  catch(std::exception &ex)
  {
    std::cout << "Exception: " << ex.what() << std::endl;
  }
  delete person;
}
