#pragma once
#include <string>
#include <iostream>
#include <map>
#include <variant>
#include "key.h"
#include "region.h"
#include "genre.h"
#include "kind.h"
#include "subject.h"

typedef std::variant<int, std::string, KIND, GENRE, REGION, SUBJECT> AttributeValue;
typedef std::map<KEY, AttributeValue> AttributeMap;

enum class INDEXES
{
  INT_INDEX,
  STRING_INDEX,
  KIND_INDEX,
  GENRE_INDEX,
  REGION_INDEX,
  SUBJECT_INDEX
};

class Attributes
{
public:
  Attributes(AttributeMap *const pairs);
  ~Attributes() { delete attribute_map; }
  bool is_match(const Attributes *target_attrs) const;
  friend std::ostream &operator<<(std::ostream &ostr, const Attributes *attrs);

private:
  AttributeMap *attribute_map;
  bool is_matching_pair(const KEY &target_key, const AttributeValue &target_value) const;
  bool equal_ingnore_case(const std::string &string1, const std::string &string2) const;
};

inline std::ostream &operator<<(std::ostream &ostr, const Attributes *attr)
{
  AttributeMap *pairs = attr->attribute_map;
  ostr << "{";
  for (auto it = pairs->begin(); it != pairs->end(); it++)
  {
    KEY key = it->first;
    AttributeValue value = it->second;
  
    if(it != pairs->begin())
      ostr << ", ";
    ostr << key << ": ";
    switch (key)
    {
    case KEY::KIND:
      ostr << get<KIND>(value);
      break;
    case KEY::TITLE:
    case KEY::FIRST:
    case KEY::LAST:
      ostr << "'" << get<std::string>(value) << "'";
      break;
    case KEY::GENRE:
      ostr << get<GENRE>(value);
      break;
    case KEY::YEAR:
      ostr << get<int>(value);
      break;
    case KEY::REGION:
      ostr << get<REGION>(value);
      break;
    case KEY::SUBJECT:
      ostr << get<SUBJECT>(value);
      break;
    default:
      break;
    }
  }
  ostr << "}";
  return ostr;
}
