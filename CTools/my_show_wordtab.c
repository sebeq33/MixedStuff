/*
** my_show_wordtab.c for my_show_wordtab in /home/bequig_s//piscine/jour8
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct 11 10:09:05 2012 sebastien bequignon
** Last update Fri Nov 16 09:42:35 2012 sebastien bequignon
*/

#include "my.h"

void	my_show_wordtab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != '\0')
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  my_putchar(tab[i][j]);
	  j = j + 1;
	}
      my_putchar('\n');
      i = i + 1;
    }
}
