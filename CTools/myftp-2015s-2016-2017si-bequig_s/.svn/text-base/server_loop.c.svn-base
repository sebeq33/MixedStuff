/*
** server_loop.c for server_loop.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Apr 11 00:01:50 2013 sebastien bequignon
** Last update Sat Apr 13 23:48:31 2013 sebastien bequignon
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
#include "get_next_line.h"
#include "server.h"

int	say_hello(int client_fd, char *client_ip)
{
  if (my_putstr_fd(client_fd, "Hello '") == -1 ||
      my_putstr_fd(client_fd, client_ip) == -1 ||
      my_putstr_fd(client_fd, "'\n") == -1)
    return (-1);
  return (0);
}

int	deal_with_client(int client_fd, char *limit)
{
  char	*line;
  int	cont;

  cont = 1;
  while (cont)
    {
      if ((line = get_next_line(client_fd)) == NULL)
	return (-1);
      printf("RECEIVED [%s]\n", line);
      if (strcasecmp(line, "quit") == 0)
	{
	  my_putstr_fd(client_fd, "bye");
	  cont = 0;
	}
      else if (execute_command(client_fd, line, limit) == 0)
	cont = 0;
      free(line);
    }
  return (1);
}

void	new_client_manager(int client_fd, char *client_ip,
			 int client_port, char *limit)
{
  pid_t			pid;

  printf("Connection from \t%s:%d\n", client_ip, client_port);
  if ((pid = fork()) == -1)
    {
      my_puterr("fork failed\n");
      close(client_fd);
      return ;
    }
  if (pid == 0)
    {
      if (say_hello(client_fd, client_ip) < 0)
	my_puterr("I Can't say hello T-T, i'm sad\n");
      else if (deal_with_client(client_fd, limit) == -1)
	printf("Connection lost with \t%s:%d\n", client_ip, client_port);
      printf("Disconnected from	%s:%d\n", client_ip, client_port);
      close(client_fd);
      exit(EXIT_SUCCESS);
    }
  close(client_fd);
}

void			listen_clients(int sock, char *limit)
{
  struct sockaddr_in	client_sock;
  socklen_t		size;
  int			client;

  while (42)
    {
      if (listen(sock, 42) == 0)
	{
	  size = sizeof(client_sock);
	  client = accept(sock, (struct sockaddr *) &client_sock, &size);
	  if (client != -1)
	    new_client_manager(client,
			       inet_ntoa(client_sock.sin_addr),
			       ntohs(client_sock.sin_port),
			       limit);
	  else
	    my_puterr("accept failed\n");
	}
    }
}
