//
// Log.hh for  in /home/bagnos_c//Tek2/C++/Plazza/plazza
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Fri Apr 19 17:16:59 2013 caroline bagnost
// Last update Sun Apr 21 15:44:02 2013 sebastien bequignon
//

#ifndef LOG_HH
#define LOG_HH

#include <fstream>
#include "Mutex.hh"
#include "ScopedLock.hh"

class Log
{
private:
  std::fstream file;
  Mutex mutex;
public:
  Log();
  Log & operator<<(const std::string & log);
  ~Log();
};

#endif /* !LOG_HH */
