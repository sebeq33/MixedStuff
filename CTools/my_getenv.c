/*
** my_getenv.c for my_getenv.c in /home/bequig_s//workspace
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 19 15:01:42 2012 sebastien bequignon
** Last update Tue Nov 20 21:13:31 2012 sebastien bequignon
*/

#include <stdlib.h>

extern char **environ;

char	*my_getenv(char	*searched_var)
{
  int	i;
  int	size_var;

  if (environ == NULL || environ[0] == NULL)
    return (NULL);
  i = 0;
  size_var = my_strlen(searched_var) - 1;
  while (environ[i] != NULL)
    {
      if (my_strncmp(environ[i], searched_var, size_var) == 0)
	return (&environ[i][size_var + 2]);
      i++;
    }
  return (NULL);
}

