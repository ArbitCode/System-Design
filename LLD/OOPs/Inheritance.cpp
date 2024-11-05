#include <iostream>

// Inheritance.
/*
1. single inheritance
2. multiple inheritance
3. multilevel inheritance
4. hirarichal inheritance
5. hybrid inheritance
*/

// single Inheritance

class A
{
  public:
    A() { std::cout << "A class Base Class." << std::endl; }
    virtual void info() { std::cout << "A Class info: Base class." << std::endl; }
};

class B
{
public:
  B() { std::cout << "B class Base Class." << std::endl; }
  virtual void info() { std::cout << "B Class info: Base class." << std::endl; }
};

class C : public A
{
  public:
  C() { std::cout << "C Class Derived class from A." << std::endl; }
  void info() { std::cout << "C Class info: Derived class from A" << std::endl; }
};

// multiple inheritance

class D : public A, public B
{
  public:
  D() { std::cout << "D Class Derived class from A and B." << std::endl; }
  void info() { std::cout << "D Class info: Derived class from A and B" << std::endl; }
};

// multilevel inheritance
class E : public C
{
public:
  E() { std::cout << "E class derived from C which derived from A." << std::endl; }
  void info() { std::cout << "E Class info: Heirarchical Inheritance." << std::endl; }
};

//heirarchical class


void tester()
{
  //A *a = new C();
  //a->info();
  A *b = new E();
  b->info();
}
int main()
{
  tester();
}
