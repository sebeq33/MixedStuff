/*
** manage_actions.c for manage_actions.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov 22 09:49:39 2012 sebastien bequignon
** Last update Fri Nov 23 16:47:00 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my_select.h"

t_node		*get_underline()
{
  t_node	*list;

  list = g_list;
  while (list->value != NULL)
    {
      if (list->underline)
	return (list);
      list = list->next;
    }
  return (list);
}

void		toggle_select()
{
  t_node	*to_select;

  to_select = get_underline();
  to_select->selected = !to_select->selected;
  display_node(to_select);
}

void		delete_underline()
{
  t_node	*to_delete;

  to_delete = get_underline();
  if (to_delete->next->value != NULL)
    to_delete->next->underline = 1;
  else
    to_delete->next->next->underline = 1;
  delete_node(&g_list, &to_delete);
  clean_term();
  update_list(g_list);
  display_list(g_list);
}

int	manage_actions(char *input, int can_edit)
{
  if (input[0] == 27 && input[1] == '[' && can_edit)
    {
      if (input[2] == 'B')
  	move_down(1);
      else if (input[2] == 'A')
  	move_up(1);
      else if (input[2] == 'C')
      	move_right(1);
      else if (input[2] == 'D')
      	move_left(1);
      else if (input[2] == '3' && input[3] == '~')
      	delete_underline();
    }
  else
    {
      if (input[0] == '\n')
	return (0);
      if (can_edit && input[0] == ' ')
	toggle_select();
    }
  return (1);
}
