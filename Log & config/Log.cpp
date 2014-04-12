//
// Log.cpp for  in /home/bagnos_c//Tek2/C++/Plazza/plazza
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Fri Apr 19 17:18:39 2013 caroline bagnost
// Last update Sun Apr 21 21:57:40 2013 sebastien bequignon
//

#include "Log.hh"

Log::Log()
  : file("log.txt", std::fstream::out | std::fstream::trunc)
{

}

Log::~Log()
{
  if (file.is_open())
    file.close();
}

Log & Log::operator<<(const std::string & log)
{
  ScopedLock lock(&mutex);
  if (file.good())
    file << log << std::endl;
  return (*this);
}

