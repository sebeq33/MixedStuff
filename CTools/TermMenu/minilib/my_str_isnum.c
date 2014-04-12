/*
** my_str_isnum.c for my_str_isnum in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Tue Oct  9 00:53:24 2012 sebastien bequignon
** Last update Mon Oct 15 11:50:20 2012 sebastien bequignon
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 48 && str[i] <= 57))
	return (0);
      i = i + 1;
    }
  return (1);
}
