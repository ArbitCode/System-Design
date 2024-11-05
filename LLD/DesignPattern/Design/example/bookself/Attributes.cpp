#include "Attributes.h"
#include <cassert>
#include <string>

Attributes::Attributes(AttributeMap *pairs): attribute_map(pairs)
{
  for (auto it = pairs->begin(); it != pairs->end(); it++)
  {
    KEY key = it->first;
    int index = it->second.index();
    switch (key)
    {
    case KEY::YEAR:
      assert(index == (int)INDEXES::INT_INDEX);
      break;
    case KEY::FIRST:
    case KEY::LAST:
    case KEY::TITLE:
      assert(index == (int)INDEXES::STRING_INDEX);
      break;
    case KEY::KIND:
      assert(index == (int)INDEXES::KIND_INDEX);
      break;
    case KEY::GENRE:
      assert(index == (int)INDEXES::GENRE_INDEX);
      break;
    case KEY::REGION:
      assert(index == (int)INDEXES::REGION_INDEX);
      break;
    case KEY::SUBJECT:
      assert(index == (int)INDEXES::SUBJECT_INDEX);
    break;

    default:
      break;
    }
  }
}

bool Attributes::equal_ingnore_case(const std::string &string1, const std::string &string2) const
{
  if(string1.length() != string2.length())
    return false;
  for (int i = 0; i < string1.length(); i++)
    if(string1[i] != string2[i])
      return false;
  return true;
}

bool Attributes::is_match(const Attributes *target_attrs) const
{
  AttributeMap *target_pairs = target_attrs->attribute_map;
  for (auto it = target_pairs->begin(); it != target_pairs->end(); it++)
  {
    KEY target_key = it->first;
    AttributeValue target_value = it->second;
    if(!is_matching_pair(target_key, target_value))
    {
      return false;
    }
  }
    return true;
}


bool Attributes::is_matching_pair(const KEY &target_key, const AttributeValue &target_value) const
{
  if(attribute_map->find(target_key) == attribute_map->end())
  {
    return false;
  }
  if((*attribute_map)[target_key] == target_value)
  {
    return true;
  }
  if(target_value.index() == (int)INDEXES::STRING_INDEX)
  {
    return equal_ingnore_case(get<std::string>((*attribute_map)[target_key]), get<std::string>(target_value));
  }
  return false;
}
