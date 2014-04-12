/*
** manage_types.c for manage_types.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 18 19:40:46 2012 sebastien bequignon
** Last update Sun Nov 18 22:24:26 2012 sebastien bequignon
*/

#include "my_printf.h"
#include "types.h"

static t_hook_type          types[NB_TYPES] =
  {
    {'d', display_nbr},
    {'i', display_nbr},
    {'o', convert_octal},
    {'u', convert_unsigned_dec},
    {'x', convert_hexa_low},
    {'X', convert_hexa_up},
    {'c', display_unsigned_char_of_int},
    {'s', display_str},
    {'p', display_pointer_hexa},
    {'%', display_percent},
    {'b', display_binary_unsigned_char},
    {'S', convert_octal_char}
  };

int	set_type(t_query *to_fill, char *format)
{
  int	i;

  i = 0;
  while (i < NB_TYPES)
    {
      if (types[i].hook == format[0])
	{
	  to_fill->func = types[i].func;
	  to_fill->type = format[0];
	  return (1);
	}
      i++;
    }
  to_fill->type = '\0';
  return (-1);
}
