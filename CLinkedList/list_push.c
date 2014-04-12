/*
** list_push.c for list_push.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Apr  3 15:59:43 2013 sebastien bequignon
** Last update Mon Apr 29 19:32:22 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

int		list_push_back(t_list *list, void *data)
{
  return (list_push_front_node(list, default_node(data)));
}

int		list_push_front(t_list *list, void *data)
{
  return (list_push_back_node(list, default_node(data)));
}

int		list_push_front_node(t_list *list, t_node *elem)
{
  if (list == NULL || elem == NULL)
    return (0);
  if (list->head == NULL)
    {
      list->tail = elem;
      list->head = elem;
      list->current = elem;
    }
  else
    {
      list->head->prev = elem;
      elem->next = list->head;
      list->head = elem;
    }
  list->nb_elem++;
  return (1);
}

int		list_push_back_node(t_list *list, t_node *elem)
{
  if (elem == NULL)
    return (0);
  if (list->tail == NULL)
    {
      list->tail = elem;
      list->head = elem;
      list->current = elem;
    }
  else
    {
      list->tail->next = elem;
      elem->prev = list->tail;
      list->tail = elem;
    }
  list->nb_elem++;
  return (1);
}

t_list		*list_push_sort(t_list *list, t_node *elem,
				int (*comp)(t_node *, t_node *))
{
  t_node	*current;

  if ((current = list->head) == NULL || comp(current, elem) > 0)
    {
      list_push_front_node(list, elem);
      return (list);
    }
  while (current->next && comp(current->next, elem) < 0)
    current = current->next;
  if (!current->next)
      list->tail = elem;
  elem->next = current->next;
  elem->prev = current;
  if (current->next)
    current->next->prev = elem;
  current->next = elem;
  list->nb_elem++;
  return (list);
}

