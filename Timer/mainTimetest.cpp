//
// mainTimetest.cpp for mainTimetest.cpp in /home/bequig_s//workspace/c++/rtype
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 15 18:41:05 2013 sebastien bequignon
// Last update Fri Jul 26 19:10:45 2013 sebastien bequignon
//

#include "Timer.hh"
#include "Time.hh"

int main()
{
  Time t;

  Time::updateStart();
  /*
    for (int i = 0; i < 6; ++i)
    {
    t.updateTime();
    std::cout << "second : " << t.getSecond() << " milli : " << t.getMilli() << std::endl;
    Time::sleep(5);
    Time::msleep(200);
  }*/

  Timer timer;
  Time get(1000, 800);
  timer.synchronizeTime(get);
  Time prev;

  for (int i = 0; i < 6; ++i)
  {
    std::cout << "====================" << std::endl;

    Time now;
    now.updateTime();
    Time res;
    res = now - prev;
    std::cout << "TEST : " << res << std::endl;
    prev = now;

    get = timer.getLastTime();
    std::cout << "LAST      second : " << get.getSecond()
          << " milli : " << get.getMilli() << std::endl;
    get = timer.getCurrentTime();
    std::cout << "CURRENT   second : " << get.getSecond()
          << " milli : " << get.getMilli() << std::endl;
    get = timer.getEllapsedTime();
    std::cout << "ELLAPSED  second : " << get.getSecond()
          << " milli : " << get.getMilli() << std::endl;
    get = timer.getSynchronizedTime();
    std::cout << "SYNCHRO   second : " << get.getSecond()
          << " milli : " << get.getMilli() << std::endl;
    Time::msleep(200);
    timer.update();
    timer.sleepFPS(60);
  }
  return (0);
}
