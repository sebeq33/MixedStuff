/*
** my_swap_char.c for my_swap_char.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 12 12:32:34 2012 sebastien bequignon
** Last update Mon Nov 12 12:33:42 2012 sebastien bequignon
*/

#include "my.h"

void	my_swapchar(char *a, char *b)
{
  char	c;

  c = *a;
  *a = *b;
  *b = c;
}
