/*
** parser.c for parser.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 15:27:14 2012 sebastien bequignon
** Last update Fri Nov 30 11:59:57 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "func_prototype.h"
#include "minishell.h"
#include "minilib/my.h"

int		count_word(char *str)
{
  int		nb_param;
  int		i;

  nb_param = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
        nb_param++;
      i++;
    }
  return (nb_param);
}

char		**parse_cmd(char *cmd)
{
  int		i;
  int		start_cmd;
  int		current_word;
  char		**params;

  i = 0;
  current_word = 0;
  if ((params = malloc((count_word(cmd) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (i == 0 || cmd[i - 1] != '\0')
    {
      start_cmd = i;
      while (cmd[i] != '\0' && cmd[i] != ' ')
	i++;
      if (i - start_cmd > 0)
	{
	  params[current_word] = get_part_string(&cmd[start_cmd], i - start_cmd);
	  current_word++;
	}
      i++;
    }
  params[current_word] = NULL;
  return (params);
}

