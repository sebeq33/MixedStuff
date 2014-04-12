/*
** server_ls.c for server_ls.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Apr 12 10:15:33 2013 sebastien bequignon
** Last update Sat Apr 13 23:50:13 2013 sebastien bequignon
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "server.h"

void    set_mode(mode_t *m, char mode[11])
{
  if (S_ISDIR(*m))
    mode[0] = 'd';
  else if (S_ISSOCK(*m))
    mode[0] = 's';
  else if (S_ISLNK(*m))
    mode[0] = 'l';
  else if (S_ISCHR(*m))
    mode[0] = 'c';
  else if (S_ISFIFO(*m))
    mode[0] = 'p';
  else if (S_ISBLK(*m))
    mode[0] = 'b';
  else
    mode[0] = '-';
  mode[1] = *m & S_IRUSR ? 'r' : '-';
  mode[2] = *m & S_IWUSR ? 'w' : '-';
  mode[3] = *m & S_IXUSR ? 'x' : '-';
  mode[4] = *m & S_IRGRP ? 'r' : '-';
  mode[5] = *m & S_IWGRP ? 'w' : '-';
  mode[6] = *m & S_IXGRP ? 'x' : '-';
  mode[7] = *m & S_IROTH ? 'r' : '-';
  mode[8] = *m & S_IWOTH ? 'w' : '-';
  mode[9] = *m & S_IXOTH ? 'x' : '-';
  mode[10] = '\0';
}

int	display_one_file(int client_fd, char *name, struct stat *stat)
{
  char		mode[11];
  char		*time;
  int		len;

  time = NULL;
  if (stat)
    {
      set_mode(&stat->st_mode, mode);
      if ((time = ctime(&stat->st_mtime)) != NULL &&
	  (len = strlen(time)) > 2)
	time[len - 1] = '\0';
    }
  if (dprintf(client_fd, "%s %5d %s %s\n",
	      (stat) ? mode : "e_stat",
	      (int) stat->st_size,
	      (stat) ? ((time) ? time : "e_ctime") : "e_stat",
	      name) == -1)
    return (-1);
  return (1);
}

int		display_files(int client_fd, struct dirent **files, int nb_files)
{
  struct stat	stat;
  char		*path;
  int		i;

  i = 0;
  while (i < nb_files)
    {
      if (my_putstr_fd(client_fd, "CONT\n") == -1)
	return (-1);
      if ((path = get_file_path(files[i]->d_name)) == NULL ||
	  lstat(path, &stat) == -1)
	{
	  if (display_one_file(client_fd, files[i]->d_name, NULL) == -1)
	    return (-1);
	}
      else if (display_one_file(client_fd, files[i]->d_name, &stat) == -1)
	return (-1);
      free(path);
      i++;
    }
  if (my_putstr_fd(client_fd, "STOP\n") == -1)
    return (-1);
  return (1);
}

char	*get_valid_path(char *asked, char *limit)
{
  if (asked)
    {
      if (valid_path(asked, limit))
	return (asked);
      else
	return (NULL);
    }
  return (".");
}

int		my_ls(int client_fd, char **cmd, char *limit)
{
  struct dirent **files;
  char		*dir;
  int		i;

  if ((dir = get_valid_path(cmd[1], limit)) == NULL)
    {
      if (my_putstr_fd(client_fd, "ERROR Invalid path\n") == -1)
	return (0);
    }
  else if ((i = scandir(dir, &files, 0, alphasort)) == -1)
    {
      if (my_putstr_fd(client_fd, "ERROR Scandir failed\n") == -1)
	return (0);
    }
  else
    {
      if (dprintf(client_fd, "SUCCESS %d file(s)\n", i) == -1)
	return (0);

      if (display_files(client_fd, files, i) == -1)
	return (-1);
    }
  return (1);
}
