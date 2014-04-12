/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/bequig_s//piscine/jour8
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 10 15:16:33 2012 sebastien bequignon
** Last update Sat Apr 13 23:37:33 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <string.h>

static int	nb_word(char *str, char *sep)
{
  int		i;

  i = 0;
  while (*str)
    {
      while (strchr(sep, *str) != NULL)
	str++;
      if (*str)
	{
	  while (*str && strchr(sep, *str) == NULL)
	    str++;
	  if (*str)
	    str++;
	  i++;
	}
    }
  return (i);
}

static int	put_word(char **dest, char *src, char *sep)
{
  int		i;

  i = 0;
  while (src[i] && strchr(sep, src[i]) == NULL)
    i++;
  if ((*dest = malloc((i + 1) * sizeof(char))) == NULL)
    return (-1);
  strncpy(*dest, src, i);
  (*dest)[i] = '\0';
  if (src[i])
    i++;
  return (i);
}

char	**my_str_to_wordtab(char *str, char *sep)
{
  char	**result;
  int	word;
  int	i;

  if ((result = malloc((nb_word(str, sep) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  word = 0;
  while (*str)
    {
      while (strchr(sep, *str) != NULL)
	str++;
      if (*str)
	{
	  if ((i = put_word(&result[word++], str, sep)) <= 0)
	    return (NULL);
	  str += i;
	}
    }
  result[word] = NULL;
  return (result);
}

int	wordtab_len(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void	free_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
