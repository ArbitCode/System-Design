#pragma once
#include <string>

class Desktop
{
  std::string m_os;
  std::string m_ram;
  std::string m_processor;
  std::string m_mouse;
  std::string m_keyboard;
  std::string m_monitor;
  std::string m_charger;

public:
  void setOs(std::string os);
  void setRam(std::string ram);
  void setCharger(std::string charger);
  void setKeyboard(std::string keyboard);
  void setMonitor(std::string monitor);
  void setMouse(std::string mouse);
  void setProcessor(std::string processor);

  void showDesktop();
};
