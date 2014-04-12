/*
** my_strstr.c for my_strstr in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 14:45:20 2012 sebastien bequignon
** Last update Fri Oct 26 11:57:31 2012 sebastien bequignon
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (str[j + i] == to_find[j] && str[j] != '\0')
	{
	  if (j == my_strlen(to_find) - 1)
	    return (&str[i]);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}
