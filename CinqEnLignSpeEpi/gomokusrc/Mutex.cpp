//
// Mutex.cpp for Mutex.cpp in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Wed Apr 17 16:54:28 2013 sebastien bequignon
// Last update Thu Apr 18 11:49:01 2013 caroline bagnost
//

#include <exception>
#include "Mutex.hh"
#include "MutexError.hh"

Mutex::Mutex()
{
  if (pthread_mutex_init(&mutex, NULL) != 0)
    throw MutexError("init");
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&mutex);
}

void Mutex::lock(void)
{
  pthread_mutex_lock(&mutex);
}

void Mutex::unlock(void)
{
  pthread_mutex_unlock(&mutex);
}

bool Mutex::trylock(void)
{
    return (pthread_mutex_trylock(&mutex));
}

pthread_mutex_t *Mutex::getMutex()
{
  return (&mutex);
}
