/*
** my_getnbr.c for my_getnbr in /home/bequig_s//piscine/jour4
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct  4 12:17:50 2012 sebastien bequignon
** Last update Sun Apr 14 17:45:32 2013 sebastien bequignon
*/

static int	convert(char *str, int end, int positif)
{
  int		res;
  int		cpt;
  int		tmp;
  int		current;

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
