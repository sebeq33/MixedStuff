//
// IMonitorDisplay.hh for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src/interface
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 10:54:49 2013 julien canda
// Last update Sun Jan 27 02:07:58 2013 sebastien bequignon
//

#ifndef IMONITORDISPLAY_H_
# define IMONITORDISPLAY_H_

#include <iostream>
#include "IMonitorModule.hh"

class IMonitorDisplay
{
public:
  virtual ~IMonitorDisplay() {};
  virtual void execute() = 0;
};

#endif /* !IMONITORDISPLAY_H_ */
