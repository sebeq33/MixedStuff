/*
** display.c for display.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 21 21:41:26 2012 sebastien bequignon
** Last update Fri Nov 23 00:51:50 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <term.h>
#include "my_select.h"
#include "terminal.h"

void	manage_style(t_node *list)
{
  char	*cmd;

  if (list->selected)
    {
      cmd = tgetstr("mr", NULL);
      if (cmd != NULL)
	my_putstr_fd(cmd);
    }
  if (list->underline)
    {
      cmd = tgetstr("us", NULL);
      if (cmd != NULL)
	my_putstr_fd(cmd);
    }
}

void	reset_style()
{
  char	*cmd;

  cmd = tgetstr("me", NULL);
  if (cmd != NULL)
    my_putstr_fd(cmd);
}

void	display_node(t_node *node)
{
  move_abs(node->x, node->y);
  manage_style(node);
  my_putstr_fd(node->value);
  reset_style();
}

void	display_list(t_node *list)
{
  while (list->value != NULL)
    {
      display_node(list);
      list = list->next;
    }
}
