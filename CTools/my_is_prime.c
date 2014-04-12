/*
** my_is_prime.c for my_is_prime in /home/bequig_s//piscine/jour5
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 22:46:17 2012 sebastien bequignon
** Last update Mon Oct 15 11:37:29 2012 sebastien bequignon
*/

int     my_sqrt(int nb)
{
  int   i;

  i = 1;
  while (i * i != nb && !(i * i < i) && i < nb)
    i = i + 1;
  return (i);
}

int	my_is_prime(int nb)
{
  int	i;
  int	end;

  end = my_sqrt(nb);
  if (nb % 2 == 0)
    return 0;
  i = 3;
  while (i < end)
    {
      if (!(nb % i))
	return 0;
      i = i + 2;
    }
  return (1);
}
