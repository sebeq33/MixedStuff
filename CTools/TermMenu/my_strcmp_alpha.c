/*
** my_strstr.c for my_strstr in /home/bequig_s//piscine/jour6
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Oct  8 12:13:20 2012 sebastien bequignon
** Last update Tue Nov 20 10:25:38 2012 sebastien bequignon
*/

/*
** "32" = 'a' - 'A' for char between upper and lower case
*/
int	my_strcmp_alpha(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    i++;
  if (s1[i] >= 'A' && s1[i] <= 'Z' && s1[i] == s2[i] - 32)
    return (1);
  if (s2[i] >= 'A' && s2[i] <= 'Z' && s2[i] == s1[i] - 32)
    return (-1);
  if (s1[i] >= 'A' && s1[i] <= 'Z' && s2[i] >= 'a' && s2[i] <= 'z')
    return (s1[i] - s2[i] + 32);
  if (s2[i] >= 'A' && s2[i] <= 'Z' && s1[i] >= 'a' && s1[i] <= 'z')
    return (s1[i] - s2[i] - 32);
  return (s1[i] - s2[i]);
}
