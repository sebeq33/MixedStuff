/*
** main.c for main.c in /home/bequig_s//workspace/module-Unix/my_select/lib
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov 20 21:26:17 2012 sebastien bequignon
** Last update Mon Dec 17 20:21:01 2012 sebastien bequignon
*/

#include "my.h"

int	main(int ac, char **av)
{
  char	*res;

  res = convert_base("-05236", "123456789", "123456789");
  my_putstr(res);
}
