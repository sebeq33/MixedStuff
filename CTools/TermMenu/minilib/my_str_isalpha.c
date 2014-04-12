/*
** my_str_isalpha.c for my_str_isalpha in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Tue Oct  9 00:42:05 2012 sebastien bequignon
** Last update Mon Oct 15 11:46:03 2012 sebastien bequignon
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 97 && str[i] <= 122))
	if (!(str[i] >= 65 && str[i] <= 90))
	  return (0);
      i = i + 1;
    }
  return (1);
}
