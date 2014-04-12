/*
** manage_signal.c for manage_signal.c in /home/bequig_s//workspace/module-Unix/minitalk
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 14 12:13:51 2012 sebastien bequignon
** Last update Wed Nov 14 17:04:29 2012 sebastien bequignon
*/

#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include "minitalk.h"
#include "server.h"

void		insert_char(t_client *client, char c)
{
  char          *new_str;

  client->msg_size = client->msg_size + 1;
  new_str = malloc((client->msg_size + 1) * sizeof(char));
  if (new_str == NULL)
    {
      my_putstr("Malloc failed\n");
      exit(0);
    }
  new_str[client->msg_size] = '\0';
  my_strcpy(new_str, client->msg);
  free(client->msg);
  new_str[client->msg_size - 1] = c;
  client->msg = new_str;
}

void            display_msg(t_client **client_list, t_client *client)
{
  my_putstr(client->msg);
  my_putchar('\n');
  delete_client(client_list, client->pid);
}

void		received_sig1(t_client **client_list, t_client *client)
{
  int	pid;
  int	received;

  received = SIG1_VAL;
  if (client->last_signal == SIG2_VAL)
    {
      insert_char(client, (client->c_val - SIG2_VAL) * client->sign);
      if (client->msg[client->msg_size - 1] == '\0')
	{
	  pid = client->pid;
	  display_msg(client_list, client);
	  kill(pid, SIGUSR1);
	  return ;
	}
      client->c_val = 0;
      client->sign = 0;
      received = 0;
    }
  client->last_signal = SIG1_VAL;
  client->c_val = client->c_val + received;
}

void		received_sig2(t_client *client)
{
  if (client->last_signal = SIG2_VAL && client->c_val == 0)
    client->sign = -1;
  client->c_val = client->c_val + SIG2_VAL;
  client->last_signal = SIG2_VAL;
}
