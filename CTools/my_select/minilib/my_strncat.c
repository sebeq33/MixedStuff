/*
** my_strncat.c for my_strncat in /home/bequig_s//piscine/jour7
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Tue Oct  9 15:50:00 2012 sebastien bequignon
** Last update Fri Oct 26 12:01:39 2012 sebastien bequignon
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int n)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] != '\0' && n > 0)
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
      n = n - 1;
    }
  return (dest);
}
