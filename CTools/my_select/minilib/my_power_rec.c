/*
** my_power_rec.c for my_power_rec in /home/bequig_s//piscine/jour5
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Oct  5 10:40:37 2012 sebastien bequignon
** Last update Mon Nov 12 11:03:14 2012 sebastien bequignon
*/

int	my_pow(int nb, int power, int result)
{
  return (power > 1 ? my_pow(nb , power - 1, result * nb) : result);
}

int	my_power_rec(int nb, int power)
{
  return (power > 0 ? my_pow(nb , power, nb) : 1);
}
