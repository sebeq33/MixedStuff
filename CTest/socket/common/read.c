/*
** read.c for read.c in /home/bequig_s//workspace/systemUnixTek2/my_irc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Apr 25 01:00:55 2013 sebastien bequignon
** Last update Fri Apr 26 17:05:14 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
** retrieve a substring using multiple chars as delim
*/
char	*substr(const char *str, const char *delim, int nb_elem)
{
  char	*result;
  int	size;
  int	i;

  i = 0;
  while (str[i] && strchr(delim, str[i]) != NULL)
    i++;
  while (nb_elem > 0 && str[i])
    {
      while (str[i] && strchr(delim, str[i]) == NULL)
	i++;
      nb_elem--;
      while (str[i] && strchr(delim, str[i]) != NULL)
	i++;
    }
  if (!str[i])
    return (NULL);
  size = 0;
  while (str[i + size] && strchr(delim, str[i + size]) == NULL)
    size++;
  if ((result = malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  strncpy(result, &str[i], size);
  result[size] = '\0';
  return (result);
}

/*
** retrieve a substring using position
** if size == -1 retrive from "start" parameter to the end of the string
*/
char	*splitstr(const char *str, int start, int size)
{
  char	*result;
  int	len;

  len = strlen(str);
  if (start >= len)
    return (NULL);
  if (size == -1 || start + size > len)
    size = len - start;
  if ((result = malloc((size + 1) * sizeof(char))) == NULL)
    return (NULL);
  result[size] = '\0';
  strncpy(result, &str[start], size);
  return (result);
}

char	*my_epur_str(char *str, const char *delim)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] && strchr(delim, str[i]) != NULL)
    i++;
  while (str[i])
    {
      while (str[i] && strchr(delim, str[i]) != NULL &&
	     strchr(delim, str[i + 1]) != NULL)
	i++;
      if (str[i] && strchr(delim, str[i]) != NULL)
	{
	  str[j++] = ' ';
	  i++;
	}
      while (str[i] && strchr(delim, str[i]) == NULL)
	str[j++] = str[i++];
    }
  while (j >= 0 && str[j - 1] && strchr(delim, str[j - 1]) != NULL)
    j--;
  str[j] = '\0';
  return (str);
}

char		*my_recv(int fd)
{
  static char	buff[4096];
  int		ret;

  if ((ret = read(fd, buff, 4096)) <= 0)
    return (NULL);
  buff[ret] = '\0';
  return (buff);
}

char		*my_recv_clean(int fd)
{
  char		*buff;

  if ((buff = my_recv(fd)) == NULL)
    return (NULL);
  return (my_epur_str(buff, " \t\v"));
}
