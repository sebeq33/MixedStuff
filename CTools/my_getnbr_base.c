/*
** my_getnbr_base.c for my_getnbr_base in /home/bequig_s//piscine/jour4
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct  4 12:17:50 2012 sebastien bequignon
** Last update Wed Dec 19 18:51:20 2012 sebastien bequignon
*/

#include "my.h"

static int	get_nbr_in_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i])
    {
      if (base[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

static int	convert(char *str, char *base, int end, int positif)
{
  int		res;
  int		cpt;
  int		current;
  int		nb;
  int		size_base;

  cpt = 1;
  res = 0;
  size_base = my_strlen(base);
  while (--end >= 0)
    {
      current = get_nbr_in_base(str[end], base) * cpt;
      nb = res + current;
      if (res == nb - current)
  	res = nb;
      else
  	return (0);
      cpt = cpt * size_base;
    }
  return (positif ? res : res * -1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	start;
  int	end;
  int	positif;

  start = 0;
  while (str[start] != '\0' && get_nbr_in_base(str[start], base) == -1)
    start++;
  if (str[start] == '\0')
    return (0);
  end = start;
  while (str[end] != '\0' && get_nbr_in_base(str[start], base) != -1)
    end++;
  i = start - 1;
  positif = 1;
  while (i >= 0 && (str[i] == '+' || str[i] == '-'))
    if (str[i--] == '-')
      positif = !positif;
  return (convert(&str[start], base, end - start, positif));
}
