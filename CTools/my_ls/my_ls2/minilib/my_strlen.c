/*
** my_strlen.c for my_strlen in /home/bequig_s//piscine/jour4
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct  4 10:31:18 2012 sebastien bequignon
** Last update Sat Oct 13 15:18:15 2012 sebastien bequignon
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
