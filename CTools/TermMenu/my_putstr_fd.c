/*
** my_putstr.c for my_putstr in /home/bequig_s//piscine/jour4
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct  4 10:05:15 2012 sebastien bequignon
** Last update Fri Nov 23 12:37:30 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <fcntl.h>
#include "minilib/my.h"

static int fd;

int	set_tty()
{
  if ((fd = open("/dev/tty" , O_WRONLY)) == -1)
    return (0);
  return (1);
}

int	close_tty()
{
  if ((fd = close(fd)) == -1)
    return (0);
  return (1);
}

void	my_putstr_fd(char *str)
{
  if (str == NULL)
    my_putstr("{NULL}");
  else
    write(fd, str, my_strlen(str));
}
