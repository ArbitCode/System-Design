#pragma once
#include "DesktopBuilder.h"

class LenovoBuilder : public DesktopBuilder
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