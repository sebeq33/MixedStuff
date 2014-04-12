/*
** server_path.c for server_path.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Apr 12 10:40:51 2013 sebastien bequignon
** Last update Sat Apr 13 23:51:08 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

char		*get_file_path(char *d_name)
{
  char		*f_path;
  int		size;
  int		path_size;
  int		have_slash;
  char		dir_path[4096];

  if (getcwd(dir_path, 4096) == NULL)
    return (NULL);
  path_size = strlen(dir_path);
  have_slash = dir_path[path_size - 1] == '/';
  size = path_size + strlen(d_name) + 1 + !have_slash;
  if ((f_path = malloc(size * sizeof(char))) == NULL)
    return (NULL);
  strcpy(f_path, dir_path);
  if (!have_slash)
    {
      f_path[path_size] = '/';
      path_size++;
    }
  f_path[path_size] = '\0';
  strcat(f_path, d_name);
  f_path[size - 1] = '\0';
  return (f_path);
}

int	valid_path(char *dest, char *limit)
{
  char	*real_dest;
  int	res;

  if ((real_dest = realpath(dest, NULL)) == NULL)
    return (-1);
  res = (strcmp(real_dest, limit) < 0) ? 0 : 1;
  free(real_dest);
  return (res);
}

char	*retrieve_limit(char *limit, char *res)
{
  int	i;
  int	j;

  i = 0;
  if (strlen(limit) < strlen(res))
    {
      j = strlen(limit);
      while (res[j])
	{
	  res[i] = res[j];
	  i++;
	  j++;
	}
    }
  else
    res[i++] = '/';
  res[i] = '\0';
  return (res);
}

int	my_pwd(int client_fd, char **cmd, char *limit)
{
  char	buff[4096];

  (void) cmd;
  (void) limit;
  if (getcwd(buff, 4096) == NULL &&
      my_putstr_fd(client_fd, "ERROR Can't retrieve cwd\n") == -1)
    return (-1);
  else
    {
      retrieve_limit(limit, buff);
      if (my_putstr_fd(client_fd, buff) == -1)
	return (-1);
    }
  return (1);
}

int	my_cd(int client_fd, char **cmd, char *limit)
{
  char	*path;
  int	res;

  path = NULL;
  if (!cmd[1] || strcmp(cmd[1], "/") == 0)
    path = limit;
  else
    {
      if ((res = valid_path(cmd[1], limit)) == 1)
	path = cmd[1];
      else if (res == 0)
	my_putstr_fd(client_fd, "ERROR : Permission denied");
      else
	my_putstr_fd(client_fd, "ERROR Can't check valid path");
    }
  if (path != NULL)
    {
      if (chdir(path) == -1)
	my_putstr_fd(client_fd, "ERROR chdir failed");
      else
	my_putstr_fd(client_fd, "SUCCESS");
    }
  return (1);
}
