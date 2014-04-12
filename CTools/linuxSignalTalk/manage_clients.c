/*
** manage_list_dir.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 31 09:33:09 2012 sebastien bequignon
** Last update Wed Nov 14 17:07:07 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include "minilib/my.h"
#include "server.h"

t_client	*get_client(t_client **client_list, int pid)
{
  t_client	*client;

  client = search_client(*client_list, pid);
  if (client == NULL)
    {
      add_to_list_end(client_list, create_client(pid));
      return (search_client(*client_list, pid));
    }
  return (client);
}

t_client	*search_client(t_client *list, int pid)
{
  while (list != NULL && list->pid != pid)
    list = list->next;
  return (list);
}

t_client	*create_client(int pid)
{
  t_client	*client;

  client = malloc(sizeof(*client));
  client->msg = malloc(2 * sizeof(char));
  if (client == NULL || client->msg == NULL)
    {
      my_putstr("Create_client : malloc failed");
      exit(0);
    }
  client->msg[0] = '\0';
  client->pid = pid;
  client->sign = 0;
  client->last_signal = 0;
  client->c_val = 0;
  client->msg_size = 0;
  client->next = NULL;
  return (client);
}

void		add_to_list_end(t_client **list, t_client *to_add)
{
  t_client	*current;

  if (*list == NULL)
    *list = to_add;
  else
    {
      current = *list;
      while (current->next != NULL)
	current = current->next;
      current->next = to_add;
    }
}

void		delete_client(t_client **list, int pid)
{
  t_client	*to_delete;
  t_client	*current;

  current = *list;
  if (*list == NULL)
    return ;
  if (current->next == NULL)
    *list = NULL;
  else
    {
      while (current->next != NULL && current->next->pid != pid)
	current = current->next;
      if (current->next != NULL)
	{
	  to_delete = current->next;
	  current->next = to_delete->next;
	  free(to_delete->msg);
	  free(to_delete);
	}
    }
}
