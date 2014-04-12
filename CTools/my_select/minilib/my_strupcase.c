/*
** my_strupcase.c for my_strupcase in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 23:51:08 2012 sebastien bequignon
** Last update Mon Oct 15 11:54:50 2012 sebastien bequignon
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 97 && str[i] <= 122)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
