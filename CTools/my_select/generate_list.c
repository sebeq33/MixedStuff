/*
** generate_list.c for generate_list.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 19 18:08:22 2012 sebastien bequignon
** Last update Fri Nov 23 16:47:55 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my_select.h"

t_node		*create_node(char *value)
{
  t_node	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->value = value;
  new->y = 0;
  new->x = 0;
  new->size = value == NULL ? 0 : my_strlen(value);
  new->selected = 0;
  new->underline = 0;
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

void		add_to_list(t_node **list, t_node *to_add)
{
  t_node	*current;

  if (*list == NULL)
    *list = to_add;
  else
    {
      current = *list;
      if (my_strcmp_alpha(current->value, to_add->value) > 0)
	{
	  to_add->next = current;
	  *list = to_add;
	}
      else
	{
	  while (current->next != NULL &&
		 my_strcmp_alpha(current->next->value, to_add->value) < 0)
	    current = current->next;
	  to_add->next = current->next;
	  current->next = to_add;
	}
    }
}

void		delete_node(t_node **list, t_node **node)
{
  t_node	*to_delete;

  if (*node == NULL || (*node)->value == NULL)
    return ;
  to_delete = *node;
  if (*list == *node)
    {
      *list = to_delete->next;
    }
  else
    *node = to_delete->next;
  to_delete->prev->next = to_delete->next;
  to_delete->next->prev = to_delete->prev;
  free(to_delete);
}

t_node		*generate_list(int ac, char **av)
{
  int		i;
  t_node	*list;
  t_node	*current;

  i = 0;
  list = NULL;
  while (i < ac)
    {
      add_to_list(&list, create_node(av[i]));
      i++;
    }
  current = list;
  while (current->next != NULL)
    {
      current->next->prev = current;
      current = current->next;
    }
  current->next = create_node(NULL);
  current->next->prev = current;
  current->next->next = list;
  list->prev = current->next;
  return (list);
}
