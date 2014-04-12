//
// DateTime.hh for MyKRellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 11:02:45 2013 julien canda
// Last update Sun Jan 27 06:24:23 2013 sebastien bequignon
//

#ifndef DATETIME_H_
# define DATETIME_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include "IMonitorDisplay.hh"
#include "IMonitorModule.hh"

class DateTime : public IMonitorModule
{
  std::string _time;
  std::string _date;
public:
  DateTime();
  virtual ~DateTime();
  virtual void updateData();
  virtual TypeModule getType() const;
  std::string getTime() const;
  std::string getDate() const;
};

#endif /* !DATETIME_H_ */
