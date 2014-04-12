/*
** my_strncpy.c for my_strncpy in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 10:33:35 2012 sebastien bequignon
** Last update Mon Oct 29 01:42:12 2012 sebastien bequignon
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
