#pragma once
#include "DesktopBuilder.h"

class DellBuilder : public DesktopBuilder
{

protected:
  void buildOs();
  void buildRam();
  void buildMouse();
  void buildProcessor();
  void buildCharger();
  void buildMonitor();
  void buildKeyboard();
};
