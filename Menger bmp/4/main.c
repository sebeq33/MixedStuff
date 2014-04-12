/*
** main.c for main.c in /home/bequig_s//workspace/piscine-Tek2/d01/ex03
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Jan  9 20:15:11 2013 sebastien bequignon
** Last update Wed Jan  9 22:52:10 2013 sebastien bequignon
*/

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "drawing.h"
#include "bitmap.h"

int	convert(char *str, int end, int positif)
{
  int	res;
  int	cpt;
  int	tmp;
  int	current;

  cpt = 1;
  res = 0;
  while (--end >= 0)
    {
      current = (str[end] - '0') * cpt;
      tmp = res + current;
      if (res == tmp - current)
        res = tmp;
      else
        return (0);
      cpt = cpt * 10;
    }
  return (positif ? res : res * -1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	start;
  int	end;
  int	positif;

  i = 0;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i = i + 1;
  start = i;
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    i = i + 1;
  end = i;
  i = start - 1;
  positif = 1;
  while (i >= 0 && (str[i] == '+' || str[i] == '-'))
    if (str[i--] == '-')
      positif = !positif;
  return (convert(&str[start], end - start, positif));
}

int main(int ac, char **av)
{
  t_bmp_header header;
  t_bmp_info_header info;
  unsigned int *buffer;
  unsigned int **img;
  t_point p = {0, 0};
  size_t size;
  int d;

  size = my_getnbr(av[2]);
  if (ac < 4)
    {
      printf("menger_face file_name size level\n");
      return (EXIT_SUCCESS);
    }
  buffer = malloc(size * size * sizeof(*buffer));
  img = malloc(size * sizeof(*img));
  memset(buffer, 0, size * size * sizeof(*buffer));
  for (size_t i = 0; i < size; ++i)
    img[i] = buffer + i * size;
  make_bmp_header(&header, size);
  make_bmp_info_header(&info, size);
  draw_menger(img, size, my_getnbr(av[3]), p);
  d = open(av[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(d, &header, sizeof(header));
  write(d, &info, sizeof(info));
  write(d, buffer, size * size * sizeof(*buffer));
  close(d);
  return EXIT_SUCCESS;
}
