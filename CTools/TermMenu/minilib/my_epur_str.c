/*
** epur_str.c for epur_str in /exam//rendu/ex_5
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Oct 27 10:33:50 2012 sebastien bequignon
** Last update Fri Nov 16 10:40:14 2012 sebastien bequignon
*/

#include "my.h"

static int	to_delete_char(char c)
{
  return (c == ' ' || c == '\t' || c == '\v');
}

static int	the_end(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!to_delete_char(str[i]))
	return (0);
      i = i + 1;
    }
  return (1);
}

static void	erase(char *str, int i)
{
  int	size;

  size = my_strlen(str);
  while (str[i + 1] != '\0')
    {
      str[i] = str[i + 1];
      i = i + 1;
    }
  str[size - 1] ='\0';
}

char	*my_epur_str(char *str)
{
  int	i;
  int	keep;

  i = 0;
  keep = 0;
  while (str[i] != '\0')
    {
      if ((!keep || the_end(&str[i])) && to_delete_char(str[i]))
	{
	  while (to_delete_char(str[i]))
	    erase(str, i);
	}
      else if (to_delete_char(str[i]))
	{
	  str[i] = ' ';
	  keep = 0;
	}
      else
	keep = 1;
      i++;
    }
  return (str);
}
