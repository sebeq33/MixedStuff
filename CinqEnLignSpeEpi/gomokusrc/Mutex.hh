//
// Mutex.hh for Mutex.hh in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Tue Apr 16 12:11:57 2013 sebastien bequignon
// Last update Wed Apr 17 17:06:47 2013 sebastien bequignon
//

#ifndef MUTEX_H_
# define MUTEX_H_

#include <pthread.h>

class IMutex
{
public:
  virtual ~IMutex(void) {}; // "{}" don't forget else you'll have a "vtable ATTACK" =P
  virtual void lock(void) = 0;
  virtual void unlock(void) = 0;
  virtual bool trylock(void) = 0;
  virtual pthread_mutex_t *getMutex() = 0;
};

class Mutex : public IMutex
{
private:
  pthread_mutex_t mutex;
  Mutex(Mutex const &);
  Mutex &operator=(Mutex const &);

public:
  Mutex();
  virtual ~Mutex();
  virtual void lock(void);
  virtual void unlock(void);
  virtual bool trylock(void);
  virtual pthread_mutex_t *getMutex();
};

#endif /* !MUTEX_H_ */
