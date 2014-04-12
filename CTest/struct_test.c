/*
** struct_test.c for struct_test.c in /home/bequig_s//workspace/test_perso
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed May 29 15:31:31 2013 sebastien bequignon
** Last update Wed May 29 16:02:02 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_plop
{
  int		a : 8;
  int		b : 16;
  int		c : 24;
  char		d : 1;
  unsigned char e : 1;
}		t_plop;

typedef union
{
  unsigned long		all;
  t_plop		plop;
  char			tada[8];
}			u_machin;

void	display_bit(char *bytes, size_t nb_bit)
{
  size_t	i;
  int8_t	j;

  i = 0;
  while (nb_bit > 0)
    {
      j = 7;
      while (nb_bit > 0 && j >= 0)
	{
	  putchar((((bytes[i]) >> j) & 0x01) + '0');
	  j--;
	  nb_bit--;
	}
      if (nb_bit > 0)
	putchar(' ');
      i++;
    }
  /* printf("\nnb = %d\n", i); */
}

int	main(int ac, char **av)
{
  u_machin machin;
  t_plop *plop = &machin.plop;

  machin.all = 0;

  plop->a = 1;
  plop->b = 1;
  plop->c = 1;
  plop->d = 1;
  plop->e = 1;

  printf("Size %lu\n", sizeof(plop));
  display_bit(machin.tada, sizeof(machin) * 8);
  printf("\n");

  /* printf("Size %lu\n", sizeof(plop.a)); */
  /* printf("Size %lu\n", sizeof(plop.b)); */
  /* printf("Size %lu\n", sizeof(plop.c)); */
  /* printf("Size %lu\n", sizeof(plop.d)); */
  /* printf("Size %lu\n", sizeof(plop.e)); */

  /* display_bit((char *) &plop.a, 8); */
  /* printf("\n"); */
  /* display_bit((char *) &plop.b, 16); */
  /* printf("\n"); */
  /* display_bit((char *) &plop.c, 24); */
  /* printf("\n"); */
  /* display_bit((char *) &plop.d, 1); */
  /* printf("\n"); */
  /* display_bit((char *) &plop.e, 1); */

  return (0);
}
