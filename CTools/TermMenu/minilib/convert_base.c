/*
** convert_base.c for convert_base in /home/bequig_s//piscine/jour8
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct 11 22:29:21 2012 sebastien bequignon
** Last update Fri Oct 26 11:48:04 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

int	manage_signe(char *nbr, int remove_minus)
{
  int	i;

  if (remove_minus)
    {
      if (nbr[0] == '-')
	{
	  i = 0;
	  while (nbr[i] != '\0')
	    {
	      nbr[i] = nbr[i + 1];
	      i = i + 1;
	    }
	  return (0);
	}
      return (1);
    }
  i = my_strlen(nbr) - 1;
  while (i >= 0)
    {
      nbr[i + 1] = nbr[i];
      i = i - 1;
    }
  nbr[0] = '-';
  return (0);
}

int	to_decimal(char *nbr, char *base_from, int size_nbr, int size_base)
{
  int	i;
  int	j;
  int	result;

  i = 0;
  while (nbr[i] != '\0')
    {
      j = 0;
      while (nbr[i] != base_from[j])
	{
	  if (base_from[j] == '\0')
	    return 0;
	  j = j + 1;
	}
      result = result + j * my_power_rec(size_base, size_nbr - 1);
      size_nbr = size_nbr - 1;
      i = i + 1;
    }
  return (result);
}

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

char	*to_base(int nbr, char *base_to, int size_base, int negative)
{
  char	*result_char;
  int	nbchar;
  int	i;

  i = 0;
  nbchar = get_nbchar(nbr, size_base);
  result_char = malloc((nbchar + negative + 1) * sizeof(char));
  while (nbr >= size_base)
    {
      result_char[i] = base_to[nbr % size_base];
      nbr = nbr / size_base;
      i = i + 1;
    }
  result_char[i] = base_to[nbr];
  result_char[i + 1] = '\0';
  my_revstr(result_char);
  return (result_char);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int decimal;
  char *result;
  int positive;

  positive = manage_signe(nbr, 1);
  decimal = to_decimal(nbr, base_from, my_strlen(nbr), my_strlen(base_from));
  result = to_base(decimal, base_to, my_strlen(base_to), !positive);
  if (!positive)
    manage_signe(result, 0);
  return (result);
}
