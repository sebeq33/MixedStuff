/*
** flags.c for flags.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Nov 17 10:39:33 2012 sebastien bequignon
** Last update Sun Nov 18 20:20:57 2012 sebastien bequignon
*/

#include "my_printf.h"

int	display_sign(t_query *t_fill)
{
  t_fill->display_sign = 1;
}

int	space(t_query *t_fill)
{
  t_fill->space = 1;
}

int	right_padded(t_query *t_fill)
{
  t_fill->align = right;
}

int	alternate_form(t_query *t_fill)
{
  t_fill->alternate_form = 1;
}

int	zero_padded(t_query *t_fill)
{
  t_fill->zero_padded = 1;
}
