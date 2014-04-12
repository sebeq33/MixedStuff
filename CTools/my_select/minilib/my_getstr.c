/*
** int_to_string.c for int_to_string.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 10:19:12 2012 sebastien bequignon
** Last update Sun Nov 18 10:10:20 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

char	*my_getstr(int val)
{
  char *result;
  int	size;
  int	cpt;
  int	i;

  i = 0;
  cpt = 1;
  size = my_intlen(val);
  if ((result = malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (i < size)
    {
      result[i] = (val / cpt % 10) + 48;
      cpt = cpt * 10;
      i++;
    }
  result[i] = '\0';
  return (result);
}
