/*
** my_is_prime.c for my_is_prime in /home/bequig_s//piscine/jour5
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 22:46:17 2012 sebastien bequignon
** Last update Fri Oct 26 11:50:05 2012 sebastien bequignon
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  while (!my_is_prime(nb))
    nb = nb + 1;
  return (nb);
}
