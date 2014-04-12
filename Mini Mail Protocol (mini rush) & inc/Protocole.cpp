//
// Protocole.cpp for bmail in /home/bagnos_c//Tek2/System_Unix/Rush/bmail
//
// Made by caroline bagnost
// Login   <bagnos_c@epitech.net>
//
// Started on  Sat Mar  9 11:30:28 2013 caroline bagnost
// Last update Sun Mar 10 13:54:54 2013 sebastien bequignon
//

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "Protocole.hh"
#include "Pop3.hh"
#include "SocksException.hh"

Protocole::Protocole(const char * hostname, int port)
{
  struct sockaddr_in serv;
  struct hostent *host;

  if ((host = gethostbyname(hostname)) == NULL)
    throw SocksException("gethostbyname");
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    throw SocksException("socket");

  serv.sin_family = AF_INET; // ipV4
  serv.sin_port = htons(port); // network port in function of endianness
  serv.sin_addr = *((struct in_addr *) host->h_addr);
  memset(&(serv.sin_zero), '\0', 8);

  if (connect(sock, (struct sockaddr *)&serv, sizeof(serv)) < 0) // connect
    throw SocksException("connect");
}

Protocole::~Protocole()
{
  close(sock);
}
