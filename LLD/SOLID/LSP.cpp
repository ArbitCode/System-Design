#include <iostream>

/*
  Liskov Substitution: if does not voilet then Inheritance is valid.
  Liskov Substitution voilates since oject of ContractEmployee does not satisfy getBonus.
*/
class Bonus
{
  public:
    virtual int getBonus() = 0;
};

class Employee
{
public:
  virtual int getSalary() = 0;
};

class EmployeeFullTime : public Employee, public Bonus
{
  int bonus = 10;
  int salary = 1000;

public:
  int getBonus() { return bonus; }
  int getSalary() { return salary; }
};

class ContractEmployee : public Employee
{
  int salary = 100;
  public:
    int getSalary() { return salary; }
};

int main()
{

  ContractEmployee *cemp = new ContractEmployee();
  EmployeeFullTime *emp = new EmployeeFullTime();
  try
  {
    std::cout << "Emp Salary: " << emp->getSalary() << std::endl;
    std::cout << "Emp Bonus: " << emp->getBonus() << std::endl;
    std::cout << "cemp Salary: " << cemp->getSalary() << std::endl;
    //std::cout << "cemp Bonus: " << cemp->getBonus() << std::endl;
  }
  catch (std::exception &ex)
  {
    std::cout << "Exception: " << ex.what() << std::endl;
  }
  delete emp;
  delete cemp;
}
