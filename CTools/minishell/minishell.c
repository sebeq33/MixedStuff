/*
** minisheel.c for minisheel.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 11:38:02 2012 sebastien bequignon
** Last update Wed Nov 28 11:57:39 2012 sebastien bequignon
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

void		catch_signal()
{
  my_putstr("\b\b  \n");
  my_putstr(COLOR_PROMPT);
  my_putstr(PROMPT);
  my_putstr(COLOR_DEFAULT);
}

void		my_exec(char **params, char **envp)
{
  if (params != NULL)
    {
      if (!search_exec(params, envp))
	{
	  if (params[0] == NULL)
	    print_file_error("{NULL} ", CMD_NOT_FOUND);
	  else
	    print_file_error(params[0], CMD_NOT_FOUND);
	  free_tab(params);
	}
    }
}

int		special_cmd(char *buffer, char ***envp)
{
  int		i;

  i = 0;
  while (i < NB_HOOK)
    {
      if (!my_strncmp(buffer, g_hook[i].hook, my_strlen(g_hook[i].hook)))
	return (g_hook[i].func(buffer, envp));
      i++;
    }
  return (0);
}

int		main(int ac, char **av, char **envp)
{
  char		buffer[BUFFER_WIDTH + 1];
  char		**func_params;
  int		size;

  envp = copy_env(envp);
  signal(SIGINT, &catch_signal);
  while(1)
    {
      if (read_cmd(buffer, envp))
	{
	  my_epur_str(buffer);
	  size = my_strlen(buffer);
	  if (!size)
	    {
	      my_putchar('\n');
	      exit_cleanly(buffer, &envp);
	    }
	  if (buffer[size - 1] != '\n')
	    my_putchar('\n');
	  if (!special_cmd(buffer, &envp))
	    {
	      func_params = prepare_parse_cmd(func_params, buffer);
	      my_exec(func_params, envp);
	    }
	}
    }
}
