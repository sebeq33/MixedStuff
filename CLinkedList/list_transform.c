/*
** list_transform.c for list_transform.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Apr  9 16:44:09 2013 sebastien bequignon
** Last update Mon Apr 29 18:40:35 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

t_list		*list_transform(t_list *list, t_node *(*func)(t_node *))
{
  t_list	*new;
  t_node	*current;
  t_node	*new_node;

  if ((new = create_list()) == NULL)
    return (NULL);
  current = list->head;
  while (current)
    {
      if ((new_node = func(current)) == NULL)
	{
	  list_destroy(&new);
	  return (NULL);
	}
      list_push_back(new, new_node);
      current = current->next;
    }
  return (new);
}

t_list		*list_partition(t_list *src, t_list **accept, t_list **other,
			       int (*check)(t_node *))
{
  t_node	*current;

  if (*accept == NULL && (*accept = create_list()) == NULL)
    return (NULL);
  if (*other == NULL && (*other = create_list()) == NULL)
    return (NULL);
  current = src->head;
  while (current)
    {
      if (check(current))
	list_push_back(*accept, current);
      else
	list_push_back(*other, current);
      current = current->next;
    }
  return (*accept);
}

void		list_reverse(t_list *list)
{
  t_node	*next;
  t_node	*current;
  t_node	*tmp;

  if (!list || !list->head || !list->head->next)
    return ;
  current = list->head;
  while (current != NULL)
    {
      next = current->next;
      tmp = current->prev;
      current->prev = current->next;
      current->next = tmp;
      current = next;
    }
  tmp = list->head;
  list->head = list->tail;
  list->tail = tmp;
}
