#pragma once

#include <iostream>

enum class KIND
{
  FICTION,
  COOKBOOK,
  HOWTO
};

inline std::ostream& operator <<(std::ostream& ostr, const KIND &kind)
{
  switch (kind)
  {
  case KIND::FICTION:
    ostr << "FICTION";
    break;
  case KIND::COOKBOOK:
    ostr << "COOKBOOK";
    break;
  case KIND::HOWTO:
    ostr << "HOWTO";
    break;

  default:
    break;
  }
  return ostr;
}
