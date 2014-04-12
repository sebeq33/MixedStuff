/*
** my_revstr.c for my_revstr in /home/bequig_s//piscine/jour6
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Oct  8 11:55:12 2012 sebastien bequignon
** Last update Mon Nov 12 12:33:50 2012 sebastien bequignon
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	size;

  i = 0;
  size = my_strlen(str);
  while (i < size / 2)
    {
      my_swapchar(&str[i], &str[size - i - 1]);
      i = i + 1;
    }
  return (str);
}
