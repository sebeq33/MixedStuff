/*
** my_putstr_error.c for my_putstr_error.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 16 09:43:32 2012 sebastien bequignon
** Last update Mon Dec 17 17:42:56 2012 sebastien bequignon
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int	my_putstr_error(char *str)
{
  my_putstr("\033[0;31m");
  while (*str)
    write(2, str++, 1);
  my_putstr("\033[0;0m");
  return (0);
}
