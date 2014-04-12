/*
** change_dir.c for change_dir.c in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 28 10:52:01 2012 sebastien bequignon
** Last update Fri Nov 30 12:26:55 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include "func_prototype.h"
#include "minilib/my.h"
#include "minishell.h"

int		go_to_home(char **envp)
{
  int		result;
  int		line;
  char		*home;

  line = get_env_line(envp, "HOME=");
  if (line != -1)
    {
      home = get_part_string(&envp[line][5], my_strlen(envp[line]) - 5);
      result = chdir(home);
      free(home);
    }
  else
    {
      print_file_error("{$HOME}", ENV_NOT_FOUND);
      result = -1;
    }
  return (result);
}

void		change_dir(char *buffer, char ***env)
{
  char		**func_params;
  char		**envp;

  envp = *env;
  func_params = NULL;
  if ((func_params = parse_cmd(buffer)) != NULL)
    {
      if (func_params[1] == NULL || !my_strcmp(func_params[1], "~"))
	{
	  if (go_to_home(envp) == -1)
	    print_file_error(func_params[1], FILE_NOT_FOUND);
	}
      else if (chdir(func_params[1]) == -1)
	print_file_error(func_params[1], FILE_NOT_FOUND);
      free_tab(func_params);
    }
}
