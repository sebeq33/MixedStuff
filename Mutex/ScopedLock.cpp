//
// ScopedLock.cpp for ScopedLock.cpp in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Wed Apr 17 16:56:31 2013 sebastien bequignon
// Last update Thu Apr 18 11:49:00 2013 caroline bagnost
//

#include "ScopedLock.hh"

ScopedLock::ScopedLock(Mutex *_mutex)
  : mutex(_mutex)
{
  mutex->lock();
}

ScopedLock::~ScopedLock()
{
  mutex->unlock();
}

Mutex *ScopedLock::getMutex()
{
  return (mutex);
}
