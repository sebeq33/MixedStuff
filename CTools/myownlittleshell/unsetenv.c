/*
** unsetenv.c for unsetenv.c in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 28 10:54:30 2012 sebastien bequignon
** Last update Fri Nov 30 17:21:10 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "minishell.h"
#include "func_prototype.h"
#include "minilib/my.h"

void	delete_env(char ***envp, int line_to_supr)
{
  char		**new_env;
  int		i;
  int		j;
  int		size;

  i = 0;
  j = 0;
  if ((new_env = malloc((count_var_lines(*envp)) * sizeof(char *))) == NULL)
    print_exit_error(MALLOC_MSG);
  while ((*envp)[i] != NULL)
    {
      if (i != line_to_supr)
	{
	  size = my_strlen((*envp)[i]);
	  if ((new_env[j] = malloc((size + 1) * sizeof(char))) == NULL)
	    print_exit_error(MALLOC_MSG);
	  my_strcpy(new_env[j], (*envp)[i]);
	  new_env[j][size] = '\0';
	  j++;
	}
      i++;
    }
  new_env[j] = NULL;
  free_tab(*envp);
  *envp = new_env;
}

void		unset_env(char *buffer, char ***envp)
{
  int		line;
  char		**params;

  params = NULL;
  if ((params = parse_cmd(buffer)) != NULL)
    {
      if (count_var_lines(params) <= 1)
	print_func_error(UNSETENV_BAD_SYNTAX);
      else if (my_strcmp(params[1], "*") == 0)
	{
	  while ((*envp)[0] != NULL)
	    delete_env(envp, 0);
	}
      else
	{
	  line = get_env_line(*envp, params[1]);
	  if (line == -1)
	    print_func_error(ENV_NOT_FOUND);
	  else
	    delete_env(envp, line);
	}
      free_tab(params);
    }
}
