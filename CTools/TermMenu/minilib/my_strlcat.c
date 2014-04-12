/*
** my_strlcat.c for my_strlcat in /home/bequig_s//piscine/jour7
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Oct  9 15:50:00 2012 sebastien bequignon
** Last update Mon Nov 12 11:11:43 2012 sebastien bequignon
*/

#include "my.h"

char	*my_strlcat(char *dest, char *src, int l)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] != '\0' && i < l - 1)
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  return (dest);
}
