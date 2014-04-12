/*
** my_put_nbr.c for my_put_nbr in /home/bequig_s//piscine/jour3
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Wed Oct  3 19:18:07 2012 sebastien bequignon
** Last update Fri Oct 26 11:50:55 2012 sebastien bequignon
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	cpt;
  int	tmp;

  cpt = 1;
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  tmp = nb;
  while (tmp > 9)
    {
      cpt = cpt * 10;
      tmp = tmp / 10;
    }
  while (cpt > 0)
    {
      my_putchar(48 + ((nb / cpt) % 10));
      cpt = cpt / 10;
    }
}
