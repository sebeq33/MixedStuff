//
// Core.hh for MyGKrellM in /home/canda_j//piscine/tek2/rush3/piscine_cpp_rush3-2016-bequig_s/src
//
// Made by julien canda
// Login   <canda_j@epitech.net>
//
// Started on  Sat Jan 26 17:29:26 2013 julien canda
// Last update Sun Jan 27 06:39:57 2013 sebastien bequignon
//

#ifndef CORE_H_
# define CORE_H_

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "IMonitorModule.hh"

class Core : public IMonitorModule
{
  float _previous_work0;
  float _previous_total0;
  float _previous_work1;
  float _previous_total1;
  float _previous_work2;
  float _previous_total2;
  float _previous_work3;
  float _previous_total3;

  float _core0Usage;
  float _core1Usage;
  float _core2Usage;
  float _core3Usage;
  float	_core;

  float _frequency;
  std::string _model;
  int _numberCores;

  void calcul_usage(float *_previous_work, float *_work_try, float *_coreUsage, std::ifstream *file_try);

public:
  Core();
  virtual ~Core();
  virtual void updateData();
  virtual TypeModule getType() const;
  float getUsage0() const;
  float getUsage1() const;
  float getUsage2() const;
  float getUsage3() const;
  float getCore() const;
  float getFrequency() const;
  std::string const &getModel() const;
  int getNumberCores() const;
};

#endif /* !CORE_H_ */
