/*
** server_loop.c for server_loop.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Apr 11 00:01:50 2013 sebastien bequignon
** Last update Thu May  2 14:14:07 2013 sebastien bequignon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"

int	say_hello(t_client *client)
{
  if (my_sendstr(client->fd, "Hello '") == -1 ||
      my_sendstr(client->fd, client->ip) == -1 ||
      my_sendstr(client->fd, " ") == -1 ||
      my_sendstr(client->fd, client->name) == -1 ||
      my_sendstr(client->fd, "'\n") == -1)
    return (-1);
  return (0);
}

int		send_msg_chan(t_server *server, int nb, char *buff)
{
  int		i;

  i = 0;
  while (i < LIMIT_FD)
    {
      if (i != nb && IS_USED(server->clients[i])
	  && my_sendstr(server->clients[i].fd, buff) == -1)
	{
	  close(server->clients[i].fd);
	  server->clients[i].fd = -1;
	}
      i++;
    }
  return (1);
}

int		client_work(t_server *server, int i)
{
  char		*buffer;

  if ((buffer = my_recv(server->clients[i].fd)) == NULL)
    return (-1);
  if (strlen(buffer) == 0)
    return (1);
  if (strncmp(buffer, "/quit", 5) == 0)
    return (-1);
  return (send_msg_chan(server, i, buffer));

}

void		check_all_clients(t_server *server, fd_set *read)
{
  int	i;

  i = 0;
  while (i < LIMIT_FD)
    {
      if (server->clients[i].fd != -1 &&
	  FD_ISSET(server->clients[i].fd, read) &&
	  client_work(server, i) == -1)
	{
	  close(server->clients[i].fd);
	  server->clients[i].fd = -1;
	}
      i++;
    }
}

void			server_work(t_server *server)
{
  fd_set		read;
  int			max;
  int			i;

  i = 0;
  max = server->sock;
  FD_ZERO(&read);
  FD_SET(server->sock, &read);
  while (i < LIMIT_FD)
    {
      if (server->clients[i].fd > max)
	max = server->clients[i].fd;
      if (server->clients[i].fd != -1)
	FD_SET(server->clients[i].fd, &read);
      i++;
    }
  if (max == -1 || select(max + 1, &read, NULL, NULL, NULL) == -1)
    return ;
  if (FD_ISSET(server->sock, &read) && get_new_client(server) <= 0)
    my_puterr("Can't get another client\n", 0);
  else
    check_all_clients(server, &read);
}

