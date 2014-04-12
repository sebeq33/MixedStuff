/*
** list_pull.c for list_pull.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Apr  3 16:04:27 2013 sebastien bequignon
** Last update Mon Apr 29 18:38:31 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

t_list		*list_delete_node(t_list *list, t_node *to_delete)
{
  if (to_delete == list->tail)
    list->tail = to_delete->prev;
  if (to_delete == list->head)
    list->head = to_delete->next;
  if (to_delete == list->current)
    list->current = to_delete->next;
  if (to_delete->next)
    to_delete->next->prev = to_delete->prev;
  if (to_delete->prev)
    to_delete->prev->next = to_delete->next;
  free(to_delete);
  list->nb_elem--;
  return (list);
}

t_list		*list_pop_back(t_list *list)
{
  if (list->tail)
    list_delete_node(list, list->tail);
  return (list);
}

t_list		*list_pop_front(t_list *list)
{
  if (list->head)
    list_delete_node(list, list->head);
  return (list);
}

t_list		*list_pop_current(t_list *list)
{
  if (list->current)
    list_delete_node(list, list->current);
  return (list);
}

t_list		*list_check_pop_node(t_list *list, t_node *to_delete)
{
  t_node	*tmp;

  if (to_delete != NULL && list_search(list, to_delete) != NULL)
    list_delete_node(list, to_delete);
  else
    return (NULL);
  return (list);
}
