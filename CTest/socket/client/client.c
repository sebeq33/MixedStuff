/*
** client.c for bequig_s in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Apr 14 18:40:52 2013 sebastien bequignon
** Last update Thu May  2 14:26:08 2013 sebastien bequignon
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

void	handle(int signum)
{
  my_puterr("Connection with server lost\n");
  if (g_fd != -1)
    {
      my_sendstr(g_fd, "/quit");
      close(g_fd);
    }
  if (signum == SIGHUP || signum == SIGINT)
    exit(0);
  else
    g_fd = -1;
}

int	recv_serv(int server)
{
  char	*line;

  if ((line = my_recv(server)) == NULL)
    return (my_puterr("Server lost\n", 0));
  my_putstr_fd(1, line);
  return (1);
}

int	recv_client(int server)
{
  char	*line;

  if ((line = my_recv_clean(0)) == NULL)
    return (my_puterr("read failed\n", 0));
  if (my_sendstr(server, line) == -1)
    return (my_puterr("Server lost\n", 0));
  if (strncmp(line, "/quit", 5) == 0)
    return (0);
  return (1);
}

void		launch_client(int server)
{
  fd_set	read;
  char		*line;
  int		cont;

  if ((line = my_recv(server)) == NULL || strlen(line) <= 2)
    {
      my_puterr("Server didn't say hello\n", 0);
      return ;
    }
  line[strlen(line) - 2] = '\0';
  printf("From server : [%s]\n", line);
  cont = 1;
  while (cont)
    {
      FD_ZERO(&read);
      FD_SET(0, &read);
      FD_SET(server, &read);
      if (select(server + 1, &read, NULL, NULL, NULL) == -1)
	{
	  my_puterr("Select failed\n");
	  return ;
	}
      if (FD_ISSET(0, &read))
	cont = recv_client(server);
      if (cont && FD_ISSET(server, &read))
	cont = recv_serv(server);
    }
}

int			main(int ac, char **av)
{
  struct sockaddr_in	sock;
  struct protoent       *prot;
  struct hostent        *host;
  int			port;

  if (ac != 3)
    return (my_puterr("usage ./client [name/ip] [port]\n"));
  if ((host = gethostbyname(av[1])) == NULL)
    return (my_puterr("Retrieve hostname failed\n"));
  if ((port = atoi(av[2])) <= 0)
    return (my_puterr("Invalid port number\n"));
  if (signal(SIGINT, &handle) == SIG_ERR ||
      signal(SIGHUP, &handle) == SIG_ERR)
    return (my_puterr("Can't handle signals\n"));
  if ((prot = getprotobyname("TCP")) == NULL)
    return (my_puterr("Can't retrieve TCP\n"));
  sock.sin_family = AF_INET;
  sock.sin_port = htons(port);
  bcopy(host->h_addr_list[0], &sock.sin_addr, sizeof(sock.sin_addr));
  if ((g_fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (my_puterr("socket failed\n"));
  if (connect(g_fd, (struct sockaddr *) &sock, sizeof(sock)) == -1)
    return (my_puterr("Function connect failed\n"));
  launch_client(g_fd);
  close(g_fd);
  return (0);
}
