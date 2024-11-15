#include <iostream>
#include <limits>
#include "include/DesktopBuilder.h"
#include "include/Manufacturer.h"
#include "include/DellBuilder.h"
#include "include/HpBuilder.h"
#include "include/LenovoBuilder.h"

enum class CHOICE
{
  WRONG,
  DELL,
  HP,
  LENOVO,
  EXIT,
  INVALID
};

DesktopBuilder* getBuilder(CHOICE ch)
{
  DesktopBuilder *builder = nullptr;
  switch (ch)
  {
  case CHOICE::DELL:
    std::cout << "Building Dell:  " << std::endl;
    builder = new DellBuilder();
    break;
  case CHOICE::HP:
    std::cout << "Building HP:  " << std::endl;
    builder = new HPBuilder();
    break;
  case CHOICE::LENOVO:
    std::cout << "Building Lenavo:  " << std::endl;
    builder = new LenovoBuilder();
  case CHOICE::EXIT:
    std::cout << "Exiting" << std::endl;
    break;
  default:
    std::cout << "Wrong Choice!" << std::endl;
    break;
  }
  return builder;
}

CHOICE getChoice()
{
  int choice;
  std::cout << "Build Choice: " << std::endl;
  std::cout << "1. Dell" << std::endl;
  std::cout << "2. HP" << std::endl;
  std::cout << "3. Lenovo" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "Choice: ";
  std::cin >> choice;
  if (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid Choice!" << std::endl;
    return CHOICE::INVALID;
  }
  return static_cast<CHOICE>(choice);
}

int main()
{
  CHOICE choice;
  do
  {
    choice = getChoice();
    if (choice == CHOICE::INVALID)
      continue;
    DesktopBuilder *builder = getBuilder(choice);
    if (builder)
    {
      Manufacturer *director = new Manufacturer(builder);
      director->buildDesktop()->showDesktop();
      delete director;
      delete builder;
    }
  } while (choice != CHOICE::EXIT);
}
