/*
** my_putstr_error.c for my_putstr_error.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 09:43:32 2012 sebastien bequignon
** Last update Fri Nov 16 10:16:23 2012 sebastien bequignon
*/

#include <unistd.h>
#include "my.h"

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  my_putstr("\033[0;31m");
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
  my_putstr("\033[0;0m");
  return (i);
}
