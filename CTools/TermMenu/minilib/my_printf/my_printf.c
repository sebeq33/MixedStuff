/*
** my_prinf.c for my_prinf.c in /home/bequig_s//workspace/module-Unix/my_printf/my_prinf2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Nov 17 09:27:20 2012 sebastien bequignon
** Last update Sun Nov 18 20:54:59 2012 sebastien bequignon
*/

#include <stdarg.h>

int		my_printf(char *format, ...)
{
  int		wrote;
  va_list	va;

  va_start(va, format);
  wrote = exec(format, va);
  va_end(va);
  return (wrote);
}
