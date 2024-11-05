#pragma once

#include <iostream>

enum class KEY
{
  KIND,
  TITLE,
  LAST,
  FIRST,
  YEAR,
  GENRE,
  REGION,
  SUBJECT
};

inline std::ostream& operator<<(std::ostream &ostr, const KEY &key)
{
  switch (key)
  {
  case KEY::KIND:
    ostr << "KIND";
    break;
  case KEY::TITLE:
    ostr << "TITLE";
    break;
  case KEY::LAST:
    ostr << "LAST";
    break;
  case KEY::FIRST:
    ostr << "FIRST";
    break;
  case KEY::YEAR:
    ostr << "YEAR";
    break;
  case KEY::GENRE:
    ostr << "GENRE";
    break;
  case KEY::REGION:
    ostr << "REGION";
    break;
  case KEY::SUBJECT:
    ostr << "SUBJECT";
    break;
  default:
    break;
  }
  return ostr;
}
