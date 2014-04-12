/*
** drawing.c for drawing.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex02
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 20:07:40 2013 sebastien bequignon
** Last update Wed Jan  9 21:26:38 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdint.h>
#include "drawing.h"

void	draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
  unsigned int	x;
  unsigned int	y;

  x = 0;
  while (x < size)
    {
      y = 0;
      while (y < size)
	{
	  img[orig->y + y][orig->x + x] = color;
	  y++;
	}
      x++;
    }
}
