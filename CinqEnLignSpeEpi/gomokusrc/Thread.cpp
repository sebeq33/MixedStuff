//
// Thread.cpp for Thread.cpp in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Wed Apr 17 16:58:09 2013 sebastien bequignon
// Last update Sun Apr 21 15:41:07 2013 sebastien bequignon
//

#include "Thread.hh"

Thread::Thread() : state(CREATED)
{

}

Thread::~Thread()
{

}

IThread::ThreadState Thread::getState() const
{
  return (state);
}

bool Thread::start(void *(*func)(void *), void *param)
{
  state = STARTED;
  return (pthread_create(&thread, NULL, func, param) == 0);
}

bool Thread::wait(void)
{
  bool res;

  res = (pthread_join(thread, NULL) == 0);
  state = STOPPED;
  return (res);
}

bool Thread::checkIsFinished(void)
{
  if (this->state != STARTED)
    return (true);
  if (pthread_tryjoin_np(thread, NULL) != 0)
    return (false);
  this->state = STOPPED;
  return (true);
}

bool Thread::operator()(void *(*func)(void *), void *param)
{
  return (this->start(func, param));
}

