/*
** manage_env.c for manage_env.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Nov 11 11:15:06 2012 sebastien bequignon
** Last update Thu Nov 29 19:06:56 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "func_prototype.h"
#include "minishell.h"
#include "minilib/my.h"

int	count_var_lines(char **envp)
{
  int	i;

  i = 0;
  if (envp == NULL)
    return (0);
  while (envp[i] != NULL)
    i++;
  return (i);
}

char		**copy_env(char **envp)
{
  char		**new_env;
  int		i;
  int		size;

  i = 0;
  new_env = malloc((count_var_lines(envp) + 1)* sizeof(char *));
  if (new_env == NULL)
    print_exit_error(MALLOC_MSG);
  while (envp[i] != NULL)
    {
      size = my_strlen(envp[i]);
      new_env[i] = malloc((size + 1) * sizeof(char));
      if (new_env[i] == NULL)
	print_exit_error(MALLOC_MSG);
      my_strcpy(new_env[i], envp[i]);
      new_env[i][size] = '\0';
      i++;
    }
  new_env[i] = NULL;
  return (new_env);
}

int	get_env_line(char **envp, char *to_search)
{
  int	size;
  int	i;

  i = 0;
  size = my_strlen(to_search);
  while (envp[i] != NULL && my_strncmp(to_search, envp[i], size))
    i++;
  if (envp[i] == NULL)
    return (-1);
  return (i);
}
