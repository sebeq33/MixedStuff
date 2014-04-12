/*
** terminal.c for terminal.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 19 17:22:40 2012 sebastien bequignon
** Last update Fri Nov 23 16:32:43 2012 sebastien bequignon
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <term.h>
#include <fcntl.h>
#include "my_select.h"
#include "minilib/my.h"
#include "terminal.h"

int			get_size_term(int *x, int *y)
{
  struct winsize	ws;
  int			fd;

  if ((fd = open("/dev/tty", O_RDWR)) < 0 || ioctl(fd, TIOCGWINSZ, &ws) < 0)
    {
      my_putstr_error("Error while loading winsize\n");
      return (0);
    }
  close(fd);
  *x = ws.ws_col;
  *y = ws.ws_row;
  if (*x < 0 || *y < 0)
    return (0);
  return (1);
}

int	reset_getent()
{
  char	*term;

  if ((term = my_getenv("TERM")) == NULL || tgetent(0, term) != 1)
    {
      my_putstr_error("Error on tgetent, only support xterm\n");
      return (0);
    }
  return (1);
}

int	move_abs(int x, int y)
{
  char	*cap;

  cap = tgetstr("cm", NULL);
  if (cap != NULL)
    cap = tgoto(cap, x, y);
  if (cap != NULL)
    {
      my_putstr_fd(cap);
      return (1);
    }
  return (0);
}

int	clean_term()
{
  char	*cmd;

  move_abs(0, 0);
  if ((cmd = tgetstr("cd", NULL)) == NULL)
    {
      my_putstr_error("Error, while cleaning the screen\n");
      return (0);
    }
  my_putstr_fd(cmd);
  return (1);
}
