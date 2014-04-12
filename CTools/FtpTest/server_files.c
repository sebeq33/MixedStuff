/*
** server_files.c for server_files.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Apr 14 03:16:15 2013 sebastien bequignon
** Last update Sun Apr 14 06:11:20 2013 sebastien bequignon
*/

#include <unistd.h>
#include "server.h"

int	my_put_file_server(int client_fd, char **cmd, char *limit)
{
  (void) limit;
  return (my_put_file(client_fd, cmd));
}

int	my_get_file_server(int dest_fd, char **cmd, char *limit)
{
  char	buff[4096];
  int	ret;

  if ((ret = valid_path(cmd[1], limit)) == -1)
    {
      if (my_putstr_fd(dest_fd, "ERROR : can't check path\n") == -1)
	return (-1);
      if ((ret = read(dest_fd, buff, 4096)) == -1)
	return (-1);
      return (1);
    }
  if (ret == 1)
    return (my_get_file(dest_fd, cmd));
  if (my_putstr_fd(dest_fd, "ERROR : permission denied\n") == -1)
    return (-1);
  if ((ret = read(dest_fd, buff, 4096)) == -1)
    return (-1);
  return (1);
}
