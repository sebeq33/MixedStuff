//
// Imap.cpp for bmail in /home/bagnos_c//Tek2/System_Unix/Rush/bmail
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Sat Mar  9 17:15:03 2013 caroline bagnost
// Last update Sun Mar 10 20:20:11 2013 sebastien bequignon
//

#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include "Imap.hh"

Imap::Imap(const char * hostname, int port,
    const char * username, const char *password)
: Protocole(hostname, port)
{
  if (this->receive() < 0)
    throw SocksException("recv");
  sendRequest("LOGIN", username, password);
  sendRequest("SELECT", "inbox", "");
}

Imap::~Imap()
{
  sendRequest("CLOSE", "", "");
  sendRequest("LOGOUT", "", "");
}

void Imap::sendRequest(const char *format, const char *param1,
		       const char *param2)
{
  std::string cmp;
  const char *command;

  cmp = "a001 " ;
  cmp += format;
  if (param1[0] != '\0')
    {
      cmp += " ";
      cmp += param1;
    }
  if (param2[0] != '\0')
    {
      cmp += " ";
      cmp += param2;
    }
  cmp += "\r\n";
  command = cmp.c_str();
  //std::cout << "SEND : " << command << std::endl;
  if (send(sock, command, strlen(command), 0) == -1) // send username
    throw SocksException("send");
  if (!this->receive())
    {
      cmp = command;
      cmp += " -> ";
      cmp += buffer;
      throw SocksException(cmp.c_str());
    }
}

void Imap::sendRequest(const char *format, int param1, const char *param2)
{
  std::stringstream cmp;
  const char *command;

  cmp << "a001 " << format << " " << param1 << " " << param2 << "\r\n";
  command = cmp.str().c_str();
  //std::cout << "SEND : " << command << std::endl;
  if (send(sock, command, strlen(command), 0) == -1) // send username
    throw SocksException("send");
  if (!this->receive())
    {
      cmp.clear();
      cmp.str("");
      cmp << command << " -> " << buffer;
      throw SocksException(cmp.str().c_str());
    }
}

bool Imap::receive()
{
  std::string cmp;
  int	ret;

  if ((ret = recv(sock, buffer, LEN, 0)) < 0)
    return (false);
  buffer[ret] = '\0';
  cmp = buffer;
  //std::cout << "RECEIVED : " << cmp << std::endl;
  if (cmp.empty())
    return (false);
  cmp = cmp.substr(5, 8);
  return (cmp != "BAD" && cmp != "NO " && cmp != "NO");
}

Message *Imap::getMail(int idMail)
{
  int ret;
  int size = 0;

  mail.clear();
  sendRequest("FETCH", idMail, "BODY[HEADER]");
  ret = strlen(buffer);
  sscanf(buffer, "\n\n* %*d FETCH (BODY[HEADER] {%d}\r\n%*s", &size);
  header = buffer;
  size -= ret;
  while (size > 0)
    {
      ret = recv(sock, buffer, LEN, 0); //read from socket
      buffer[ret] = 0;
      header += buffer;
      size -= ret;
    }
  sendRequest("FETCH", idMail, "BODY[TEXT]");
  ret = strlen(buffer);
  sscanf(buffer, "\n\n* %*d FETCH (BODY[TEXT] {%d}\r\n%*s", &size);
  mail = buffer;
  size -= ret;
  while (size > 0)
    {
      ret = recv(sock, buffer, LEN, 0); //read from socket
      buffer[ret] = 0;
      mail += buffer;
      size -= ret;
    }
    return (new Message(mail, header));
}

int Imap::getNbMail()
{
  int nb = 0;

  sendRequest("SELECT", "inbox", "");
  sscanf(buffer, "\n\n* %d EXISTS\r\n%*s", &nb);
  return (nb);
}

void Imap::suprMail(int idMail)
{
  sendRequest("STORE", idMail, "+FLAGS (\\Deleted)");
}
