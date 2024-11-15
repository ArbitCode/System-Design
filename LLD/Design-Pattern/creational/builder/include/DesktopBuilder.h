#pragma once
#include "Desktop.h"

class DesktopBuilder : public Desktop
{
protected:
  Desktop *m_desktop;

public:
  DesktopBuilder() { m_desktop = new Desktop(); }
  virtual void buildOs() = 0;
  virtual void buildRam() = 0;
  virtual void buildMouse() = 0;
  virtual void buildProcessor() = 0;
  virtual void buildCharger() = 0;
  virtual void buildMonitor() = 0;
  virtual void buildKeyboard() = 0;
  virtual Desktop *getDesktop() { return m_desktop; }
  virtual ~DesktopBuilder(){}
};
