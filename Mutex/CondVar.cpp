//
// CondVar.cpp for CondVar.cpp in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Wed Apr 17 17:03:30 2013 sebastien bequignon
// Last update Wed Apr 17 23:59:22 2013 sebastien bequignon
//

#include "CondVar.hh"
#include "MutexError.hh"

CondVar::CondVar(Mutex &mutex)
  : mutex(&mutex)
{
  if (pthread_cond_init(&cond, NULL) != 0)
    throw MutexError("Cond init");
}

CondVar::~CondVar()
{
  pthread_cond_destroy(&cond);
}

void CondVar::wait(void)
{
  if (pthread_cond_wait(&cond, mutex->getMutex()) != 0)
    throw MutexError("Cond wait");
}

void CondVar::signal(void)
{
  if (pthread_cond_signal(&cond) != 0)
    throw MutexError("Cond signal");
}

void CondVar::broadcast(void)
{
  if (pthread_cond_broadcast(&cond) != 0)
    throw MutexError("Cond broadcast");
}
