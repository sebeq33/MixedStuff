/*
** my_strstr.c for my_strstr in /home/bequig_s//piscine/jour6
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Mon Oct  8 12:13:20 2012 sebastien bequignon
** Last update Fri Oct 26 11:55:56 2012 sebastien bequignon
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	s1_tmp;
  int	s2_tmp;

  i = 0;
  while (i <= my_strlen(s1))
    {
      s1_tmp = i < my_strlen(s1) ? s1[i] : 0;
      s2_tmp = i < my_strlen(s2) ? s2[i] : 0;
      if (s1[i] != s2[i])
	return s1_tmp - s2_tmp;
      i = i + 1;
    }
  return (0);
}
