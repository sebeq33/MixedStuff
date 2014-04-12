/*
** main.c for main.c in /tmp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri May 10 16:15:27 2013 sebastien bequignon
** Last update Tue May 28 17:57:42 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>

int	isBigEndian()
{
  union
  {
    int	 i;
    char c[4];
  } endianchecker;

  endianchecker.i = 1;
  return (endianchecker.c[0] == 1);
}

void	reverse_bytes(char *data, size_t size)
{
  char	tmp;
  int	i = 0;
  int	j = size - 1;

  while (i < j)
    {
      tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
      i++;
      j--;
    }
}

void	toBigEndian(void *data, size_t size)
{
  if (!isBigEndian())
    reverse_bytes(data, size);
}

void	display_bit(char *bytes, size_t size)
{
  size_t	i;
  int8_t	j;

  i = 0;
  while (i < size)
    {
      j = 7;
      while (j >= 0)
	{
	  putchar((((bytes[i]) >> j) & 0x01) + '0');
	  j--;
	}
      i++;
    }
}

void	explode_val_test(int ac, char **av)
{
  int32_t	val;

  val = (ac > 1) ? atoi(av[1]) : 277;

  printf("val            = %d\n", val);
  printf("endian         = \"%s endian\"\n", isBigEndian() ? "big" : "little");
  printf("bit of val     = ");
  display_bit((char *) &val, sizeof(val));
  printf("\n");
  reverse_bytes((char *) &val, sizeof(val));
  printf("rev indian val = ");
  display_bit((char *) &val, sizeof(val));
  printf("\n");
}

void	mask_test(int ac, char **av)
{
  uint8_t	bytes;

  if (ac < 2)
    {
      bytes = 0;
      bytes |= 1; //commenter 2~3 truc et tada
      bytes |= 2;
      bytes |= 4;
      bytes |= 8;
      bytes |= 16;
      bytes |= 32;
      bytes |= 64;
      bytes |= 128;
    }
  else
    bytes = atoi(av[1]);
  printf("1        ? %u\n", (bytes & 1) > 0);
  printf("2        ? %u\n", (bytes & 2) > 0);
  printf("4        ? %u\n", (bytes & 4) > 0);
  printf("8        ? %u\n", (bytes & 8) > 0);
  printf("16       ? %u\n", (bytes & 16) > 0);
  printf("32       ? %u\n", (bytes & 32) > 0);
  printf("64       ? %u\n", (bytes & 64) > 0);
  printf("128      ? %u\n", (bytes & 128) > 0);
  putchar('\n');
  printf("1 && 128 ? %u\n", (bytes & 129) == 129);
  printf("1 && 2   ? %u\n", (bytes & 3) == 3);
  printf("1 && 2   ? %u\n", (bytes & (2 | 1)) == 3);
  printf("8 && 32  ? %u\n", (bytes & (8 | 32)) == (8 | 32));
  printf("8 || 32  ? %u\n", (bytes & (8 | 32)) > 0);
  printf("8 && !32 ? %u\n", (bytes & (8 | ~32)));
}

int	main(int ac, char **av)
{
  mask_test(ac, av);
  printf("\n-----------------\n\n");
  explode_val_test(ac, av);

  return (0);
}
