/*
** minisheel.c for minisheel.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 11:38:02 2012 sebastien bequignon
** Last update Fri Nov 30 18:14:23 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <signal.h>
#include "minishell.h"
#include "func_prototype.h"
#include "minilib/my.h"
#include "hook.h"

static t_hook	g_hook[NB_HOOK] =
  {
    {"exit", exit_cleanly},
    {"env", display_env},
    {"setenv", set_env},
    {"unsetenv", unset_env},
    {"cd", change_dir}
  };

void		catch_signal(int signum)
{
  my_putstr("\b\b  \n");
  my_putstr(COLOR_PROMPT);
  my_putstr(PROMPT);
  my_putstr(COLOR_DEFAULT);
}

int		special_cmd(char *cmd, char ***envp)
{
  int		i;

  i = 0;
  while (i < NB_HOOK)
    {
      if (!my_strncmp(cmd, g_hook[i].hook, my_strlen(g_hook[i].hook)))
	{
	  g_hook[i].func(cmd, envp);
	  return (1);
	}
      i++;
    }
  return (0);
}

int		main(int ac, char **av, char **envp)
{
  char		buffer[BUFFER_WIDTH + 1];

  envp = copy_env(envp);
  if (signal(SIGINT, &catch_signal) == SIG_ERR)
    print_exit_error(SIGNAL_FAIL);
  while (1)
    {
      if (read_cmd(buffer, envp))
	search_exec(buffer, &envp);
      else
	{
	  free_tab(envp);
	  return (0);
	}
    }
}
