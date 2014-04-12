/*
** list_search.c for list_search.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Apr  3 16:41:15 2013 sebastien bequignon
** Last update Mon Apr 29 19:30:43 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"


t_node		*list_search(t_list *list, void *data)
{
  return (list_search_data(list, data, default_data_comparison));
}

t_node		*list_search_node(t_list *list, t_node *to_search)
{
  return (list_search_node_func(list, to_search, default_node_comparison));
}

t_node		*list_search_node_func(t_list *list, t_node *node,
				  int (*comp)(t_node *, t_node *))
{
  t_node	*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (comp(tmp, node))
	return (node);
      tmp = tmp->next;
    }
  return (NULL);
}

t_node		*list_search_data(t_list *list, void *data,
				  int (*comp)(void *, void *))
{
  t_node	*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (comp(tmp->data, data))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

