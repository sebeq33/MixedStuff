/*
** my_new_epur.c for my_new_epur.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Dec 11 15:13:19 2012 sebastien bequignon
** Last update Thu Mar  7 15:32:29 2013 sebastien bequignon
*/

#include "my.h"

static int	is_sep(char c)
{
  return (c == ' ' || c == '\t' || c == '\v');
}

char	*my_epur_str(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (is_sep(str[i]))
    i++;
  while (str[i] != '\0')
    {
      while (is_sep(str[i]) && is_sep(str[i + 1]))
	i++;
      if (is_sep(str[i]))
	{
	  str[j++] = ' ';
	  i++;
	}
      while (!is_sep(str[i]) && str[i] != '\0')
	str[j++] = str[i++];
    }
  while (is_sep(str[j - 1]))
    j--;
  str[j] = '\0';
  return (str);
}

