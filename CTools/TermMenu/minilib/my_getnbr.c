/*
** my_getnbr.c for my_getnbr in /home/bequig_s//piscine/jour4
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct  4 12:17:50 2012 sebastien bequignon
** Last update Fri Nov 16 10:38:56 2012 sebastien bequignon
*/

#include "my.h"

static int	signe(char *str, int start)
{
  int	i;

  i = 0;
  start = start - 1;
  while (start >= 0 && (str[start] == '+' || str[start] == '-'))
    {
      if (str[start] == '-')
	i = i + 1;
      start = start - 1;
    }
  return (!(i % 2));
}

static void	set_area(char *str, int *start, int *end)
{
  int	i;

  i = 0;
  while ((str[i] < 48 || str[i] >= 58) && i < my_strlen(str))
      i = i + 1;
  *start = i;
  while (str[i] >= 48 && str[i] < 58 && i < my_strlen(str))
    i = i + 1;
  *end = i;
}

static int	convert(char *str, int start, int end, int positif)
{
  int	cpt;
  int	to_ret;
  int	new_nb;

  cpt = 1;
  to_ret = 0;
  while (start < end)
    {
      new_nb = to_ret + (str[end - 1] - 48) * cpt;
      if (to_ret == new_nb - (str[end - 1] - 48) * cpt)
	to_ret = new_nb;
      else
	return 0;
      cpt = cpt * 10;
      end = end - 1;
    }
  return (positif ? to_ret : to_ret * -1);
}

int	my_getnbr(char *str)
{
  int	start;
  int	end;

  if (my_strlen(str) <= 0)
    return 0;
  set_area(str, &start, &end);
  return (convert(str, start, end, signe(str, start)));
}
