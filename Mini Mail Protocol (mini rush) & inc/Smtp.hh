//
// Smtp.hh for Smtp.hh in /home/bequig_s//workspace/rush/bmail
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Mar 10 18:34:13 2013 sebastien bequignon
// Last update Sun Mar 10 18:45:49 2013 sebastien bequignon
//

#ifndef SMTP_H_
# define SMTP_H_

#include "Protocole.hh"

class Smtp : Protocole
{
private:
  char buffer[512];
  std::string mail;

  void sendRequest(const char *format, const char * param, const char *param2);
  bool receive();

public:
  Smtp(const char * hostname, int port);
  ~Smtp();
  void sendMail(const char *from, const char * to,
		const char *subject, const char *message);
};

#endif /* !SMTP_H_ */
