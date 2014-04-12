/*
** manage_list_dir.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 31 09:33:09 2012 sebastien bequignon
** Last update Sun Nov  4 22:12:41 2012 sebastien bequignon
*/

#include "headers/my_ls.h"
#include "headers/func_prototype.h"
#include "minilib/my.h"
#include <stdlib.h>
#include <stdio.h>

t_list		*create_dir_node(void *data)
{
  t_list	*node;

  node = malloc(sizeof(*node));
  if (node == NULL)
    {
      perror("Create_node_dir : malloc failed");
      exit(0);
    }
  node->data = data;
  node->next = NULL;
  return (node);
}

t_list		*create_node_copy(char *data)
{
  t_list	*node;
  char		*cpy_of_str;

  node = malloc(sizeof(*node));
  if (node != NULL)
    {
      cpy_of_str = get_file_path(data, "");
      node->data = (void *) cpy_of_str;
      node->next = NULL;
      return (node);
    }
  perror("Create_node_dir_copy() : malloc failed");
  exit(0);
}

void		add_dir_to_list_end(t_list **list, t_list *to_add)
{
  t_list	*current;

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

void		delete_first_dir_node(t_list **list)
{
  t_list	*to_delete;

  to_delete = *list;
  *list = to_delete->next;
  free(to_delete->data);
  free(to_delete);
}
