#include <iostream>
#include <math.h>
#include <iomanip>

/*
  here Shape class is closed to modification but sub class is open to extend.
 */

class Shape
{
public:
  virtual float getArea() const = 0;
  virtual ~Shape() = default;
};

class Circle: public Shape
{
  public:
    Circle(float radius) : radius(radius){}
    float getArea() const { return M_PI * radius * radius; }


  private:
    float radius;
    float area;
};

class Rectangle : public Shape
{
  public:
    Rectangle(float length, float width) : length(length), width(width) {}
    float getArea() const { return length * width; }

  private:
    float length;
    float width;
};

class Triangle : public Shape
{
  public:
    Triangle(float a, float b, float c): a(a), b(b), c(c){}
    float getArea() const { float s = (a + b + c) / 2.0;
      return sqrt(s*(s - a)*(s - b)*(s - c));
    }

  private:
    float a;
    float b;
    float c;
};

int main()
{
  Shape *cr = new Circle(12.0);
  Shape *rect = new Rectangle(12.0, 12.0);
  Shape *triangle = new Triangle(3.0, 2.0, 3.0);
  std::cout << "Circle Area: " << cr->getArea() << std::endl;
  std::cout << "Rectangle Area: " << rect->getArea() << std::endl;
  std::cout << "Triangle Area: " << triangle->getArea() << std::endl;

  delete cr;
}
