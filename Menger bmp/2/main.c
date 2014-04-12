/*
** main.c for main.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex02
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 16:38:25 2013 sebastien bequignon
** Last update Wed Jan  9 16:41:08 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bitmap.h"

int main(void)
{
  t_bmp_header header;
  t_bmp_info_header info;
  int d;
  uint32_t pixel = 0x00FFFFFF;

  make_bmp_header(&header, 32);
  make_bmp_info_header(&info, 32);
  d = open("32px.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  for (size_t i = 0; i < 32 * 32; ++i)
    write(d, &pixel, sizeof(pixel));
  close(d);
  return EXIT_SUCCESS;
}
