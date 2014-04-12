/*
** server.h for server.h in /home/bequig_s//workspace/test_perso/socket
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Apr 30 15:02:35 2013 sebastien bequignon
** Last update Thu May  2 12:10:26 2013 sebastien bequignon
*/

#ifndef SERVER_H_
# define SERVER_H_

# define DEFAULT_PORT		(4242)
# define LIMIT_FD		(1024)
# define IS_USED(client)	(client.fd != -1)

typedef struct	s_client
{
  int		fd;
  char		name[256];
  char		*ip;
  int		port;
}		t_client;

typedef struct	s_server
{
  t_client	clients[LIMIT_FD];
  int		nb_connect;
  int		sock;
}		t_server;

char		*my_recv(int fd);

#endif /* !SERVER_H_ */
