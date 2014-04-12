/*
** bitmap.h for bitmap.h in /home/bequig_s//workspace/piscine-Tek2/d01/ex02
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 16:23:37 2013 sebastien bequignon
** Last update Wed Jan  9 18:49:22 2013 sebastien bequignon
*/

#ifndef BITMAP_H_
# define BITMAP_H_

#include <stdint.h>

typedef struct __attribute__ ((packed))
{
  uint16_t	magic;
  uint32_t	size;
  uint16_t	_app1;
  uint16_t	_app2;
  uint32_t	 offset;
} t_bmp_header;

typedef struct __attribute__ ((packed))
{
  uint32_t	size;
  int32_t	width;
  int32_t	height;
  uint16_t	planes;
  uint16_t	bbp;
  uint32_t	compression;
  uint32_t	raw_data_size;
  int32_t	h_resolution;
  int32_t	v_resolution;
  uint32_t	palette_size;
  uint32_t	important_colors;
} t_bmp_info_header;

void	make_bmp_header(t_bmp_header *header, size_t size);
void	make_bmp_info_header(t_bmp_info_header *header, size_t size);

#endif /* !BITMAP_H_ */
