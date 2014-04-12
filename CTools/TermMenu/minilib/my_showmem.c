/*
** my_showmem.c for my_showmem in /home/bequig_s//piscine/jour6
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Oct 16 17:02:14 2012 sebastien bequignon
** Last update Fri Nov 16 10:42:20 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

static void	zero_to_complete(int nb, int size)
{
  int	i;

  i = 0;
  while (nb > 9)
    {
      nb = nb / 16;
      i = i + 1;
    }
  i = i + 1;
  while (i < size)
    {
      my_putchar('0');
      i = i + 1;
    }
}

static void	display_address(int *current_address)
{
  zero_to_complete(*current_address, 8);
  my_putstr(to_base(*current_address, "0123456789abcdef", 16, 0));
  *current_address = *current_address + 16;
}

static void	display_char_hexa(char *str, int size)
{
  int	i;
  char	*nbr_tmp;
  char	current_char[2];

  i = 0;
  current_char[1] = '\0';
  while (i < 16 && i < size)
    {
      zero_to_complete((int) str[i], 2);
      nbr_tmp = to_base((int) str[i], "0123456789abcdef", 16, 0);
      my_putstr(nbr_tmp);
      my_showstr(current_char);
      i = i + 1;
      if (!(i % 2))
	my_putchar(' ');
      free(nbr_tmp);
    }
}

static void	display_string16(char *str)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if (str[i] <= '~' && str[i] >= 32)
	{
	  my_putchar(str[i]);
	}
      else
	{
	  my_putchar('.');
	}
      i = i + 1;
    }
}

int	my_showmem(char *str, int size)
{
  int	i;
  int	current_address;

  i = 0;
  current_address = 0;
  while (i < size)
    {
      display_address(&current_address);
      my_putstr(": ");
      display_char_hexa(&str[i], size - i);
      my_putchar(' ');
      display_string16(&str[i]);
      my_putchar('\n');
      i = i + 16;
    }
  return (0);
}
