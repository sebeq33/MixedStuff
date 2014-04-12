/*
** list_next_prev.c for list_next_prev.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Apr  3 16:24:22 2013 sebastien bequignon
** Last update Mon Apr 29 11:25:34 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

t_node		*list_next_loop(t_list *list)
{
  if (!list->current)
    return (NULL);
  if (list->current->next)
    list->current = list->current->next;
  else
    list->current = list->head;
  return (list->current);
}

t_node		*list_prev_loop(t_list *list)
{
  if (!list->current)
    return (NULL);
  if (list->current->prev)
    list->current = list->current->prev;
  else
    list->current = list->tail;
  return (list->current);
}

t_node		*list_next(t_list *list)
{
  if (!list->current)
    return (NULL);
  if (list->current->next)
    list->current = list->current->next;
  else
    return (NULL);
  return (list->current);
}

t_node		*list_prev(t_list *list)
{
  if (!list->current)
    return (NULL);
  if (list->current->prev)
    list->current = list->current->prev;
  else
    return (NULL);
  return (list->current);
}
