/*
** menger.c for menger.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex01
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 12:11:14 2013 sebastien bequignon
** Last update Wed Jan  9 18:42:51 2013 sebastien bequignon
*/

#include <stdio.h>

void	display_param(int size, int x, int y)
{
  printf("%03d %03d %03d\n", size, x, y);
}

void	menger(int size, int level, int x0, int y0)
{
  if (level > 0)
    {
      display_param(size / 3, x0 + size / 3, y0 + size / 3);
      if (level > 1 && (size / 3))
	{
	  for (int x = 0; x < size; x += size / 3)
	    for (int y = 0; y < size; y += size / 3)
	      if (x != size / 3 || y != size / 3)
		menger(size / 3, level - 1, x0 + x, y0 + y);
	}
    }
}
