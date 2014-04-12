/*
** update_list.c for update_list.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov 20 11:16:08 2012 sebastien bequignon
** Last update Fri Nov 23 12:35:59 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my_select.h"

int	get_size_of_bigger(t_node *list)
{
  int	bigger;

  bigger = 0;
  while (list->value != NULL)
    {
      if (bigger < list->size)
	bigger = list->size;
      list = list->next;
    }
  return (bigger);
}

int	set_values(t_node *list, int max_x, int max_y, int size_bigger)
{
  int	current_y;
  int	current_x;

  current_y = 0;
  current_x = 0;
  while (list->value != NULL)
    {
      list->y = current_y;
      list->x = current_x;
      if (current_y >= max_y - 1)
	{
	  current_y = 0;
	  current_x += size_bigger + NB_SPACES;
	}
      else
	current_y++;
      if (current_x + list->size - 1 >= max_x)
	return (0);
      list = list->next;
    }
  return (1);
}

int	update_list(t_node *list)
{
  int	x;
  int	y;
  int	bigger;

  clean_term();
   if (!get_size_term(&x, &y))
    return (0);
   bigger = get_size_of_bigger(list);
   return (set_values(list, x, y, bigger));
}
