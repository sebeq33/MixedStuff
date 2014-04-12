/*
** display_common.c for display_common.c in /home/bequig_s//workspace/module-Unix/my_printf/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 18 20:30:45 2012 sebastien bequignon
** Last update Sun Nov 18 20:42:02 2012 sebastien bequignon
*/

#include <stdarg.h>

int     display_percent(va_list va)
{
  my_putchar('%');
  return (1);
}

int	display_nbr(va_list va)
{
  int	nb;

  nb = va_arg(va, int);
  my_put_nbr(nb);
  return (my_intlen(nb));
}

int	display_str(va_list va)
{
  char	*str;

  str = va_arg(va, char *);
  my_putstr(str);
  return (my_strlen(str));
}

int	display_unsigned_char_of_int(va_list va)
{
  int	c;

  c = va_arg(va, int);
  my_putchar(c);
  return (1);
}

