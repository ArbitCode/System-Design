#pragma once

#include <iostream>

enum class REGION
{
  CHINA,
  FRANCE,
  ITALY,
  INDIA,
  MEXICO,
  PERSIA,
  USA
};

inline std::ostream& operator << (std::ostream& ostr, const REGION region)
{
  switch (region)
  {
  case REGION::CHINA:
    ostr << "CHINA";
    break;
  case REGION::FRANCE:
    ostr << "FRANCE";
    break;
  case REGION::ITALY:
    ostr << "ITALY";
    break;
  case REGION::INDIA:
    ostr << "INDIA";
    break;
  case REGION::MEXICO:
    ostr << "MEXICO";
    break;
  case REGION::PERSIA:
    ostr << "PERSIA";
    break;
  case REGION::USA:
    ostr << "USA";
    break;

  default:
    break;
  }
  return ostr;
}
