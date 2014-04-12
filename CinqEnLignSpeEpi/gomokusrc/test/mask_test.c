/*
** main.c for main.c in /tmp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri May 10 16:15:27 2013 sebastien bequignon
** Last update Tue Jun 25 17:34:44 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>

//----- ENDIAN

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


//----- BIT

void	display_bit(char *bytes, size_t size)
{
  int32_t	i;

  while (size > 0)
    {
      i = 7;
      while (i >= 0)
	{
	  putchar((((bytes[size - 1]) >> i) & 0x01) + '0');
	  i--;
	}
      size--;
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

//------ MASK

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

void	maskmodif(int ac, char **av)
{
  (void) ac;
  (void) av;
  /* modifie de façon ciblé 15 des 32 bits de l'uint32_t */
  uint32_t	default_val = 2147483647;
  uint16_t	param = 55;
  uint32_t	mask = ~(32767 << 15); //32767 = 15 bit a 1
  uint32_t	newval = ((uint32_t) param) << 15;

  //affiche les valeur actuel
  display_bit((char *) &default_val, sizeof(default_val));
  printf("\n");
  display_bit((char *) &mask, sizeof(mask));
  printf("\n");

  //on remplace les bit 17 a 32 de default par param actuellement dans newval
  default_val = (default_val & mask) | newval;

  //on affiche le resultat complet
  display_bit((char *) &default_val, sizeof(default_val));
  printf("\n");

  //on affiche seul les 15 bit modifié;
  default_val = (default_val >> 15) & 32767;
  display_bit((char *) &default_val, sizeof(default_val));
  printf("\n");

}

void	mask_check1(int ac, char **av)
{
  (void) ac;
  (void) av;
  uint32_t tmp		= 0;
  uint32_t align	= 64764; //001111110011111100 align de 3 de chaque cote a matcher
  uint32_t val1		= 252;	 //000000000011111100 align de 3 a droite
  uint32_t val2		= 64512; //001111110000000000 align de 3 a gauche
  uint32_t val3		= 61440; //001111000000000000 fausse valeur ne devant pas match

  printf("val1 ? %u\n", ((val1 & val2) ^ val1));
  printf("val1 ? %u\n", ((val1 & val1) ^ val1));

  printf("val2 ? %u\n", ((val2 & val2) ^ val2));
  printf("val2 ? %u\n", ((val2 & val1) ^ val2));

  printf("val3 ? %u\n", ((val3 & val2) ^ val3)); //error
  printf("val3 ? %u\n", ((val3 & val2) ^ val2)); //ok
  printf("val3 ? %u\n", ((val3 & val1) ^ val3));

  printf("val3 : "); display_bit((char *) &val3, sizeof(val3)); putchar('\n');
  tmp = (val3 & val2);
  printf("tmp  : "); display_bit((char *) &tmp, sizeof(tmp)); putchar('\n');
  tmp = ((val3 & val2) ^ val3);
  printf("tmp  : "); display_bit((char *) &tmp, sizeof(tmp)); putchar('\n');
  tmp = ((val3 & val2) ^ val2);
  printf("tmp  : "); display_bit((char *) &tmp, sizeof(tmp)); putchar('\n');
  putchar('\n');

  printf("val1 ? %u\n", ((val1 & val2) ^ val2) == 0 || ((val1 & val1) ^ val1) == 0); //true
  printf("val2 ? %u\n", ((val2 & val2) ^ val2) == 0 || ((val2 & val1) ^ val1) == 0); //true
  printf("val3 ? %u\n", ((val3 & val2) ^ val1) == 0 || ((val3 & val1) ^ val1) == 0); //false
}

void	mask_check2(int ac, char **av)
{
  (void) ac;
  (void) av;
  uint16_t	patternVal;
  uint16_t	srcVal;
  uint8_t	patternSize;
  uint8_t	srcSize;

  patternSize = 10;
  patternVal = 0b0101010101; //align de 5 noir
  srcVal = 0b0101010101; //noir noir noir noir noir
  printf("result = %d\n", ((srcVal & ~(~0 << patternSize)) ^ patternVal) == 0);

  patternSize = 8;
  patternVal = 0b01010101;
  srcVal = 0b1101010101;
  //on precise le pattern pour match uniquement les 8 derniers bits
  printf("result = %d\n", ((srcVal & ~(~0 << patternSize)) ^ patternVal) == 0);
  putchar('\n');

  patternVal = 0b0001010101;
  printf("mask : "); display_bit((char *) &patternVal, sizeof(patternVal)); putchar('\n');

  srcVal = 0b1001010101; //blanc noir noir noir noir
  printf("src  : "); display_bit((char *) &srcVal, sizeof(srcVal)); putchar('\n');
  // should be false because patternVal(00...) && srcVal(10...)
  printf("result = %d\n", (srcVal ^ patternVal) == 0);

  srcVal = 0b0001010101; //vide noir noir noir noir
  printf("src  : "); display_bit((char *) &srcVal, sizeof(srcVal)); putchar('\n');
  printf("result = %d\n", (srcVal ^ patternVal) == 0); //true
}

void	mask_check2(int ac, char **av)
{
  (void) ac;
  (void) av;
  uint32_t check   = 0b00000000000000000000000000011001; // 110 = pattern 5
  uint32_t mask    = 0b00000011011011011011011011011000; // check pattern 5 in 8 direction
  uint32_t pattern = 0b00000000000000000000000000000110; // searched
}

int	main(int ac, char **av)
{
  /* mask_test(ac, av); */
  /* printf("\n-----------------\n\n"); */
  /* explode_val_test(ac, av); */
  /* printf("\n-----------------\n\n"); */
  /* maskmodif(ac, av); */
  /* printf("\n-----------------\n\n"); */
  /* mask_check1(ac, av); */
  /* printf("\n-----------------\n\n"); */
  /* mask_check2(ac, av); */
  /* printf("\n-----------------\n\n"); */
  mask_check3(ac, av);
  return (0);
}
