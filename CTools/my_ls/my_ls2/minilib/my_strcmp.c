/*
** my_strstr.c for my_strstr in /home/bequig_s//piscine/jour6
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Oct  8 12:13:20 2012 sebastien bequignon
** Last update Sun Nov  4 22:00:14 2012 sebastien bequignon
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
