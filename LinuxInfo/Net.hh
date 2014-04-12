//
// Net.hh for Rush3 in /home/savide_k/local/piscine_cpp/Rush3/piscine_cpp_rush3-2016-bequig_s
// 
// Made by kevin savidetove
// Login   <savide_k@epitech.net>
// 
// Started on  Sat Jan 26 22:57:52 2013 kevin savidetove
// Last update Sun Jan 27 03:56:32 2013 kevin savidetove
//

#ifndef NET_HH_
# define NET_HH_

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "IMonitorModule.hh"


class Net : public IMonitorModule
{
  int           _prevDataRecieved;
  int           _dataRecieved;

  int           _prevDataTransmitted;
  int           _dataTransmitted;

  int		_receptionRate;
  int		_transmissionRate;

public:
  Net();
  virtual ~Net();
  virtual void updateData();
  int	my_atoi(std::string);
  int	getDataReceived() const;
  int	getDataTransmitted() const;
  int	getReceptionRate() const;
  int	getTransmissionRate() const;
  virtual TypeModule   getType() const;
};

#endif /* NET_HH_ */
