
#include <stdlib.h>

int	nb_word(char *str)
{
  int	i;
  
  i = 0;
  while (*str == ' ' || *str == '\t')
    str++;
  if (*str)
    {
      i++;
      while (*str && *str != ' ' && *str != '\t')
	str++;
    }
  return (i);
}

char	**wordtab(char *str)
{
  char	**wtab;
  int	i;

  wtab = malloc((nb_word(str) + 1) * sizeof(char *));
  i = 0;
  while (*str)
    {
      while (*str == ' ' || *str == '\t')
	str++;
      if (*str)
	{
	  wtab[i++] = str;
	  while (*str && *str != ' ' && *str != '\t')
	    str++;
	  if (*str)
	    *str++ = 0;
	}
    }
  wtab[i] = 0;
  return (wtab);
}

inline int to_lower(char c)
{
  return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}
int	my_strcmp(char *s1, char *s2)
{
  while (*s1 && *s2 && to_lower(*s1) == to_lower(*s2))
    {
      s1++;
      s2++;
    }
  return (to_lower(*s1) - to_lower(*s2));
}

char	**sort_word(char **wtab)
{
  char	*tmp;
  int	i;
  
  i = 1;
  while (wtab[i])
    {
      if (my_strcmp(wtab[i - 1], wtab[i]) > 0)
	{
	  tmp = wtab[i - 1];
	  wtab[i - 1] = wtab[i];
	  wtab[i] = tmp;
	  i = 1;
	} 
      else
	i++;
    }
  return (wtab);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	**display_sort(char **wtab)
{
  int	i;

  i = 0;
  while (wtab[i])
    {
      write(1, wtab[i], my_strlen(wtab[i]));
      i++;
      if (wtab[i] != '\0')
	write(1, " ", 1);
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    display_sort(sort_word(wordtab(av[1])));
  write(1, "\n", 1);
  return (0);
}
