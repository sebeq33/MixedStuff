/*
** my_strcat.c for my_strcat in /home/bequig_s//piscine/jour7
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Tue Oct  9 15:50:00 2012 sebastien bequignon
** Last update Fri Oct 26 11:54:54 2012 sebastien bequignon
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
