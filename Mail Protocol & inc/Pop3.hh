//
// Pop3.hpp for bmail in /home/bagnos_c//Tek2/System_Unix/Rush/bmail
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Sat Mar  9 11:03:45 2013 caroline bagnost
// Last update Sun Mar 10 21:14:02 2013 sebastien bequignon
//

#ifndef POP3_HH_
#define POP3_HH_

#include <string>
#include "IGetProtocol.hh"
#include "Message.hh"
#include "Protocole.hh"

class Pop3 : public Protocole, public IGetProtocol
{
private:
  char buffer[512];
  std::string mail;

  void sendRequest(const char *format, const char * param);
  void sendRequest(const char *format, int param);
  bool receive();

public:
  Pop3(const char * hostname, int port,
       const char * username, const char * password);
  ~Pop3();
  Message *getMail(int idMail);
  int getNbMail();
  void suprMail(int);
};

#endif
