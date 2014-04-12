/*
** parser.c for parser.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 15:27:14 2012 sebastien bequignon
** Last update Wed Nov 28 11:33:55 2012 sebastien bequignon
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

void		parse_cmd(char **params, char *str)
{
  int		i;
  int		nb_char;
  int		current_word;

  i = 0;
  current_word = 0;
  while (i == 0 || str[i - 1] != '\0')
    {
      nb_char = 0;
      while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ')
	{
	  nb_char++;
	  i++;
	}
      if (nb_char > 0)
	{
	  params[current_word] = get_part_string(&str[i - nb_char], nb_char);
	  current_word++;
	}
      i++;
    }
  params[current_word] = NULL;
}

char		**prepare_parse_cmd(char **params, char *buffer)
{
  int		nb_params;

  nb_params = count_word(buffer);
  if (buffer[0] == '\0' || buffer[0] == '\n' || nb_params < 1)
    return (NULL);
  params = malloc((nb_params + 1) * sizeof(char *));
  if (params == NULL)
    return (NULL);
  parse_cmd(params, buffer);
  return (params);
}
