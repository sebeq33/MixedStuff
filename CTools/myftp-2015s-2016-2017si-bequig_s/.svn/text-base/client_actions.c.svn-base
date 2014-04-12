/*
** client_actions.c for client_actions.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Apr 13 15:26:40 2013 sebastien bequignon
** Last update Sun Apr 14 19:19:14 2013 sebastien bequignon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "client.h"
#include "get_next_line.h"

static int	is_sep(char c)
{
  return (c == ' ' || c == '\t' || c == '\v');
}

char	*my_epur_str(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (is_sep(str[i]))
    i++;
  while (str[i] != '\0')
    {
      while (is_sep(str[i]) && is_sep(str[i + 1]))
	i++;
      if (is_sep(str[i]))
	{
	  str[j++] = ' ';
	  i++;
	}
      while (!is_sep(str[i]) && str[i] != '\0')
	str[j++] = str[i++];
    }
  while (is_sep(str[j - 1]))
    j--;
  str[j] = '\0';
  return (str);
}

int	client_read_line(int server, char **cmd)
{
  char	buff[4096];
  int	ret;

  (void) cmd;
  if ((ret = read(server, buff, 4096)) == -1)
    return (-1);
  write(1, buff, ret);
  write(1, "\n", 1);
  return (1);
}

int	client_ls_loop(int server)
{
  char	*buff;
  int	cont;

  cont = 1;
  while (cont)
    {
      if ((buff = get_next_line(server)) == NULL)
	return (-1);
      if (strcmp(buff, "CONT") != 0)
	cont = 0;
      else
	{
	  free(buff);
	  if ((buff = get_next_line(server)) == NULL)
	    return (-1);
	  printf("%s\n", buff);
	}
      free(buff);
    }
  return (1);
}

int	client_ls(int server, char **cmd)
{
  char	*buff;

  (void) cmd;
  if ((buff = get_next_line(server)) == NULL)
    return (-1);
  printf("LS : %s\n", buff);
  if (strncmp(buff, "ERROR", 5) == 0)
    {
      free(buff);
      return (1);
    }
  free(buff);
  return (client_ls_loop(server));
}
