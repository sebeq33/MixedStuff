/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/bequig_s//piscine/jour8
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 10 15:16:33 2012 sebastien bequignon
** Last update Thu Dec 20 19:10:47 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "my.h"

static int	nb_word(char *str)
{
  int		nbword;
  int		i;

  i = 0;
  nbword = 0;
  while (str[i] != '\0')
    {
      if (!my_isalphanumeric(str[i]))
	nbword = nbword + 1;
      i = i + 1;
    }
  return (nbword + 1);
}

static int	place(char **tab, int *pos, char *to_place)
{
  int		i;

  if (to_place == NULL)
    {
      i = 0;
      while (i < *pos)
	free(tab[i++]);
      free(tab);
      return (1);
    }
  tab[*pos] = to_place;
  *pos = *pos + 1;
  return (0);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	nbword;
  int	nb_char;
  char	**tab;

  if ((tab = malloc((nb_word(str) + 1)* sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  nbword = 0;
  while (i == 0 || str[i - 1] != '\0')
    {
      nb_char = 0;
      while (my_isalphanumeric(str[i]))
	{
	  nb_char = nb_char + 1;
	  i = i + 1;
	}
      if (nb_char > 0)
	if (place(tab, &nbword,
		  get_part_of_string(&str[i - nb_char], nb_char)))
	  return (NULL);
      i = i + 1;
    }
  tab[nbword] = '\0';
  return (tab);
}
