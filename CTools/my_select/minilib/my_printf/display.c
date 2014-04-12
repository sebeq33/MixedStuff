/*
** display.c for display.c in /home/bequig_s//workspace/module-Unix/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 11:57:09 2012 sebastien bequignon
** Last update Mon Nov 19 16:12:09 2012 sebastien bequignon
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "../my.h"

int	display_char(char c, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      my_putchar(c);
      i++;
    }
  return (nb);
}

int	display_binary_unsigned_char(va_list va)
{
  int	i;
  char	*bin;
  int	size;

  i = va_arg(va, int);
  if (i < 0)
    i = i * -1;
  bin = to_base(i, BASE_BIN, my_strlen(BASE_BIN), 0);
  if (bin == NULL)
    {
      my_putstr("\nError malloc");
      return (0);
    }
  size = my_strlen(bin);
  my_putstr(bin);
  free(bin);
  return (size);
}

/*
** get int in place of void * to remove warning
*/
int	display_pointer_hexa(va_list va)
{
  int	i;
  char	*bin;
  int	size;

  i = va_arg(va, int);
  if (i < 0)
    i = i * -1;
  bin = to_base(i, BASE_HEXA_LOW, my_strlen(BASE_HEXA_LOW), 0);
  if (bin == NULL)
    {
      my_putstr("\nError malloc");
      return (0);
    }
  size = my_strlen(bin);
  my_putstr(bin);
  free(bin);
  return (size);
}
