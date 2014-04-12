/*
** get_next_line.c for get_next_line.c in /home/bequig_s//workspace/module-Unix/get_next_line
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Nov 23 15:45:59 2012 sebastien bequignon
** Last update Sat Dec  1 14:29:35 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	get_end(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  return (i);
}

char	*next(char *str)
{
  char	*result;
  int	size;
  int	i;

  size = get_end(str);
  if ((result = malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      result[i] = str[i];
      i++;
    }
  result[i] = '\0';
  i = 0;
  if (str[size] != '\0')
    while (str[++size] != '\0')
      str[i++] = str[size];
  while (i < size)
    str[i++] = '\0';
  return (result);
}

char	*my_realloc_str(char *str, char buffer[NB_READ + 1], int size_buf)
{
  int	i;
  int	end_str;
  char 	*result;

  end_str = 0;
  if (str != NULL)
    while (str[end_str] != '\0')
      end_str++;
  if ((result = malloc((end_str + size_buf + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < end_str)
    {
      result[i] = str[i];
      i++;
    }
  while (i - end_str < size_buf)
    {
      result[i] = buffer[i - end_str];
      i++;
    }
  result[i] = '\0';
  free(str);
  return (result);
}

char		*check_fill_line(char *str, const int fd)
{
  char		buffer[NB_READ + 1];
  int		ret;

  ret = -1;
  while (str == NULL || (str[get_end(str)] != '\n' && ret != 0))
    {
      if ((ret = read(fd, buffer, NB_READ)) < 0)
	return (NULL);
      if (!ret && str == NULL)
	return (NULL);
      buffer[ret] = '\0';
      str = my_realloc_str(str, buffer, ret);
      if (str == NULL || str[0] == '\0')
	return (NULL);
    }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	*str = NULL;
  static int	prec_fd = -1;
  char		*result;

  if ((prec_fd != fd || prec_fd < 0) && str != NULL)
    {
      free(str);
      str = NULL;
    }
  prec_fd = fd;
  if (fd < 0 || (str = check_fill_line(str, fd)) == NULL)
    return (NULL);
  if (str[get_end(str)] == '\0')
    {
      result = next(str);
      free(str);
      str = NULL;
      return (result);
    }
  else
    return (next(str));
}

