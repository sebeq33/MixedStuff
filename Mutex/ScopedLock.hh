//
// ScopedLock.hh for ScopedLock.hh in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Wed Apr 17 17:06:55 2013 sebastien bequignon
// Last update Wed Apr 17 17:07:21 2013 sebastien bequignon
//

#ifndef SCOPEDLOCK_H_
# define SCOPEDLOCK_H_

#include "Mutex.hh"

class ScopedLock
{
private:
  Mutex *mutex;
  ScopedLock(ScopedLock const &);
  ScopedLock &operator=(ScopedLock const &);

public:
  ScopedLock(Mutex *_mutex);
  ~ScopedLock();
  Mutex *getMutex();
};

#endif /* !SCOPEDLOCK_H_ */
