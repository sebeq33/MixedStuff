/*
** client_loop.c for client_loop.c in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Apr 13 12:00:18 2013 sebastien bequignon
** Last update Sun Apr 14 19:26:17 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"
#include "client.h"

static const t_hook     g_hooks[NB_ACTIONS]=
  {
    {"cd", &client_read_line},
    {"pwd", &client_read_line},
    {"ls", &client_ls},
    {"put", &my_get_file},
    {"get", &my_put_file},
  };

int	execute_command(int server, char *line)
{
  char	**cmd;
  char	buff[32];
  int	i;

  if ((cmd = my_str_to_wordtab(line, " \t\v\n")) == NULL)
    return (my_puterr("Malloc failed, can't handle that command\n"));
  if (my_putstr_fd(server, line) == -1 ||
      my_putstr_fd(server, "\n") == -1 ||
      ((i = read(server, buff, 32)) == -1))
    return (-1);
  if (strncmp(buff, "ERROR", 5) == 0)
    {
      write(1, buff, i);
      return (1);
    }
  if (strcasecmp(cmd[0], "quit") == 0)
    return (0);
  i = 0;
  while (i < NB_ACTIONS)
    {
      if (strcmp(g_hooks[i].hook, cmd[0]) == 0)
	return (g_hooks[i].func(server, cmd));
      i++;
    }
  return (1);
}

void	launch_client(int server)
{
  int	cont;
  char	*line;

  if ((line = get_next_line(server)) == NULL)
    {
      my_puterr("Server didn't say 'hello', i'll not talk with him =O\n");
      return ;
    }
  printf("From server : \"%s\"\n", line);
  free(line);
  cont = 1;
  while (cont > 0)
    {
      my_putstr_fd(1, "my_ftp> ");
      if ((line = get_next_line(0)) == NULL)
	cont = -1;
      else
	{
	  if (strlen(my_epur_str(line)) > 0)
	    cont = execute_command(server, line);
	  free(line);
	}
      if (cont == -1)
	my_puterr("\nConnection with server lost\n");
    }
}
