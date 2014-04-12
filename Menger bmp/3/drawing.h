/*
** drawing.h for drawing.h in /home/bequig_s//workspace/piscine-Tek2/d01/ex02
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 20:06:35 2013 sebastien bequignon
** Last update Wed Jan  9 20:22:24 2013 sebastien bequignon
*/

#ifndef DRAWING_H_
# define DRAWING_H_

typedef struct
{
  uint32_t	x;
  uint32_t	y;
}		t_point;

void draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color);

#endif /* !DRAWING_H_ */
