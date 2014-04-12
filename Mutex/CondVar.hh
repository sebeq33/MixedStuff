//
// CondVar.hh for CondVar.hh in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Tue Apr 16 16:51:32 2013 sebastien bequignon
// Last update Thu Apr 18 00:00:03 2013 sebastien bequignon
//

#ifndef CONDVAR_H_
# define CONDVAR_H_

#include <pthread.h>
#include <exception>
#include <iostream>
#include "Mutex.hh"

class ICondVar {
public:
  ~ICondVar(){};
  virtual void wait(void) = 0;
  virtual void signal(void) = 0;
  virtual void broadcast(void) = 0;
};

class CondVar {
private:
  pthread_cond_t cond;
  Mutex *mutex;
  CondVar(const CondVar &);

public:
  CondVar(Mutex &mutex);
  ~CondVar();
  virtual void wait(void);
  virtual void signal(void);
  virtual void broadcast(void);
};

#endif /* !CONDVAR_H_ */
