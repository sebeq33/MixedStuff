//
// Time.hh for Time.hh in /home/bequig_s//workspace/c++/rtype
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 15 17:01:01 2013 sebastien bequignon
// Last update Fri Jul 26 19:09:02 2013 sebastien bequignon
//

#ifndef TIME_H_
# define TIME_H_

#include <stdint.h>
#include <iostream>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

class			Time
{
private:
#ifdef WIN32
  typedef struct	s_time
  {
    uint64_t    sec     : 54;
    uint16_t    milli   : 10;
  }			t_time;
  static t_time		start;
#else
  static struct timeval start;
#endif
  static bool		started;

  uint32_t	seconds	: 22;
  uint16_t	milli	: 10;

public:
  Time();
  Time(uint32_t sec, uint16_t milli);
  Time(const Time &t);
  ~Time();

  Time &operator=(const Time &t);
  Time &operator+=(const Time &t);
  Time &operator-=(const Time &t);
  Time operator+(const Time &t) const;
  Time operator-(const Time &t) const;
  void			addTime(uint32_t sec, uint16_t milli);
  void			subTime(uint32_t sec, uint16_t milli);
  void			setSecond(uint32_t sec);
  void			setMilli(uint16_t milli);
  uint32_t		getSecond() const;
  uint16_t		getMilli() const;
  void			updateTime();
  static void		updateStart();
  void			sleep();
  static void		sleep(uint32_t sec);
  static void		msleep(uint16_t msec);
};

std::ostream &operator<<(std::ostream &os, const Time &t);

#endif /* !TIME_H_ */
