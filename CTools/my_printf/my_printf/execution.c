/*
** execution.c for execution.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Nov 17 09:55:49 2012 sebastien bequignon
** Last update Sun Nov 18 22:48:16 2012 sebastien bequignon
*/

#include <stdarg.h>
#include "my_printf.h"

void		reset_query(t_query *to_reset)
{
  to_reset->nb_param = 0;
  to_reset->display_sign = 0;
  to_reset->space = 0;
  to_reset->align = 0;
  to_reset->alternate_form = 0;
  to_reset->zero_padded = 0;
  to_reset->width = 0;
  to_reset->precision = 0;
  to_reset->type = 0;
}

int		exec_query(t_query *query, va_list va)
{
  if (query->alternate_form || query->type == 'p')
    my_putstr("0x");
  if (query->width > 0 && query->align == left)
    display_char(query->zero_padded ? '0': ' ', query->width);
  return (query->func(va));
}

int		exec(char *format, va_list va)
{
  int		i;
  int		wrote;
  t_query	query;
  int		move;

  i = 0;
  move = 0;
  wrote = 0;
  while (format[i] != '\0')
    {
      reset_query(&query);
      if (format[i] == '%')
	move = generate_query(&query, &format[i + 1]);
      if (move > 0 && query.type != '\0')
	{
	  wrote += exec_query(&query, va);
	  i = i + move;
	}
      else
	my_putchar(format[i]);
      wrote++;
      i = i + 1;
    }
  return (wrote);
}
