/*
** my_strdup.c for my_strdup in /home/bequig_s//piscine/jour8
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 10 11:35:50 2012 sebastien bequignon
** Last update Tue Dec 11 10:08:56 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dest;

  dest = malloc(my_strlen(src) * sizeof(char));
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
