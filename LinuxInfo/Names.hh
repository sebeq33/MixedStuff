//
// Names.hh for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 14:29:32 2013 julien canda
// Last update Sun Jan 27 04:02:29 2013 julien canda
//

#ifndef NAMES_H_
# define NAMES_H_

#include <string>
#include <iostream>
#include <fstream>
#include "IMonitorDisplay.hh"
#include "IMonitorModule.hh"

class Names : public IMonitorModule
{
  std::string _hostname;
  std::string _username;
public:
  Names();
  virtual ~Names();
  virtual void updateData();
  virtual TypeModule getType() const;
  std::string getHostName() const;
  std::string getUserName() const;
};

#endif /* !NAMES_H_ */
