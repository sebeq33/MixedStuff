//
// SafeQueue.hh for SafeQueue.hh in /home/bequig_s//workspace/c++/plazza/tp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Tue Apr 16 14:38:18 2013 sebastien bequignon
// Last update Wed Apr 17 17:07:55 2013 sebastien bequignon
//

#ifndef SAFEQUEUE_H_
# define SAFEQUEUE_H_

#include <queue>
#include "ScopedLock.hh"
#include "CondVar.hh"
#include "Mutex.hh"

template <typename T>
class SafeQueue
{
private:
  std::queue<T> queue;
  bool finished;
  Mutex mutex;
  CondVar cond;

  SafeQueue(SafeQueue const &);
  SafeQueue &operator=(SafeQueue const &);

public:
  SafeQueue()
    : finished(false), cond(mutex)
  {
  }

  ~SafeQueue()  {}

  void push(T value)
  {
    mutex.lock();
    queue.push(value);
    cond.signal();
    mutex.unlock();
  }

  bool tryPop(T& value)
  {
    ScopedLock lock(&mutex);

    if (queue.size() <= 0)
      {
	return (false);
      }
    value = queue.front();
    queue.pop();
    return (true);
  }

  bool pop(T &value)
  {
    ScopedLock lock(&mutex);

    if (finished)
      return (false);
    while (queue.size() <= 0)
      {
	if (finished)
	  {
	    cond.signal();
	    return (false);
	  }
	cond.wait();
      }
    value = queue.front();
    queue.pop();
    return (value);
  }

  size_t getSize() const
  {
    return (queue.size());
  }

  bool isFinished(void) const
  {
    return (finished);
  }

  void setFinished(void)
  {
    finished = true;
    cond.signal();
  }
};

#endif /* !SAFEQUEUE_H_ */
