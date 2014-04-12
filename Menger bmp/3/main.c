/*
** main.c for main.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex03
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 20:15:11 2013 sebastien bequignon
** Last update Wed Jan  9 21:16:54 2013 sebastien bequignon
*/

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "drawing.h"
#include "bitmap.h"

int main(void)
{
  t_bmp_header header;
  t_bmp_info_header info;
  unsigned int *buffer;
  unsigned int **img;
  t_point p = {0, 0};
  size_t size = 64;
  int d;

  buffer = malloc(size * size * sizeof(*buffer));
  img = malloc(size * sizeof(*img));
  memset(buffer, 0, size * size * sizeof(*buffer));
  for (size_t i = 0; i < size; ++i)
    img[i] = buffer + i * size;
  make_bmp_header(&header, size);
  make_bmp_info_header(&info, size);
  draw_square(img, &p, size, 0x0000FFFF);
  p.x = 10;
  p.y = 10;
  draw_square(img, &p, 22, 0x00FF0000);
  d = open("square.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  write(d, buffer, size * size * sizeof(*buffer));
  close(d);
  return EXIT_SUCCESS;
}
