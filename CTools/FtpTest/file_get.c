/*
** file_get.c for file_get.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Apr 12 15:01:08 2013 sebastien bequignon
** Last update Sun Apr 14 19:21:15 2013 sebastien bequignon
*/

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "server.h"

int	get_loop(int dest_fd, int file_fd, int size)
{
  char	buff[4096];
  int	ret;

  if ((ret = read(dest_fd, buff, 4096)) == -1)
    return (-1);
  else if (strncmp(buff, "SUCCESS", 7) != 0)
    return (1);
  while (size > 0)
    {
      if ((ret = read(file_fd, buff, 4096)) == -1)
	{
	  my_putstr_fd(dest_fd, "ERROR can't read the file\n");
	  return (1);
	}
      if (write(dest_fd, buff, ret) == -1)
	return (-1);
      size -= ret;
    }
  return (1);
}

int		get_right(int fd_file, int *right, int *size)
{
  struct stat	stat;

  if (fstat(fd_file, &stat) == -1)
    return (-1);
  if ((S_ISDIR(stat.st_mode)))
    return (-1);
  *right = stat.st_mode;
  *size = stat.st_size;
  return (1);
}

int	my_get_file(int dest_fd, char **cmd)
{
  char	buff[4096];
  int	size;
  int	right;
  int	file_fd;

  if ((file_fd = open(cmd[1], O_RDONLY)) == -1 ||
      (get_right(file_fd, &right, &size)) == -1)
    {
      my_putstr_fd(dest_fd, "ERROR can't open this file\n");
      if (read(dest_fd, buff, 4096) == -1)
	return (-1);
      return (1);
    }
  if (dprintf(dest_fd, "INFO %d %d\n", right, size) == -1
      || my_putstr_fd(dest_fd, "SUCCESS\n") == -1)
    return (-1);
  if (get_loop(dest_fd, file_fd, size) == -1)
    {
      close(file_fd);
      return (-1);
    }
  close(file_fd);
  return (1);
}
