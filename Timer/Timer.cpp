#include "Timer.hh"

Timer::Timer()
{
  this->restart();
}

Timer::~Timer()
{

}

const Time &Timer::getCurrentTime() const
{
    return (current);
}

const Time &Timer::getLastTime() const
{
    return (last);
}

const Time &Timer::getSynchronizedTime() const
{
    return (sync);
}

const Time Timer::getEllapsedTime() const
{
    return (current - last);
}

void Timer::synchronizeTime(const Time &other)
{
    this->sync = other;
}

void Timer::update()
{
    this->last = current;
    current.updateTime();
    this->sync += (current - last);
}

void Timer::updateCurrent()
{
  current.updateTime();
}

void Timer::restart()
{
    this->last.updateTime();
    this->current.updateTime();
    this->sync.setSecond(0);
    this->sync.setMilli(0);
}

void Timer::sleepFPS(uint16_t fps) const
{
    Time tosleep(current - last);
    if (tosleep.getSecond() < 1)
    {
      int milli = 1000 / fps;
      if (milli > tosleep.getMilli())
        Time::msleep(milli - tosleep.getMilli());
    }
}
