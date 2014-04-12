/*
** manage_width.c for manage_width.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 18 19:36:59 2012 sebastien bequignon
** Last update Sun Nov 18 20:28:03 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my_printf.h"

int	set_width(t_query *to_fill, char *format)
{
  int	i;
  char	*nb;

  i = 0;
  while (format[i] >= '0' && format[i] <= '9')
    i++;
  if (i > 0)
    {
      nb = get_part_of_string(format, i);
      to_fill->precision = my_getnbr(nb);
      free(nb);
    }
  return (i);
}
