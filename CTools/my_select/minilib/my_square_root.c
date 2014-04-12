/*
** my_square_root.c for my_suare_root in /home/bequig_s//piscine/jour5
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 09:52:33 2012 sebastien bequignon
** Last update Mon Oct 15 11:42:46 2012 sebastien bequignon
*/

int	my_square_root(int nb)
{
  int	i;

  i = 1;
  while (i * i != nb && !(i * i < i) && i < nb)
    i = i + 1;
  if (i * i != nb)
    return (0);
  return (i);
}
