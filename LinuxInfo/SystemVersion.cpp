//
// SystemVersion.cpp for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 11:46:14 2013 julien canda
// Last update Sun Jan 27 07:09:47 2013 sebastien bequignon
//

#include "SystemVersion.hh"

SystemVersion::SystemVersion() :
  _KernelVersion(""), _OSVersion("")
{
}

SystemVersion::~SystemVersion()
{
}

void SystemVersion::updateData()
{
  std::ifstream file;
  std::string	a_line;

  file.open("/proc/version");
  if (file.is_open())
    {
      getline(file, a_line);
      _KernelVersion = a_line.substr(0, a_line.find(" ("));
    }
  file.close();

  file.open("/etc/os-release");
  if (file.is_open())
    {
      getline(file, a_line);
      _OSVersion = a_line.substr(5);

      _OSVersion += " ";

      getline(file, a_line);
      _OSVersion += a_line.substr(10);
    }
  file.close();
}

TypeModule SystemVersion::getType() const
{
  return (SYSTEM_VERSION);
}

std::string SystemVersion::getKernelVersion() const
{
  return (_KernelVersion);
}

std::string SystemVersion::getOSBVersion() const
{
  return (_OSVersion);
}
