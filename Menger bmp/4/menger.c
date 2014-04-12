/*
** menger.c for menger.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex01
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 12:11:14 2013 sebastien bequignon
** Last update Wed Jan  9 22:58:33 2013 sebastien bequignon
*/

#include <stdio.h>
#include <stdint.h>
#include "drawing.h"

# define RGB(r, g, b) (r << 16 | g << 8 | b)

void	display_param(uint32_t **img, int size, t_point *point, int level)
{
  draw_square(img, point, size, RGB(255 / level, 255 / level, 255 / level));
}

void	draw_menger(uint32_t **img, int size, int level, t_point orig)
{
  t_point	point;

  if (level > 0)
    {
      point.x = orig.x + size / 3;
      point.y = orig.y + size / 3;
      display_param(img, size / 3, &point, level);
      if (level > 1 && (size / 3))
	{
	  for (int x = 0; x < size; x += size / 3)
	    for (int y = 0; y < size; y += size / 3)
	      if (x != size / 3 || y != size / 3)
		{
		  point.x = orig.x + x;
		  point.y = orig.y + y;
		  draw_menger(img, size / 3, level - 1, point);
		}
	}
    }
}
