/*
** list_position.c for list_position.c in /home/bequig_s//workspace/libmy/linked_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Apr 29 11:18:13 2013 sebastien bequignon
** Last update Mon Apr 29 18:55:52 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

t_node		*list_start(t_list *list)
{
  if (!list)
    return (NULL);
  list->current = list->head;
  return (list->current);
}

t_node		*list_end(t_list *list)
{
  if (!list)
    return (NULL);
  list->current = list->tail;
  return (list->current);
}

t_node		*list_index(t_list *list, size_t i)
{
  t_node	*tmp;
  int		next;

  if (list == NULL)
    return (NULL);
  next = i < list->nb_elem / 2 ? 1 : 0;
  tmp = (next) ? list->head : list->tail;
  if (next)
    i--;
  else
    i = list->nb_elem - i;
  while (tmp != NULL && i > 0)
    {
      tmp = next ? tmp->next : tmp->prev;
      i--;
    }
  return (tmp);
}
