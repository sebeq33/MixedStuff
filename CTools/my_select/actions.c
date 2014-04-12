/*
** actions.c for actions.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov 22 15:42:00 2012 sebastien bequignon
** Last update Thu Nov 22 23:21:30 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my_select.h"
#include "terminal.h"
#include "manage_actions.h"

void		move_down(int nb_move)
{
  int		i;
  t_node	*prev_selected;

  i = 0;
  prev_selected = get_underline();
  prev_selected->underline = 0;
  display_node(prev_selected);
  while (i < nb_move)
    {
      if (prev_selected->next->value != NULL)
	i++;
      prev_selected = prev_selected->next;
    }
  prev_selected->underline = 1;
  display_node(prev_selected);
}

void		move_up(int nb_move)
{
  int		i;
  t_node	*prev_selected;

  i = 0;
  prev_selected = get_underline();
  prev_selected->underline = 0;
  display_node(prev_selected);
  while (i < nb_move)
    {
      if (prev_selected->prev->value != NULL)
	i++;
      prev_selected = prev_selected->prev;
    }
  prev_selected->underline = 1;
  display_node(prev_selected);
}

void		move_left()
{
  t_node	*list;
  int		x_pos;
  int		y_pos;

  list = get_underline();
  list->underline = 0;
  display_node(list);
  x_pos = list->x;
  y_pos = list->y;
  list = list->prev;
  while (list->y != y_pos || list->value == NULL)
    list = list->prev;
  list->underline = 1;
  display_node(list);
}

void		move_right()
{
    t_node	*list;
  int		x_pos;
  int		y_pos;

  list = get_underline();
  list->underline = 0;
  display_node(list);
  x_pos = list->x;
  y_pos = list->y;
  list = list->next;
  while (list->y != y_pos || list->value == NULL)
    list = list->next;
  list->underline = 1;
  display_node(list);
}
