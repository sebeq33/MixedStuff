/*
** my_printf.c for my_printf.c in /home/bequig_s//workspace/module-Unix/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 12 12:19:52 2012 sebastien bequignon
** Last update Fri Nov 16 23:33:46 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

static t_hook          converters[NB_CONVERTER] =
  {
    {'d', display_nbr},
    {'o', convert_octal},
    {'u', convert_unsigned_dec},
    {'x', convert_hexa_low},
    {'X', convert_hexa_up},
    {'c', display_unsigned_char_of_int},
    {'s', display_str},
    {'p', display_pointer_in_hexa},
    {'%', display_percent},
    {'b', display_binary_unsigned_char},
    {'S', display_percent},
    {NULL}
  }

int		my_printf(char *format, ...)
{
  int		read;
  va_list	va;

  read = 0;
  va_start(va);
  read = procede(format, &va);
  va_end(va);
  free(copy);
  return (read);
}
