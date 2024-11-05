#pragma once

#include <iostream>

enum class SUBJECT
{
  DRAWING,
  PAINTING,
  WRITING
};

inline std::ostream& operator <<(std::ostream & ostr, const SUBJECT subject)
{
  switch (subject)
  {
  case SUBJECT::DRAWING:
    ostr << "DRAWING";
    break;
  case SUBJECT::PAINTING:
    ostr << "PAINTING";
    break;
  case SUBJECT::WRITING:
    ostr << "WRITING";
    break;
  default:
    break;
  }
  return ostr;
}
