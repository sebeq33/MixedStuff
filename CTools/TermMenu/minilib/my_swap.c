/*
** my_swap.c for my_swap in /home/bequig_s//piscine/jour4
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct  4 09:58:53 2012 sebastien bequignon
** Last update Tue Oct  9 11:03:58 2012 sebastien bequignon
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
