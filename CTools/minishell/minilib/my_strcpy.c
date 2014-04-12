/*
** my_strcpy.c for my_strcpy in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 10:11:40 2012 sebastien bequignon
** Last update Mon Oct 15 11:45:29 2012 sebastien bequignon
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
