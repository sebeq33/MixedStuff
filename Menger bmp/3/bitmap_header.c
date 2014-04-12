/*
** bitmap_header.c for bitmap_header.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex02
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 16:29:58 2013 sebastien bequignon
** Last update Wed Jan  9 19:49:22 2013 sebastien bequignon
*/

#include <stdint.h>
#include <stdlib.h>
#include "bitmap.h"
int		is_big_endian()
{
  int		i;
  unsigned char	*s;

  i = 1;
  s = (unsigned char *) &i;
  return (!(s[0] == 1));
}

uint16_t		get_magic()
{
  int			i;
  uint16_t		magic;
  unsigned char		*s;
  unsigned char		tmp;

  magic = 0x424D;
  if (!is_big_endian())
    {
      s = (unsigned char *) &magic;
      tmp = s[0];
      s[0] = s[1];
      s[1] = tmp;
      i = 8;
      tmp = 0;
      while (i > 0)
      	tmp |= s[0] << i-- * 8;
      s[0] = tmp;
      i = 8;
      tmp = 0;
      while (i > 0)
      	tmp |= s[1] << i-- * 8;
      s[1] = tmp;
    }
  return (magic);

}

void	make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = get_magic();
  header->offset = sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
  header->size = size * size * 4 + header->offset; /* 13840 */
  header->_app1 = 0;
  header->_app2 = 0;
}

void	make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = sizeof(t_bmp_info_header);
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bbp = 32;
  header->compression = 0;
  header->raw_data_size = size * size * header->bbp / 8;
  header->v_resolution = 0;
  header->h_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
