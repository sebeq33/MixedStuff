//
// Protocole.hpp for bmail in /home/bagnos_c//Tek2/System_Unix/Rush/bmail
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Sat Mar  9 11:02:51 2013 caroline bagnost
// Last update Sun Mar 10 19:09:30 2013 sebastien bequignon
//

#ifndef PROTOCOLE_HH_
# define PROTOCOLE_HH_

# include "Message.hh"
# include <iostream>

# define LEN (255)

class Protocole
{
protected:

  int sock;
  int port;

public:

  Protocole(const char * hostname, int port);
  virtual ~Protocole();
};

#endif
