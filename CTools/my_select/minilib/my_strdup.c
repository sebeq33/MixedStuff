/*
** my_strdup.c for my_strdup in /home/bequig_s//piscine/jour8
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 10 11:35:50 2012 sebastien bequignon
** Last update Mon Nov 12 11:53:03 2012 sebastien bequignon
*/
#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;

  dest = malloc(sizeof(src));
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
