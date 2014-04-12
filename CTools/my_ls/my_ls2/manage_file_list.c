/*
** manage_file_list.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov  2 08:52:12 2012 sebastien bequignon
** Last update Sun Nov  4 16:09:25 2012 sebastien bequignon
*/

#include "headers/file.h"
#include "stdlib.h"

void		add_file_to_list_end(t_file **list, t_file *to_add)
{
  t_file	*current;

  if (*list == NULL)
    *list = to_add;
  else
    {
      current = *list;
      while (current->next != NULL)
        current = current->next;
      current->next = to_add;
    }
}

void            delete_first_file_node(t_file **list)
{
  t_file	*to_delete;

  to_delete = *list;
  *list = to_delete->next;
  if (to_delete->symb_link != NULL)
    free(to_delete->symb_link);
  free(to_delete->path);
  free(to_delete);
}
