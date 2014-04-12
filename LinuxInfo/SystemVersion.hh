//
// SystemVersion.hh for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 11:46:06 2013 julien canda
// Last update Sun Jan 27 04:02:53 2013 julien canda
//

#ifndef SYSTEMVERSION_H_
# define SYSTEMVERSION_H_

#include <iostream>
#include <fstream>
#include <string>
#include "IMonitorDisplay.hh"
#include "IMonitorModule.hh"

class SystemVersion : public IMonitorModule
{
  std::string _KernelVersion;
  std::string _OSVersion;

public:
  SystemVersion();
  virtual ~SystemVersion();
  virtual void updateData();
  TypeModule getType() const;
  std::string getKernelVersion() const;
  std::string getOSBVersion() const;
};

#endif /* !SYSTEMVERSION_H_ */
