/*
** my_strdup.c for my_strdup in /home/bequig_s//piscine/jour8
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Wed Oct 10 11:35:50 2012 sebastien bequignon
** Last update Sun Nov  4 21:45:51 2012 sebastien bequignon
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;

  dest = malloc(sizeof(src)); 
  my_strcpy(dest, src);
  return (dest);
}
