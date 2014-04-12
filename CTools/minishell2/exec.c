/*
** cmd.c for cmd.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 12:26:25 2012 sebastien bequignon
** Last update Fri Nov 30 17:31:22 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "minilib/my.h"
#include "minishell.h"
#include "func_prototype.h"

int		exec_forked(char *full_path, char **params, char **envp)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    {
      print_exit_error("fork()");
      exit(0);
    }
  if (pid == 0)
    {
      if (execve(full_path, params, envp) == -1)
	print_file_error(full_path, PERM_DENIED);
      free(full_path);
      exit(0);
    }
  wait(0);
  if (full_path != NULL)
    free(full_path);
  return (1);
}

char		*test_path_exec(char *exec_name, char *path, int path_size)
{
  char		*full_path;

  full_path = get_file_path(exec_name, path, path_size);
  if (access(full_path, X_OK) == -1)
    {
      free(full_path);
      return (NULL);
    }
  return (full_path);
}

int		test_all_paths_exec(char **params, char **envp, char *paths)
{
  int		start;
  int		nb_char;
  char		*full_path;

  start = 0;
  if (paths != NULL)
    while (start == 0 || paths[start - 1] != '\0')
      {
	nb_char = 0;
	while (paths[start] != '\0' && paths[start] != ':')
	  {
	    start++;
	    nb_char++;
	  }
	full_path = test_path_exec(params[0], &paths[start - nb_char], nb_char);
	if (full_path != NULL)
	  return (exec_forked(full_path, params, envp));
	start++;
      }
  if ((full_path = test_path_exec(params[0], "./", 2)) == NULL)
    if ((full_path = test_path_exec(params[0], "", 0)) == NULL)
      return (0);
  return (exec_forked(full_path, params, envp));
}

void		search_exec(char *buffer, char ***envp)
{
  char		**params;
  char		*cmd;
  int		path_line;
  int		i;
  char		*path;

  if ((path_line = get_env_line(*envp, "PATH=")) == -1)
    path = NULL;
  else
    path = &(*envp)[path_line][5];
  i = 0;
  while ((cmd = get_cmd(buffer, i)) != NULL)
    {
      if (cmd[0] != '\0' && !special_cmd(cmd, envp))
	{
	  params = parse_cmd(cmd);
	  if (!test_all_paths_exec(params, *envp, path))
	    print_file_error(params[0], CMD_NOT_FOUND);
	  free_tab(params);
	}
      free(cmd);
      i++;
    }
}

