/*
** chk_error.c for chk_error.c in /home/bequig_s//workspace/libmy
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Dec 19 18:45:15 2012 sebastien bequignon
** Last update Wed Dec 19 19:03:15 2012 sebastien bequignon
*/

#include <stdlib.h>

int	check_error(int result, char *error, int need_exit)
{
  if (!result)
    {
      if (error != NULL)
	{
	  my_putstr_error(error);
	  write(2, "\n", 1);
	}
      if (need_exit)
	exit(0);
      return (0);
    }
  return (1);
}
