/*
** my_strncmp.c for my_strncmp in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 16:20:27 2012 sebastien bequignon
** Last update Fri Oct 26 12:00:57 2012 sebastien bequignon
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  char	s1_tmp;
  char	s2_tmp;

  i = 0;
  while (i < my_strlen(s2) && i < n)
    {
      s1_tmp = i < my_strlen(s1) ? s1[i] : 0;
      s2_tmp = i < my_strlen(s2) ? s2[i] : 0;	 
      if (s1[i] != s2[i])
	return (s1_tmp - s2_tmp);
      i = i + 1;
    }
  return (0);
}
