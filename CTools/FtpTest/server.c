/*
** server.c for server.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Apr 14 18:40:29 2013 sebastien bequignon
** Last update Sun Apr 14 19:00:05 2013 sebastien bequignon
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

int	my_putstr_fd(int fd, char *str)
{
  return (write(fd, str, strlen(str)));
}

int	my_puterr(char *error)
{
  my_putstr_fd(2, error);
  return (1);
}

int	main(int ac, char **av)
{
  char			limit[4096];
  struct protoent	*prot;
  struct sockaddr_in	sock;
  int			port;
  int			fd;

  if (ac != 2)
    return (my_puterr("usage ./serveur [port]"));
  if ((port = my_getnbr(av[1])) <= 0)
    return (my_puterr("Invalid port number\n"));
  if ((prot = getprotobyname("TCP")) == NULL)
    return (my_puterr("Can't retrieve TCP\n"));
  if ((fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (my_puterr("Function socket failed"));
  sock.sin_family = AF_INET;
  sock.sin_port = htons(port);
  sock.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr *) &sock, sizeof(sock)) == -1)
    return (my_puterr("bind failed\n"));
  if (getcwd(limit, 4096) == NULL)
    return (my_puterr("Unable to retrieve current path\n"));
  listen_clients(fd, limit);
  return (0);
}
