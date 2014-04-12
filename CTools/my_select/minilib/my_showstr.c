/*
** my_showstr.c for my_show_str in /home/bequig_s//piscine/jour6
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Oct 16 09:42:38 2012 sebastien bequignon
** Last update Mon Nov 12 12:08:02 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

int	my_showstr(char *str)
{
  int	i;
  char	*nbr_tmp;
  int	value_of_char;
  char	*base_16;

  i = 0;
  base_16 = "0123456789ABCDEF";
  while (str[i] != '\0')
    {
      if (str[i] <= '~' && str[i] >= 32)
	{
	  my_putchar(str[i]);
	}
      else
	{
	  value_of_char = str[i];
	  nbr_tmp = to_base(value_of_char, base_16, 16, 0);
	  my_putstr(nbr_tmp);
	  free(nbr_tmp);
	}
      i = i + 1;
    }
  return (0);
}
