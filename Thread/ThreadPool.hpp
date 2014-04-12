//
// ThreadPool.hpp for ThreadPool.hpp in /home/bequig_s//workspace/rtype/include/Thread
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Jul 28 18:57:29 2013 sebastien bequignon
// Last update Sun Jul 28 19:20:37 2013 sebastien bequignon
//

#ifndef THREADPOOL_H_
# define THREADPOOL_H_

#include <list>
#include "Thread.hpp"

template <typename T>
class ThreadPool
{
private:
  typedef Thread<T *>		ThreadType;
  std::list<ThreadType *>	threadList;

  static int32_t	tool_func(T *param)
  {
    return (param->operator());
  }

public:
  ThreadPool(int8_t nbThread)
  {
    for (int i = 0; i < nbThread; ++i)
      threadList.push_back(new ThreadType());
  }

  ~ThreadPool()
  {
    ThreadType	*tmp = NULL;

    this->wait();
    for (typename std::list<ThreadType *>::iterator it = threadList.begin();
	 it != threadList.end(); ++it)
      {
	if ((tmp = (*it)) != NULL)
	  delete tmp;
      }
    while (!threadList.empty())
      threadList.pop_back();
  }

  bool  operator()(T *param)
  {
    return (this->start(param));
  }

  bool	operator()(int32_t (*func)(T *), T *param)
  {
    return (this->start(func, param));
  }

  bool	start(T *param)
  {
    return (this->start(&tool_func, param));
  }

  bool	start(int32_t (*func)(T *), T *param)
  {
    ThreadType	*tmp = NULL;

    for (typename std::list<ThreadType *>::iterator it = threadList.begin();
	 it != threadList.end(); ++it)
      {
	if ((tmp = (*it)) != NULL && tmp->getState() != ThreadType::RUNNING)
	  {
	    tmp->start(func, param);
	    return (true);
	  }
      }
    return (false);
  }

  int8_t	nb_running() const
  {
    ThreadType	*tmp = NULL;
    int8_t	res = 0;

    for (typename std::list<ThreadType *>::const_iterator it = threadList.begin();
	 it != threadList.end(); ++it)
      {
	if ((tmp = (*it)) != NULL && tmp->getState() == ThreadType::RUNNING)
	  res++;
      }
    return (res);

  }

  void		wait()
  {
    ThreadType	*tmp = NULL;

    for (typename std::list<ThreadType *>::iterator it = threadList.begin();
	 it != threadList.end(); ++it)
      {
	if ((tmp = (*it)) != NULL)
	  tmp->wait();
      }
  }

  const std::list<ThreadType *> &getlist() const
  {
    return (threadList);
  }
};

#endif /* !THREADPOOL_H_ */
