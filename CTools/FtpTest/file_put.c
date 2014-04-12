/*
** server_files.c for server_files.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Apr 12 13:55:17 2013 sebastien bequignon
** Last update Sun Apr 14 18:33:56 2013 sebastien bequignon
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "server.h"
#include "get_next_line.h"

int	put_loop(int dest_fd, int file_fd, int size)
{
  char	buff[4096];
  int	ret;

  if (my_putstr_fd(dest_fd, "SUCCESS\n") == -1 ||
      (ret = read(dest_fd, buff, 4096)) == -1)
    return (-1);
  else if (strncmp(buff, "SUCCESS", 7) != 0)
    {
      buff[ret] = '\0';
      printf("ERROR %s\n", buff);
      return (1);
    }
  while (size > 0)
    {
      if ((ret = read(dest_fd, buff, 4096)) < 0)
	return (-1);
      if (write(file_fd, buff, ret) == -1)
	{
	  my_putstr_fd(dest_fd, "ERROR can't write on the file\n");
	  return (1);
	}
      size -= ret;
    }
  printf("SUCCESS\n");
  return (1);
}

int	open_file_with_right(char *path, int right)
{
  char	**file;
  int	fd;

  if ((file = my_str_to_wordtab(path, "/")) == NULL)
    return (-1);
  fd = open(file[wordtab_len(file) - 1],
	    O_CREAT | O_WRONLY | O_TRUNC,
	    right & 0777);
  free_wordtab(file);
  return (fd);
}

int	get_info(int dest_fd, int *right, int *size)
{
  char	**params;
  char	*line;
  int	res;

  if ((line = get_next_line(dest_fd)) == NULL)
    return (-1);
  if (strncmp(line, "INFO", 4) != 0)
    res = my_putstr_fd(dest_fd, "ERROR you gave me an error\n");
  else if ((params = my_str_to_wordtab(line, " \t\v\n")) == NULL
      || wordtab_len(params) < 3)
    {
      res = my_putstr_fd(dest_fd, "ERROR malloc failed\n");
      free_wordtab(params);
    }
  else
    {
      *right = my_getnbr(params[1]);
      *size = my_getnbr(params[2]);
      free_wordtab(params);
    }
  free(line);
  return (res >= 0 ? 1 : -1);
}

int	my_put_file(int dest_fd, char **cmd)
{
  int	right;
  int	size;
  int	file_fd;

  if (get_info(dest_fd, &right, &size) == -1)
    return (-1);
  if ((file_fd = open_file_with_right(cmd[1], right)) == -1)
    return (my_putstr_fd(dest_fd, "ERROR Can't open the file\n") >= 0 ? 1 : 0);
  else if (put_loop(dest_fd, file_fd, size) == -1)
    {
      close(file_fd);
      return (-1);
    }
  if (file_fd != -1)
    close(file_fd);
  return (1);
}
