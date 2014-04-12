/*
** list.c for list.c in /home/bequig_s//workspace/libmy/chained_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar 28 12:20:35 2013 sebastien bequignon
** Last update Mon Apr 29 15:19:20 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "list.h"

t_list		*create_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  list->nb_elem = 0;
  return (list);
}

t_list		*list_clean(t_list *list)
{
  while (list->head != NULL)
    list_delete_node(list, list->head);
  return (list);
}

void		list_destroy(t_list **list)
{
  if (*list == NULL)
    return ;
  list_clean(*list);
  free(*list);
  *list = NULL;
}

void		list_destroy_free_data(t_list **list)
{
  if (*list)
    {
      list_iter(*list, &free_node_data);
      list_destroy(list);
    }
}
