//
// NamedPipes.cpp for plazza in /home/mangeo_q//Tek2/git/plazza
//
// Made by quentin mangeon
// Login   <mangeo_q@epitech.net>
//
// Started on  Wed Apr 17 18:26:29 2013 quentin mangeon
// Last update Sun Apr 21 22:44:15 2013 sebastien bequignon
// Last update Fri Apr 19 16:04:02 2013 quentin mangeon
//

#include "NamedPipes.hh"
#include "Convert.hpp"
#include <errno.h>

NamedPipes::NamedPipes(int id)
  : path("/tmp/Plazza_namedpipe"), state(NONBLOCK)
{
  path += Convert<std::string, int>::convert(id);
  path += ".fifo";

  if (mkfifo(path.c_str(), 0666) == -1 && errno != EEXIST)
    throw std::exception();
  this->open();
}

NamedPipes::~NamedPipes()
{
  this->close();
  unlink(path.c_str());
}

void NamedPipes::open(void)
{
  file.open(path.c_str(), std::fstream::in | std::fstream::out);
  if (!file.is_open())
    throw std::exception();
}

void NamedPipes::close(void)
{
  if (this->file.is_open())
    file.close();
}

NamedPipes &NamedPipes::operator>>(std::string &str)
{
  ScopedLock lock(&mutex);

  if (!file.good())
    throw std::exception();
  if (this->state == BLOCK || this->canRead())
    std::getline(file, str);
  else
    str = "";
  return (*this);
}

NamedPipes &NamedPipes::operator<<(const std::string &str)
{
  ScopedLock lock(&mutex);

  if (!file.good())
    throw std::exception();
  file << str << std::endl;
  return (*this);
}

bool NamedPipes::canRead(void)
{
  if (!file.good())
    return (false);
  std::streambuf* pbuf = file.rdbuf();
  std::streamsize size = pbuf->in_avail();
  return (size > 0);
}

void NamedPipes::changeState(NamedPipes::State state)
{
  ScopedLock lock(&mutex);

  this->state = state;
}
