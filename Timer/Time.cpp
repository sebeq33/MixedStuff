//
// Time.cpp for Time.cpp in /home/bequig_s//workspace/c++/rtype
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 15 17:01:01 2013 sebastien bequignon
// Last update Fri Jul 26 19:23:29 2013 sebastien bequignon
//

#include "Time.hh"

#ifdef WIN32
  Time::t_time 		Time::start;
#else
  struct timeval 	Time::start;
#endif

bool Time::started = false;

Time::Time()
  : seconds(0), milli(0)
{
}

Time::Time(uint32_t sec, uint16_t mil)
    : seconds(sec), milli(mil)
{
}

Time::Time(const Time &t)
{
  this->seconds = t.seconds;
  this->milli = t.milli;
}

Time::~Time()
{
}

Time &Time::operator=(const Time &t)
{
  if (this != &t)
    {
      this->seconds = t.seconds;
      this->milli = t.milli;
    }
  return (*this);
}

Time &Time::operator+=(const Time &t)
{
  addTime(t.seconds, t.milli);
  return (*this);
}

Time &Time::operator-=(const Time &t)
{
  subTime(t.seconds, t.milli);
  return (*this);
}

Time Time::operator+(const Time &t) const
{
  Time result(*this);
  return ((result += t));
}

Time Time::operator-(const Time &t) const
{
  Time result(*this);
  return ((result -= t));
}

void Time::addTime(uint32_t s, uint16_t m)
{
  uint32_t t;

  t = this->milli + m;
  this->seconds += s + t / 1000;
  this->milli = t % 1000;
}

void Time::subTime(uint32_t s, uint16_t m)
{
  if (this->milli < m)
  {
    this->seconds = this->seconds - s - 1;
    this->milli = 1000 - (m - this->milli);
  }
  else
  {
    this->seconds -= s;
    this->milli -= m;
  }
}

void Time::setSecond(uint32_t sec)
{
  this->seconds = sec;
}

void Time::setMilli(uint16_t milli)
{
  if (milli > 1000)
    this->milli = 0;
  else
    this->milli = milli;
}

uint32_t Time::getSecond() const
{
  return (this->seconds);
}

uint16_t Time::getMilli() const
{
  return (this->milli);
}

void Time::updateTime()
{
  if (!Time::started)
    {
      Time::updateStart();
      this->seconds = 0;
      this->milli = 0;
      return ;
    }

#ifdef WIN32
  FILETIME current;
  ULARGE_INTEGER t;
  t_time now;

  GetSystemTimeAsFileTime(&current);
  t.HighPart = current.dwHighDateTime;
  t.LowPart = current.dwLowDateTime;
  now.sec = t.QuadPart / 10000000;
  now.milli = (t.QuadPart / 10000) % 1000;

  if (now.milli < start.milli)
  {
      this->seconds = now.sec - start.sec - 1;
      this->milli = 1000 - (start.milli - now.milli);
  }
  else
  {
      this->seconds = now.sec - start.sec;
      this->milli = now.milli - start.milli;
  }

#else
  struct timeval current;

  gettimeofday(&current, NULL);
  if (current.tv_usec < Time::start.tv_usec)
    {
      this->seconds = current.tv_sec - Time::start.tv_sec - 1;
      this->milli = 1000 - ((Time::start.tv_usec - current.tv_usec) / 1000);
    }
  else
    {
      this->seconds = current.tv_sec - Time::start.tv_sec;
      this->milli = (current.tv_usec - Time::start.tv_usec) / 1000;
    }
#endif
}

void Time::updateStart()
{
#ifdef WIN32
  FILETIME current;
  ULARGE_INTEGER t;

  GetSystemTimeAsFileTime(&current);
  t.HighPart = current.dwHighDateTime;
  t.LowPart = current.dwLowDateTime;
  // t.QuadPart = nb de 100 nanosec depuis 1960 environ

  start.sec = t.QuadPart / 10000000;
  start.milli = (t.QuadPart / 10000) % 1000;

#else
  gettimeofday(&Time::start, NULL);
#endif
  Time::started = true;
}

void Time::sleep()
{
  Time::sleep(this->seconds);
  Time::msleep(this->milli);
}

void Time::sleep(uint32_t sec)
{
#ifdef WIN32
  ::Sleep(sec * 1000);
#else
  ::sleep(sec);
#endif
}

void Time::msleep(uint16_t msec)
{
#ifdef WIN32
  ::Sleep(msec);
#else
  ::usleep(msec * 1000);
#endif
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
  os << t.getSecond() << ',' << t.getMilli();
  return (os);
}
