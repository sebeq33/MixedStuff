/*
** my_putstr.c for my_putstr in /home/bequig_s//piscine/jour4
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct  4 10:05:15 2012 sebastien bequignon
** Last update Fri Oct 26 11:51:34 2012 sebastien bequignon
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
