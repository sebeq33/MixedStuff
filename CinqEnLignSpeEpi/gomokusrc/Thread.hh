//
// Thread.hh for Thread.hh in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Tue Apr 16 13:29:51 2013 sebastien bequignon
// Last update Sun Apr 21 06:50:50 2013 sebastien bequignon
//

#ifndef THREAD_H_
# define THREAD_H_

#include <pthread.h>

class IThread
{
public:
  enum ThreadState
    {
      CREATED,
      STARTED,
      STOPPED,
    };
  virtual ~IThread() {};
  virtual bool operator()(void *(*func)(void *), void *param) = 0;
  virtual bool start(void *(*func)(void *), void *param) = 0;
  virtual bool wait(void) = 0;
  virtual bool checkIsFinished(void) = 0;
  virtual ThreadState getState() const = 0;
};

class Thread : public IThread
{
private:
  pthread_t thread;
  ThreadState state;

  Thread(Thread const &);
  Thread &operator=(Thread const &);

public:
  Thread();
  ~Thread();
  virtual bool operator()(void *(*func)(void *), void *param);
  virtual bool start(void *(*func)(void *), void *param);
  virtual bool wait(void);
  virtual bool checkIsFinished(void);
  virtual ThreadState getState() const;
};

#endif /* !THREAD_H_ */
