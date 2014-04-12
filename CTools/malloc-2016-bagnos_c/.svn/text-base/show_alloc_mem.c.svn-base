/*
** show_alloc_mem.c for show_alloc_mem.c in /home/bequig_s//workspace/systemUnixTek2/malloc/malloc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Feb  5 14:43:12 2013 sebastien bequignon
** Last update Sat Feb  9 12:41:27 2013 sebastien bequignon
*/

#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

void		my_putstr_error(char *str)
{
  while (*str)
    write(2, str++, 1);
}

void		my_putstr(char *str)
{
  while (*str)
    if (write(1, str++, 1) < 0)
      my_putstr_error("Write failed\n");
}

void			my_put_pointer(void *ptr)
{
  unsigned long		nb;
  unsigned long		cpt;

  my_putstr("0x");
  nb = (unsigned long) ptr;
  cpt = 1;
  while (nb / cpt > 16)
    cpt = cpt * 16;
  while (cpt > 0)
    {
      if (write(1, &("0123456789abcdef")[((nb / cpt) % 16)], 1) < 0)
	my_putstr_error("Write failed\n");
      cpt = cpt / 16;
    }
}

void		my_putnbr(int nb)
{
  char		val;
  int		cpt;

  cpt = 1;
  if (nb < 0)
    {
      nb *= -1;
      write(1, "-", 1);
    }
  while (nb / cpt > 9)
    cpt = cpt * 10;
  while (cpt > 0)
    {
      val = '0' + ((nb / cpt) % 10);
      if (write(1, &val, 1) < 0)
	my_putstr_error("Write failed\n");
      cpt = cpt / 10;
    }
}

void		show_alloc_mem()
{
  t_header	*current;

  current = g_start;
  my_putstr("Break : ");
  my_put_pointer(sbrk(0));
  my_putstr("\n");
  while (current)
    {
      my_put_pointer(((char *) current + HEADER_SIZE));
      my_putstr(" - ");
      my_put_pointer(((char *) current + HEADER_SIZE + current->size));
      my_putstr(" : ");
      my_putnbr(current->size);
      my_putstr(" Octets - free ? ");
      my_putnbr(current->freed);
      my_putstr("\n");
    }
}
