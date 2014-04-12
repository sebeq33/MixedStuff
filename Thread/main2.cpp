#include <iostream>
#include "ThreadPool.hpp"
#include "Mutex.hh"

Mutex	mutex;
int	i = 0;

void my_sleep(int sec)
{
#ifdef WIN32
  Sleep(sec * 1000);
#else
  sleep(sec);
#endif
}

void my_msleep(int msec)
{
#ifdef WIN32
  Sleep(msec);
#else
  usleep(msec * 1000);
#endif
};

#include <stdio.h>
int32_t	test(int *param)
{
  mutex.lock();
  (*param)++;
  my_msleep(10);
  std::cout << "NOW : " << (*param) << std::endl;
  mutex.unlock();
}

int	main()
{
  Thread<int *> th;
  int		param = 0;

  ThreadPool<int> pool(20);

  for (int i = 0; i < 200; ++i)
    {
      pool.start(test, &param);
      my_msleep(5);
    }
  pool.wait();
  std::cout << "End = = = = =" << std::endl;
  std::cout << "Res : " << param << std::endl;
  return (0);
}
