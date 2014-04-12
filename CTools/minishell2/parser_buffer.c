/*
** parser_buffer.c for parser_buffer.c in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov 29 17:53:32 2012 sebastien bequignon
** Last update Fri Nov 30 15:56:53 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "func_prototype.h"
#include "minilib/my.h"

char	*get_cmd(char *buffer, int nb_cmd)
{
  int	start;
  int	end;
  int	current;

  end = 0;
  current = 0;
  while (current < nb_cmd + 1 && buffer[end] != '\0')
    {
      start = end;
      while (buffer[end] != '\0' && buffer[end] != ';')
	end++;
      if (current != nb_cmd && buffer[end] == ';')
	end++;
      current++;
    }
  if (current == nb_cmd + 1)
    return (my_epur_str(get_part_string(&buffer[start], end - start)));
  return (NULL);
}

char	*get_params(char *cmd, int nb_param)
{
  int	start;
  int	end;
  int	current;

  end = 0;
  current = 0;
  while (current < nb_param + 1 && cmd[end] != '\0')
    {
      start = end;
      while (cmd[end] != '\0' && cmd[end] != ' ')
	end++;
      if (current != nb_param && cmd[end] == ' ')
	end++;
      current++;
    }
  if (current == nb_param + 1)
    return (my_epur_str(get_part_string(&cmd[start], end - start)));
  return (NULL);
}
