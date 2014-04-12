//
// DateTime.cpp for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 11:02:52 2013 julien canda
// Last update Sun Jan 27 04:01:54 2013 julien canda
//

#include <curses.h>
#include "DateTime.hh"

DateTime::DateTime() : _time(""), _date("")
{
}

DateTime::~DateTime()
{
}

void DateTime::updateData()
{
  time_t t;
  std::ostringstream os;

  time (&t);
  t += 3600;
  struct tm *a = gmtime(&t);

  os << a->tm_hour << ':';
  if (a->tm_min < 10)
    os << '0';
  os << a->tm_min << ':';
  if (a->tm_sec < 10)
    os << '0';
  os << a->tm_sec;
  _time = os.str();
  os.clear();
  os.str("");
  os << a->tm_mday;
  os << '/';
  if (a->tm_mon + 1 < 10)
    os << '0';
  os << (a->tm_mon + 1);
  os << '/';
  os << (a->tm_year + 1900);
  _date = os.str();
  os.clear();
}

TypeModule DateTime::getType() const
{
  return (DATETIME);
}

std::string DateTime::getTime() const
{
  return (_time);
}

std::string DateTime::getDate() const
{
  return (_date);
}
