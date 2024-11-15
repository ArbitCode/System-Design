#include "include/Manufacturer.h"

Manufacturer::Manufacturer(DesktopBuilder *desktopBuilder) : m_desktopBuilder(desktopBuilder) {}
Desktop *Manufacturer::buildDesktop()
{
  m_desktopBuilder->buildOs();
  m_desktopBuilder->buildCharger();
  m_desktopBuilder->buildKeyboard();
  m_desktopBuilder->buildMonitor();
  m_desktopBuilder->buildProcessor();
  m_desktopBuilder->buildMouse();
  m_desktopBuilder->buildRam();
  return m_desktopBuilder->getDesktop();
}

