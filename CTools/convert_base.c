/*
** convert_base.c for convert_base in /home/bequig_s//piscine/jour8
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct 11 22:29:21 2012 sebastien bequignon
** Last update Thu Dec 20 19:07:34 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

int	get_nbchar(int nbr, int size_base)
{
  int	i;

  i = 0;
  while (nbr >= size_base)
    {
      nbr = nbr / size_base;
      i = i + 1;
    }
  return (i + 1);
}

int	manage_signe(int *nbr)
{
  if (*nbr < 0)
    {
      *nbr = *nbr * -1;
      return (1);
    }
  return (0);
}

char	*to_base(int nbr, char *base_to, int size_base)
{
  char	*result_char;
  int	negative;
  int	nbchar;
  int	i;

  i = 0;
  negative = manage_signe(&nbr);
  nbchar = get_nbchar(nbr, size_base) + negative;
  if ((result_char = malloc((nbchar + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (nbr >= size_base)
    {
      result_char[i] = base_to[nbr % size_base];
      nbr = nbr / size_base;
      i = i + 1;
    }
  result_char[i] = base_to[nbr];
  if (negative)
    result_char[++i] = '-';
  result_char[++i] = '\0';
  my_revstr(result_char);
  return (result_char);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	decimal;

  decimal = my_getnbr_base(nbr, base_from);
  return (to_base(decimal, base_to, my_strlen(base_to)));
}
