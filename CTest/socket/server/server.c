/*
** server.c for server.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Apr 14 18:40:29 2013 sebastien bequignon
** Last update Thu May  2 13:46:38 2013 sebastien bequignon
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

static	t_server	*g_server_access = NULL;

void	close_cleanly(int signum)
{
  int	i;

  if (g_server_access == NULL)
    return ;
  i = 0;
  while (i < LIMIT_FD)
    {
      if (IS_USED(g_server_access->clients[i]))
	{
	  close(g_server_access->clients[i].fd);
	  g_server_access->clients[i].fd = -1;
	}
      i++;
    }
  if (signum == SIGINT || signum == SIGHUP)
    exit(EXIT_SUCCESS);
  else
    g_server_access = NULL;
}

int			get_new_client(t_server *server)
{
  struct sockaddr_in	client_sock;
  socklen_t		size;
  size_t		i;

  if (server->nb_connect == LIMIT_FD)
    return (0);
  i = 0;
  while (i < LIMIT_FD && IS_USED(server->clients[i]))
    i++;
  size = sizeof(client_sock);
  server->clients[i].fd = accept(server->sock, (struct sockaddr *) &client_sock, &size);
  if (server->clients[i].fd == -1)
    return (my_puterr("accept failed\n", -1));
  strcpy(server->clients[i].name, "Guest");
  server->clients[i].ip = inet_ntoa(client_sock.sin_addr);
  server->clients[i].port = ntohs(client_sock.sin_port);
  if (say_hello(&server->clients[i]) == -1)
    {
      close(server->clients[i].fd);
      server->clients[i].fd = -1;
      return (my_puterr("I can't say hello =(, i'm sad\n", -1));
    }
  printf("Connection from %s:%d\n", server->clients[i].ip, server->clients[i].port);
  server->nb_connect++;
  return (1);
}

int		work_loop(int sock)
{
  t_server	server;
  int		i;

  server.sock = sock;
  server.nb_connect = 0;
  i = 0;
  puts("0");
  while (i < LIMIT_FD)
    server.clients[i++].fd = -1;
  puts("1");
  g_server_access = &server;
  while (42)
    {
      puts("2");
      server_work(&server);
    }
  return (1);
}

int			prepare_wait_client(int fd_sock, int port)
{
  struct sockaddr_in	sock;
  int			yes;

  yes = 1;
  sock.sin_family = AF_INET;
  sock.sin_port = htons(port);
  sock.sin_addr.s_addr = INADDR_ANY;
  if (setsockopt(fd_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1
      || bind(fd_sock, (struct sockaddr *) &sock, sizeof(sock)) == -1)
    return (my_puterr("bind failed\n", 0));
  if (listen(fd_sock, LIMIT_FD) != 0)
    return (my_puterr("listen failed\n", 0));
  return (1);
}

int	main(int ac, char **av)
{
  struct protoent	*prot;
  int			port;
  int			fd;

  port = (ac != 2) ? DEFAULT_PORT : atoi(av[1]);
  if (port <= 0)
    return (my_puterr("Invalid port number\n", EXIT_FAILURE));
  if (signal(SIGINT, &close_cleanly) == SIG_ERR ||
      signal(SIGHUP, &close_cleanly) == SIG_ERR)
    return (my_puterr("Signal catcher failed\n", EXIT_FAILURE));
  if ((prot = getprotobyname("TCP")) == NULL)
    return (my_puterr("Can't retrieve TCP\n", EXIT_FAILURE));
  if ((fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (my_puterr("Function socket failed\n", EXIT_FAILURE));
  if (!prepare_wait_client(fd, port))
    {
      close(fd);
      return (EXIT_FAILURE);
    }
  work_loop(fd);
  close(fd);
  return (EXIT_SUCCESS);
}
