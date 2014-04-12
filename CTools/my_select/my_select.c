/*
** my_select.c for my_select.c in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 19 16:55:15 2012 sebastien bequignon
** Last update Fri Nov 23 16:12:23 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include "my_select.h"
#include "terminal.h"
#include "execute.h"
#include "generate_list.h"

t_node			*g_list;
static struct termios	termcap_save;

void		exit_cleanly(int quit)
{
  if (quit == SIGINT)
    clean_term();
  if (!reset_attr(&termcap_save))
    my_putstr_error("Error while reset terminal attributes, type \"reset\"\n");
  while (g_list->value != NULL)
    delete_node(&g_list, &g_list);
  free(g_list);
  if (quit == SIGINT)
    exit(0);
}

int			save_set_attr()
{
  struct termios	mod;
  char			*cmd;

  if (tcgetattr(0, &termcap_save) == -1 || tcgetattr(0, &mod) == -1)
    return (0);
  if (!set_tty())
    return (0);
  cmd = tgetstr("vi", NULL);
  if (cmd == NULL)
    return (0);
  my_putstr_fd(cmd);
  mod.c_lflag &= ~(ICANON | ECHO);
  mod.c_cc[VMIN] = 1;
  if (tcsetattr(0, TCSANOW, &mod) == -1)
    return (0);
  return (1);
}

int		reset_attr(struct termios *backup)
{
  char		*cmd;

  if (!close_tty())
    return (0);
  cmd = tgetstr("ve", NULL);
  if (cmd == NULL)
    return (0);
  my_putstr_fd(cmd);
  if (tcsetattr(0, TCSANOW, backup) == -1)
    return (0);
  return (1);
}

int			main(int ac, char **av)
{
  if (ac < 2)
    {
      my_putstr_error("Usage : ./my_select list1 { list2 list3 ... }\n");
      return (0);
    }
  if (signal(SIGWINCH, resize) == SIG_ERR ||
      signal(SIGINT, exit_cleanly) == SIG_ERR)
    {
      my_putstr_error("Error, while loading signal handler\n");
      return (0);
    }
  if (!reset_getent() || !save_set_attr())
    {
      my_putstr_error("Error, while retrieve/changing terminal capacities\n");
      return (0);
    }
  if ((g_list = generate_list(ac - 1, &av[1])) != NULL)
    execute();
  else
    my_putstr_error("Error, while loading list\n");
  exit_cleanly(0);
  return (0);
}
