/*
** list_default_func.c for list_default_func.c in /home/bequig_s//workspace/libmy/linked_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Apr 29 15:20:01 2013 sebastien bequignon
** Last update Mon Apr 29 19:14:16 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"

int	default_node_comparison(t_node *first, t_node *second)
{
  return (first == second);
}

int	default_data_comparison(void *first, void *second)
{
  return (first == second);
}

void	free_node_data(t_node *node)
{
  free(node->data);
}

int	strcmp_node(t_node *node, t_node *node2)
{
  return (strcmp((char *) node->data, (char *) node2->data));
}

void		list_dump(t_list *list)
{
  t_node	*current;

  if (!list)
    return ;
  current = list->head;
  while (current)
    {
      if (current->data)
	{
	  write(1, current->data, strlen((char *)current->data));
	  putchar('\n');
	}
      current = current->next;
    }
}
