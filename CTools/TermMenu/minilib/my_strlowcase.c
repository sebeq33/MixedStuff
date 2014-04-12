/*
** my_strlowcase.c for my_strlowcase in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Tue Oct  9 00:05:52 2012 sebastien bequignon
** Last update Mon Oct 15 11:52:01 2012 sebastien bequignon
*/

char	*my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
