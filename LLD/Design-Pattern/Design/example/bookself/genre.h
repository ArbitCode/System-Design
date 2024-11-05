#pragma once
#include <ostream>

enum class GENRE
{
  ADENTURE,
  CLASSICS,
  DETECTIVE,
  FANTANSY,
  HISTORIC,
  HORROR,
  ROMANACE,
  SCIFI
};

inline std::ostream &operator<<(std::ostream &ostr, const GENRE genre)
{
  switch (genre)
  {
  case GENRE::CLASSICS:
    ostr << "Classics";
    break;
  case GENRE::ADENTURE:
    ostr << "ADENTURE";
    break;
  case GENRE::DETECTIVE:
    ostr << "DETECTIVE";
    break;
  case GENRE::FANTANSY:
    ostr << "FANTANSY";
    break;
  case GENRE::HISTORIC:
    ostr << "HISTORIC";
    break;
  case GENRE::HORROR:
    ostr << "HORROR";
    break;
  case GENRE::ROMANACE:
    ostr << "ROMANACE";
    break;
  case GENRE::SCIFI:
    ostr << "SCIFI";
    break;

  default:
    break;
  }
  return ostr;
}
