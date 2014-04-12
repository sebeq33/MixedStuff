/*
** manage_path.c for manage_path.c in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 31 10:43:26 2012 sebastien bequignon
** Last update Wed Nov 28 11:33:30 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include "func_prototype.h"
#include "minishell.h"
#include "minilib/my.h"

char		*get_part_string(char *to_copy, int nb_char)
{
  char		*str;

  if ((str = malloc((nb_char + 1) * sizeof(char))) == NULL)
    print_exit_error(MALLOC_MSG);
  my_strncpy(str, to_copy, nb_char);
  str[nb_char] = '\0';
  return (str);
}

char		*get_file_path(char *exec_name, char *dir_path, int path_size)
{
  char		*f_path;
  int		size;
  int		have_slash;

  have_slash = exec_name[0] == '/';
  size = path_size + my_strlen(exec_name) + 1 + !have_slash;
  f_path = malloc(size * sizeof(char));
  if (f_path == NULL)
    print_exit_error(MALLOC_MSG);
  my_strncpy(f_path, dir_path, path_size);
  if (!have_slash)
    {
      f_path[path_size] = '/';
      path_size++;
    }
  f_path[path_size] = '\0';
  my_strcat(f_path, exec_name);
  f_path[size - 1] = '\0';
  return (f_path);
}

char	*create_env(char *str)
{
  int	space;
  int	start;
  char	*env;
  int	i;

  i = 0;
  space = 1;
  while (str[i] != '\0' && str[i - 1] != ' ')
    i = i + 1;
  start = i;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ')
	{
	  str[i] = space ? '=' : ':';
	  space = 0;
	}
      i++;
    }
  if ((env = malloc(my_strlen(str) * sizeof(char))) == NULL)
    print_exit_error(MALLOC_MSG);
  env = my_strncpy(env, &str[start], i - start);
  env[i - start] = '\0';
  return (env);
}
