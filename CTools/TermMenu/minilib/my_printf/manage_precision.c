/*
** manage_precision.c for manage_precision.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 18 19:14:07 2012 sebastien bequignon
** Last update Mon Nov 19 16:11:47 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my_printf.h"
#include "../my.h"

int	set_precision(t_query *to_fill, char *format)
{
  int	i;
  char	*nb;

  i = 0;
  if (format[0] == '.')
    {
      while (format[i] >= '0' && format[i] <= '9')
	i++;
      if (i > 0)
	{
	  nb = get_part_of_string(format, i);
	  to_fill->precision = my_getnbr(nb);
	  free(nb);
	  return (i);
	}
      return (-1);
    }
  return (i);
}
