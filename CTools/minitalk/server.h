/*
** server.h for server.h in /home/bequig_s//workspace/module-Unix/minitalk
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov 13 16:32:09 2012 sebastien bequignon
** Last update Wed Nov 14 14:20:38 2012 sebastien bequignon
*/

#ifndef SERVER_H_
# define SERVER_H_

typedef struct s_client
{
  int	pid;
  char	last_signal;
  char	c_val;
  int	msg_size;
  int	sign;
  char	*msg;
  struct s_client *next;
} t_client;

typedef struct sigaction t_sig;

void		insert_char(t_client *client, char c);
void		display_msg(t_client **client_list, t_client *client);
void		received_sig1(t_client **client_list, t_client *client);
void		received_sig2(t_client *client);
t_client	*create_client(int pid);
t_client	*get_client(t_client **client_list, int pid);
t_client	*search_client(t_client *list, int pid);
void		add_new_client(t_client **list, int pid);
void		add_to_list_end(t_client **list, t_client *to_add);
void		delete_client(t_client **list, int pid);

#endif /* !SERVER_H_ */
