/*
** main.c for main.c in /home/bequig_s//workspace/asm
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar  7 19:39:41 2013 sebastien bequignon
** Last update Fri Mar 29 19:15:45 2013 sebastien bequignon
*/

#include <stdio.h>
#include <string.h>

void mem_test()
{
  char message1[60] = "Four score and seven years ago ...";
  char message2[60] = "abcdefghijklmnopqrstuvwxyz";
  char temp[60];

  printf("----------MEMSET-----------\n");

  strcpy(temp, message1);
  printf("before my_memset():\t[%s][%1$p][%d]\n", temp, strlen(temp));
  memset(temp + 5, '@', 10);
  printf("after my_memset():\t[%s][%1$p][%d]\n", temp, strlen(temp));

  printf("\n----------MEMCPY-----------\n");

  strcpy(temp, message2);
  printf("\nOriginal message: [%s]\n", temp);
  memcpy(temp + 4, temp + 16, 10);
  printf("After my_memcpy() without overlap:  [%1$p][%s]\n", temp);
  strcpy(temp, message2);
  memcpy(temp + 6, temp + 4, 10);
  printf("After my_memcpy() with overlap:\t    [%1$p][%s]\n", temp);

  printf("\n----------MEMMOVE-----------\n");

  strcpy(temp, message2);
  printf("\nOriginal message: [%s]\n", temp);
  memmove(temp + 4, temp + 16, 10);
  printf("After my_memmove() without overlap: [%1$p][%s]\n", temp);
  strcpy(temp, message2);
  memmove(temp + 6, temp + 4, 10);
  printf("After my_memmove() with overlap:    [%1$p][%s]\n", temp);
}

void	test_strchr()
{
  char	*truc = "machin";
  char	*test = "";

  printf("%p [%1$s]\n", strchr(truc, 'v'));
  printf("%p [%1$s]\n", strchr(truc, 'c'));
  printf("%p [%1$s]\n", strchr(truc, 'm'));
  printf("%p [%1$s]\n", strchr(test, '\0'));
}

void	test_rindex()
{
  char	*truc = "machinchose";
  char	*test = "";

  printf("%p [%1$s]\n", strchr(truc, 'v'));
  printf("%p [%1$s]\n", rindex(truc, 'c'));
  printf("%p [%1$s]\n", rindex(truc, 'm'));
  printf("%p [%1$s]\n", rindex(test, '\0'));
}

void	test_strstr()
{
  char	*truc = "machinchosebidule";
  char	*test = "";

  printf("%p [%1$s]\n", strstr(truc, ""));
  printf("%p [%1$s]\n", strstr(truc, "chose"));
  printf("%p [%1$s]\n", strstr(truc, "machin"));
  printf("%p [%1$s]\n", strstr(truc, "tralala"));
  printf("%p [%1$s]\n", strstr(test, ""));
}

void test_strcmp()
{
  char *truc = "";
  char *machin = "";

  printf("strcmp(\"\", \"\") = %d\n\n", strcmp(truc, machin));

  truc = machin = "blabla";
  printf("strcmp(\"blabla\", \"blabla\") = %d\n\n", strcmp(truc, machin));

  machin = "blablatruc";
  printf("strcmp(\"blabla\", \"blablatruc\") = %d\n\n", strcmp(truc, machin));

  truc = "test";
  machin = "testa";
  printf("strcmp(\"test\", \"testa\") = %d\n\n", strcmp(truc, machin));
  printf("strcmp(\"testa\", \"test\") = %d\n\n", strcmp(machin, truc));

  truc = "testb";
  printf("strcmp(\"testb\", \"testa\") = %d\n\n", strcmp(truc, machin));

  printf("\n----------------\n\n");

  truc = "blabla";
  machin = "blablatruc";
  printf("strncmp(\"blabla\", \"blablatruc\", 6) = %d\n\n", strncmp(truc, machin, 6));
  printf("strncmp(\"blabla\", \"blablatruc\", 25) = %d\n\n", strncmp(truc, machin, 25));

  printf("\n----------------\n\n");

  machin = "blabla";
  printf("case %d\n", strcasecmp(truc, machin));

  truc = "BlabLA";
  printf("case %d\n", strcasecmp(truc, machin));

  machin = "blablb";
  printf("case %d\n", strcasecmp(truc, machin));

  truc = "123";
  machin = "1234";
  printf("case %d\n", strcasecmp(truc, machin));

  truc = "";
  machin = "";
  printf("case %d\n", strcasecmp(truc, machin));
}

int	main(int ac, char **av)
{
  test_strchr();
  printf("\n");
  test_rindex();
  printf("\n");
  test_strstr();
  printf("\n");
  test_strcmp();
  printf("\n");
  mem_test();
  /* printf("%s\n", my_strpbrk(av[1], av[2])); */
  /* printf("%s\n", strpbrk(av[1], av[2])); */
  /* printf("%u\n", my_strcspn(av[1], av[2])); */
  /* printf("%u\n", strcspn(av[1], av[2])); */
  return (0);
}
