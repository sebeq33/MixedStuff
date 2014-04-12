//
// Names.cpp for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 14:29:39 2013 julien canda
// Last update Sun Jan 27 07:06:45 2013 sebastien bequignon
//

#include "Names.hh"
#include "my_getenv.hh"
#include "IMonitorModule.hh"

Names::Names() :
  _hostname(""), _username("")
{
}

Names::~Names()
{
}

void Names::updateData()
{
  std::ifstream file;
  std::string	a_line;

  file.open("/proc/sys/kernel/hostname");
  if (file.is_open())
    {
      getline(file, _hostname);
    }
  file.close();
  try
    {
      _username = my_getenv("USERNAME");
    }
  catch (NoEnvException &e)
    {
      _username = "Unknown";
    }
}

TypeModule Names::getType() const
{
  return (NAME);
}

std::string Names::getHostName() const
{
  return (_hostname);
}

std::string Names::getUserName() const
{
  return (_username);
}
