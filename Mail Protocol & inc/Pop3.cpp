//
// Pop3.cpp for bmail in /home/bagnos_c//Tek2/System_Unix/Rush/bmail
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Sat Mar  9 17:15:15 2013 caroline bagnost
// Last update Sun Mar 10 20:20:08 2013 sebastien bequignon
//

#include <sstream>
#include <string>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "Pop3.hh"
#include "SocksException.hh"

Pop3::Pop3(const char * hostname, int port,
    const char * username, const char *password)
  : Protocole(hostname, port)
{
  if (!this->receive())
    throw SocksException("recv");
  sendRequest("USER", username);
  sendRequest("PASS", password);
}

Pop3::~Pop3()
{
  sendRequest("QUIT", "");
}

void Pop3::sendRequest(const char *format, const char * param)
{
  std::string cmp(format);
  const char *command;

  if (param[0] != '\0')
    {
      cmp += " ";
      cmp += param;
    }
  cmp += "\r\n";
  command = cmp.c_str();
  // std::cout << "SEND : " << command << std::endl;
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

void Pop3::sendRequest(const char *format, int param)
{
  std::stringstream cmp;
  const char *command;

  cmp << format;
  cmp << " ";
  cmp << param;
  cmp << "\r\n";
  command = cmp.str().c_str();
  // std::cout << "SEND : " << command << std::endl;
  if (send(sock, command, strlen(command), 0) < 0) // send username
    throw SocksException("send");
  if (!this->receive())
    throw SocksException(command);
}

bool Pop3::receive()
{
  std::string cmp;
  int ret;

  if ((ret = recv(sock, buffer, LEN, 0)) < 0)
    return (false);
  buffer[ret] = '\0';
  cmp = buffer;
  // std::cout << "RECEIVED : " << cmp << std::endl;
  cmp = cmp.substr(0, 4);
  return (cmp != "-ERR");
}

Message *Pop3::getMail(int idMail)
{
  int size = 0;
  int ret;

  mail.clear();

  sendRequest("LIST", idMail);
  sscanf(buffer, "+OK %*d %d", &size);
  sendRequest("RETR", idMail);
  sscanf(buffer, "+OK %d %*s", &size);
  while (size > 0)
    {
      ret = recv(sock, buffer, LEN, 0); //read from socket
      buffer[ret] = 0;
      mail += buffer;
      size -= ret;
    }
  return (new Message(mail));
}

int Pop3::getNbMail()
{
  int nb = 0;

  sendRequest("STAT", "");
  sscanf(buffer, "+OK %d", &nb);
  return (nb);
}

void Pop3::suprMail(int idMail)
{
  sendRequest("DELE", idMail);
}
