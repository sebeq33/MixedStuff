//
// Imap.hpp for bmail in /home/bagnos_c//Tek2/System_Unix/Rush/bmail
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Sat Mar  9 11:06:01 2013 caroline bagnost
// Last update Sun Mar 10 21:13:09 2013 sebastien bequignon
//

#ifndef IMAP_HH_
# define IMAP_HH_

#include "IGetProtocol.hh"
#include "SocksException.hh"
#include "Protocole.hh"

class Imap : public Protocole, public IGetProtocol
{
private:
  char buffer[512];
  std::string mail;
  std::string header;

  bool receive();
  void sendRequest(const char *format, const char *param1,
			 const char *param2);
  void sendRequest(const char *format, int param1, const char *param2);

public:
  Imap(const char * hostname, int port,
       const char * username, const char *password);
  ~Imap();
  Message *getMail(int idMail);
  int getNbMail();
  void suprMail(int idMail);
};

#endif

