//
// NamedPipes.hh for plazza in /home/mangeo_q//Tek2/git/plazza
//
// Made by quentin mangeon
// Login   <mangeo_q@epitech.net>
//
// Started on  Wed Apr 17 18:27:58 2013 quentin mangeon
// Last update Sun Apr 21 21:27:51 2013 sebastien bequignon
//

#ifndef NAMEDPIPES_H_
# define NAMEDPIPES_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Mutex.hh"
#include "ScopedLock.hh"
#include "Convert.hpp"

class NamedPipes
{
public:
  enum State
    {
      BLOCK,
      NONBLOCK
    };
private:
  std::string	path;
  std::fstream	file;
  State		state;
  Mutex		mutex;
  NamedPipes(const NamedPipes &);

  void open(void);
  void close(void);
  bool canRead(void);

public:
  NamedPipes(int id);
  ~NamedPipes();
  NamedPipes &operator>>(std::string &);
  NamedPipes &operator<<(const std::string &);
  void changeState(NamedPipes::State state);
};

#endif /* !NAMEDPIPES_H_ */
