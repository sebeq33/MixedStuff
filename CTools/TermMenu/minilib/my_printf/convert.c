/*
** convert.c for convert.c in /home/bequig_s/workspace/module-Unix/my_printf/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 18 20:38:46 2012 sebastien bequignon
** Last update Mon Nov 19 10:36:34 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"
#include "../my.h"

int	convert_octal(va_list va)
{
  int	i;
  char	*bin;
  int	size;

  i = va_arg(va, int);
  if (i < 0)
    i = i * -1;
  bin = to_base(i, BASE_OCTAL, my_strlen(BASE_OCTAL), 0);
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

int	convert_unsigned_dec(va_list va)
{
  int	i;

  i = va_arg(va, int);
  if (i < 0)
    i *= -1;
  my_put_nbr(i);
  return (my_intlen(i));
}

int	convert_hexa_low(va_list va)
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

int	convert_hexa_up(va_list va)
{
  int	i;
  char	*bin;
  int	size;

  i = va_arg(va, int);
  if (i < 0)
    i = i * -1;
  bin = to_base(i, BASE_HEXA_UP, my_strlen(BASE_HEXA_UP), 0);
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

int	convert_octal_char(va_list va)
{
  int	i;
  char	*bin;
  int	size;

  i = va_arg(va, int);
  if (i < 0)
    i = i * -1;
  bin = to_base(i, BASE_OCTAL, my_strlen(BASE_OCTAL), 0);
  if (bin == NULL)
    {
      my_putstr("\nError malloc");
      return (0);
    }
  size = my_strlen(bin);
  my_putchar('\\');
  my_putstr(bin);
  free(bin);
  return (size);
}
