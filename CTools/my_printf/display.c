/*
** display.c for display.c in /home/bequig_s//workspace/module-Unix/my_printf
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 11:57:09 2012 sebastien bequignon
** Last update Fri Nov 16 22:17:37 2012 sebastien bequignon
*/

#include <stdarg.h>

int	display_nbr(char *format, va_list *va)
{
  int	nb;

  nb = va_arg(*va, int);
  my_put_nbr(nb);
  return (my_intlen(nb));
}

int	display_str(char *format, va_list *va)
{
  char	*str;

  str = va_arg(*va, char *);
  return (my_putstr(str));
}

int			display_unsigned_char_of_int(char *format, va_list *va)
{
  unsigned char		c;

  c = (unsigned char) va_arg(*va, unsigned char);
  my_putchar(c);
  return (1);
}

int	display_percent(char *format, va_list *va)
{
  my_putchar('%');
  return (1);
}
