/*
** my_str_isupper.c for my_str_isupper in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Tue Oct  9 00:42:05 2012 sebastien bequignon
** Last update Mon Oct 15 11:51:14 2012 sebastien bequignon
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 65 && str[i] <= 90))
	return (0);
      i = i + 1;
    }
  return (1);
}
