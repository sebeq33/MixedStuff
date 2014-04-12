/*
** list_apply.c for list_apply.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Apr  8 16:38:31 2013 sebastien bequignon
** Last update Mon Apr 29 19:05:34 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

/*
** apply a function
*/
t_list		*list_iter(t_list *list, void (*func)(t_node *))
{
  t_node	*current;

  if (!list)
    return (NULL);
  current = list->head;
  while (current != NULL)
    {
      func(current);
      current = current->next;
    }
  return (list);
}

/*
** apply a function on each using a param
*/
t_list		*list_iter2(t_list *list,
			    void (*func)(t_node *, void *), void *param)
{
  t_node	*current;

  current = list->head;
  while (current != NULL)
    {
      func(current, param);
      current = current->next;
    }
  return (list);
}

/*
** check a condition for all node of the list
*/
int		list_forall(t_list *list, int (*func)(t_node *))
{
  t_node	*current;

  current = list->head;
  while (current != NULL)
    {
      if (func(current))
	return (1);
      current = current->next;
    }
  return (0);
}

void		swap_with_next(t_list *list, t_node *current)
{
  t_node	*next;

  next = current->next;
  if (current = list->head)
    list->head = next;
  if (next = list->tail)
    list->tail = next->prev;
  next->prev = current->prev;
  current->prev = next;
  current->next = next->next;
  next->next = current;
}

t_list		*list_sort(t_list *list, int (*func)(t_node *, t_node *))
{
  t_node	*current;
  int		cont;

  if (list == NULL || list->head == NULL)
    return (NULL);
  cont = 1;
  while (cont)
    {
      cont = 0;
      current = list->head;
      while (current != NULL && current->next != NULL)
	{
	  if (func(current, current->next))
	    {
	      swap_with_next(list, current);
	      cont = 1;
	    }
	  current = current->next;
	}
    }
  return (list);
}
