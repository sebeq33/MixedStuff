#include <iostream>
#include "Thread.hpp"
#include "ThreadPool.hpp"
#include "Mutex.hh"

Mutex	mutex;
int		i = 0;

void	my_sleep(int sec)
{
#ifdef WIN32
  Sleep(sec * 1000);
#else
  sleep(sec);
#endif
}

void	my_msleep(int msec)
{
#ifdef WIN32
  Sleep(msec);
#else
  usleep(msec * 1000);
#endif
}

int32_t func(int* param)
{
  mutex.lock();
  std::cout << "NOW : " << (*param)++ << std::endl;
  my_msleep(10);
  mutex.unlock();
  return (11);
}

void	test1()
{
  std::cout << "START" << std::endl;
  Thread<int *> th;
  int		i = 0;

  th(&func, &i);
  th(&func, &i);
  th(&func, &i);
  th(&func, &i);
  th.wait();
  th(&func, &i);
  th.wait();

  std::cout << "END = " << i << std::endl;
  std::cout << "ret = " << th.getReturnvalue() << std::endl;
  std::cout << "exit = " << th.getExitCode() << std::endl;
}

void	test2()
{
  ThreadPool<int> pool(10);
  int	param = 0;

  for (int i = 0; i < 200; ++i)
    {
      pool(func, &param);
      my_msleep(5);
    }
  pool.wait();

  std::cout << "END = " << param << std::endl;
}

int	main()
{
  std::cout << "=====================" << std::endl;
  test1();
  std::cout << "=====================" << std::endl;
  test2();
  return (0);
}
