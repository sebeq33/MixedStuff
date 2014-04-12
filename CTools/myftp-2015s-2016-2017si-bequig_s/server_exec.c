/*
** server_exec.c for server_exec.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Apr 11 02:25:42 2013 sebastien bequignon
** Last update Sun Apr 14 03:39:59 2013 sebastien bequignon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "server.h"

static const t_hook	g_hooks[NB_ACTIONS]=
{
  {"cd", &my_cd},
  {"pwd", &my_pwd},
  {"ls", &my_ls},
  {"put", &my_put_file_server},
  {"get", &my_get_file_server},
};

int	select_command(int client_fd, char **cmd, char *limit)
{
  int	i;

  i = 0;

  while (i < NB_ACTIONS)
    {
      if (strcmp(g_hooks[i].hook, cmd[0]) == 0)
	{
	  my_putstr_fd(client_fd, "SUCCESS command found\n");
	  return (g_hooks[i].func(client_fd, cmd, limit));
	}
      i++;
    }
  my_putstr_fd(client_fd, "ERROR Command not supported\n");
  printf("ERROR cmd [%s]\n", cmd[0]);
  return (1);
}

int	execute_command(int client_fd, char *line, char *limit)
{
  char	**cmd;
  int	res;

  res = 1;
  if ((cmd = my_str_to_wordtab(line, " \t\v\n")) == NULL)
    my_putstr_fd(client_fd, "ERROR memory allocation failed\n");
  else
    {
      if (wordtab_len(cmd) <= 0)
	my_putstr_fd(client_fd, "CONTINUE\n");
      else
	res = select_command(client_fd, cmd, limit);
      free_wordtab(cmd);
    }
  return (res);
}
