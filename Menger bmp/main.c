/*
** main.c for main.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex01
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 11:44:18 2013 sebastien bequignon
** Last update Wed Jan  9 15:39:30 2013 sebastien bequignon
*/

#include <stdio.h>

void	menger(int, int, int, int);

int	convert(char *str, int end, int positif)
{
  int	res;
  int	cpt;
  int	tmp;
  int	current;

  cpt = 1;
  res = 0;
  while (--end >= 0)
    {
      current = (str[end] - '0') * cpt;
      tmp = res + current;
      if (res == tmp - current)
        res = tmp;
      else
        return (0);
      cpt = cpt * 10;
    }
  return (positif ? res : res * -1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	start;
  int	end;
  int	positif;

  i = 0;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i = i + 1;
  start = i;
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    i = i + 1;
  end = i;
  i = start - 1;
  positif = 1;
  while (i >= 0 && (str[i] == '+' || str[i] == '-'))
    if (str[i--] == '-')
      positif = !positif;
  return (convert(&str[start], end - start, positif));
}

int	main(int ac, char **av)
{
  if (ac > 2)
    menger(my_getnbr(av[1]), my_getnbr(av[2]), 0, 0);
  return (0);
}
