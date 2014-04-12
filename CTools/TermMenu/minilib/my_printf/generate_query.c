/*
** generate_query.c for generate_query.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Nov 17 09:53:02 2012 sebastien bequignon
** Last update Sun Nov 18 22:23:54 2012 sebastien bequignon
*/

#include "my_printf.h"

int		generate_query(t_query *to_fill, char *format)
{
  int		i;
  int		res;

  i = 0;
  res = set_flags(to_fill, &format[i]);
  if (res == -1)
    return (res);
  i += res;
  res = set_width(to_fill, &format[i]);
  if (res == -1)
    return (res);
  i += res;
  res = set_precision(to_fill, &format[i]);
  if (res == -1)
    return (res);
  i += res;
  res = set_type(to_fill, &format[i]);
  if (res == -1)
    return (res);
  else
    return (i + res);
}
