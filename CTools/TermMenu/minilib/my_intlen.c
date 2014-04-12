/*
** my_intlen.c for my_intlen.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 09:39:39 2012 sebastien bequignon
** Last update Fri Nov 16 10:15:45 2012 sebastien bequignon
*/

int	my_intlen(int val)
{
  int	i;

  i = 0;
  while (val > 0)
    {
      val = val / 10;
      i = i + 1;
    }
  return (i);
}
