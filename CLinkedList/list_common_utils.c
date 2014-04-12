/*
** list_common_utils.c for list_common_utils.c in /home/bequig_s//workspace/libmy/linked_list
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Apr 27 21:28:02 2013 sebastien bequignon
** Last update Mon Apr 29 18:22:53 2013 sebastien bequignon
*/

#include "list.h"

int	list_is_empty(t_list *list)
{
  return (!list || list->nb_elem == 0);
}

size_t	list_size(t_list *list)
{
  return (list ? list->nb_elem : 0);
}
