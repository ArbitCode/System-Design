#pragma once
#include "DesktopBuilder.h"

class Manufacturer
{
private:
  DesktopBuilder *m_desktopBuilder;

public:
  Manufacturer(DesktopBuilder *desktopBuilder);
  Desktop *buildDesktop();
};
