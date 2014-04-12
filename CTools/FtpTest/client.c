/*
** client.c for bequig_s in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Apr 14 18:40:52 2013 sebastien bequignon
** Last update Sun Apr 14 20:55:23 2013 sebastien bequignon
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
#include <signal.h>
#include "client.h"

static int	g_fd = -1;

int	my_putstr_fd(int fd, char *str)
{
  return (write(fd, str, strlen(str)));
}

int	my_puterr(char *error)
{
  my_putstr_fd(2, error);
  return (1);
}

void	handle(int signum)
{
  (void) signum;

  my_puterr("Connection with server lost\n");
  if (g_fd != -1)
    close(g_fd);
  exit(0);
}

int			main(int ac, char **av)
{
  struct sockaddr_in	sock;
  struct protoent	*prot;
  struct hostent	*host;
  int			port;

  if (ac != 3)
    return (my_puterr("usage ./client [name/ip] [port]\n"));
  if ((host = gethostbyname(av[1])) == NULL)
    return (my_puterr("Retrieve hostname failed\n"));
  if ((port = my_getnbr(av[2])) <= 0)
    return (my_puterr("Invalid port number\n"));
  if (signal(SIGPIPE, &handle) == SIG_ERR)
    return (my_puterr("Can't handle pipe signals\n"));
  if ((prot = getprotobyname("TCP")) == NULL)
    return (my_puterr("Can't retrieve TCP\n"));
  sock.sin_family = AF_INET;
  sock.sin_port = htons(port);
  bcopy(host->h_addr_list[0], &sock.sin_addr, sizeof(sock.sin_addr));
  if ((g_fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (my_puterr("socket failed\n"));
  if (connect(g_fd, (struct sockaddr *) &sock, sizeof(sock)) == -1)
    return (my_puterr("Unable to reach server\n"));
  launch_client(g_fd);
  close(g_fd);
  return (0);
}
