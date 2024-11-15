#include <iostream>
#include "include/Desktop.h"

void Desktop::setOs(std::string os) { m_os = os; }
void Desktop::setRam(std::string ram) { m_ram = ram; }
void Desktop::setCharger(std::string charger) { m_charger = charger; }
void Desktop::setKeyboard(std::string keyboard) { m_keyboard = keyboard; }
void Desktop::setMonitor(std::string monitor) { m_monitor = monitor; }
void Desktop::setMouse(std::string mouse) { m_mouse = mouse; }
void Desktop::setProcessor(std::string processor) { m_processor = processor; }

void Desktop::showDesktop()
{
  std::cout << "***************************************************" << std::endl;
  std::cout << "OS: " << m_os << std::endl;
  std::cout << "Ram: " << m_ram << std::endl;
  std::cout << "Charger: " << m_charger << std::endl;
  std::cout << "Monitor: " << m_monitor << std::endl;
  std::cout << "Mouse: " << m_mouse << std::endl;
  std::cout << "Processor: " << m_processor << std::endl;
  std::cout << "Keyboard: " << m_keyboard << std::endl;
  std::cout << "***************************************************" << std::endl;
}
