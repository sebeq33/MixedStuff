/*
** manage_flags.c for manage_flags.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Nov 17 10:20:34 2012 sebastien bequignon
** Last update Sun Nov 18 22:18:29 2012 sebastien bequignon
*/

#include "my_printf.h"
#include "flags.h"

static t_hook           flags[NB_FLAGS] =
  {
    {'+', display_sign},
    {' ', space},
    {'-', right_padded},
    {'#', alternate_form},
    {'0', zero_padded}
  };

int             set_flags(t_query *to_fill, char *format)
{
  int		i;
  int		j;
  _Bool		flag_found;

  i = 0;
  flag_found = 1;
  while (format[i] != '\0' && flag_found)
    {
      j = 0;
      flag_found = 0;
      while (j < NB_FLAGS && !flag_found)
	{
	  if (format[i] == flags[j].hook)
	    {
	      flags[j].func(to_fill);
	      flag_found = 1;
	    }
	  j = j + 1;
	}
      if (flag_found)
	i = i + 1;
    }
  return (i);
}
