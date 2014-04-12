#ifndef TIMER_H_
# define TIMER_H_

#include <stdint.h>
#include "Time.hh"

class Timer
{
private:
  Time current;
  Time last;
  Time sync;

public:
  Timer();
  ~Timer();

  const Time &getCurrentTime() const;
  const Time &getLastTime() const;
  const Time &getSynchronizedTime() const;
  const Time getEllapsedTime() const;
  void synchronizeTime(const Time &other);
  void update();
  void updateCurrent();
  void restart();
  void sleepFPS(uint16_t fps) const;
};

#endif
