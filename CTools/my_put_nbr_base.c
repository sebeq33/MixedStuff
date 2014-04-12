/*
** my_put_nbr_base.c for my_put_nbr_base in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 25 23:15:12 2012 sebastien bequignon
** Last update Mon Dec 17 19:09:12 2012 sebastien bequignon
*/

static void	my_putnbr_base_rec(int val, char *base, int size_base)
{
  if (val > 0)
    {
      my_putnbr_base_rec(val / size_base, base, size_base);
      my_putchar(base[val % size_base]);
    }
}

void	my_put_nbr_base(int val, char *base)
{
  if (val < 0)
    {
      val *= -1;
      my_putchar('-');
    }
  if (val == 0)
    my_putchar(base[0]);
  else
    my_putnbr_base_rec(val, base, my_strlen(base));
}
