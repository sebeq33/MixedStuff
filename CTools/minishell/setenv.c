/*
** setenv.c for setenv.c in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 28 10:56:14 2012 sebastien bequignon
** Last update Wed Nov 28 11:34:33 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "minishell.h"
#include "func_prototype.h"
#include "minilib/my.h"

/*
** new_env malloc ==> nb_line + 1 for {NULL} + 1 for the new var
*/
void		add_env(char *buffer, char ***envp)
{
  char		**new_env;
  int		i;
  int		size;

  i = 0;
  new_env = malloc((count_var_lines(*envp) + 2) * sizeof(char *));
  if (new_env == NULL)
    print_exit_error(MALLOC_MSG);
  while ((*envp)[i] != NULL)
    {
      size = my_strlen((*envp)[i]);
      new_env[i] = malloc((size + 1) * sizeof(char));
      if (new_env[i] == NULL)
	print_exit_error(MALLOC_MSG);
      my_strcpy(new_env[i], (*envp)[i]);
      new_env[i][size] = '\0';
      i++;
    }
  new_env[i] = create_env(buffer);
  new_env[i + 1] = NULL;
  free_tab(*envp);
  *envp = new_env;
}

int		set_env(char *buffer, char ***envp)
{
  char		**params;
  int		line;

  params = NULL;
  if ((params = prepare_parse_cmd(params, buffer)) == NULL
      || count_var_lines(params) <= 2)
    {
      free_tab(params);
      print_func_error(SETENV_BAD_SYNTAX);
      return (1);
    }
  line = get_env_line(*envp, params[1]);
  free_tab(params);
  if (line != -1)
    delete_env(envp, line);
  add_env(buffer, envp);
  return (1);
}
