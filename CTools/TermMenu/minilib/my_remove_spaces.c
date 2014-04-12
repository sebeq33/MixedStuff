/*
** epur_str.c for epur_str in /exam//rendu/ex_5
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Oct 27 10:33:50 2012 sebastien bequignon
** Last update Fri Nov 16 10:39:52 2012 sebastien bequignon
*/

static int	char_to_remove(char c)
{
  return (c == ' ' || c == '\t' || c == '\v');
}

static void	erase_char(char *str, int i)
{
  while (str[i] != '\0')
    {
      str[i] = str[i + 1];
      i = i + 1;
    }
  str[i] = '\0';
}

char	*my_remove_spaces(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (char_to_remove(str[i]))
	{
	  while (char_to_remove(str[i]))
	    erase_char(str, i);
	}
      i = i + 1;
    }
  if (str[i - 1] == '\n')
    str[i - 1] = '\0';
  return (str);
}
