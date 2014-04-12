/*
** func_ptr.c for func_ptr.c in /home/bequig_s//workspace/piscine-Tek2/d02m/ex03
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Jan 10 10:12:54 2013 sebastien bequignon
** Last update Thu Jan 10 10:49:04 2013 sebastien bequignon
*/

#include <stdio.h>
#include <string.h>
#include "func_ptr_enum.h"
#include "func_ptr.h"

static t_hook tab_p[NB_PARAM] =
  {
    {PRINT_NORMAL, &print_normal},
    {PRINT_REVERSE, &print_reverse},
    {PRINT_UPPER, &print_upper},
    {PRINT_42, &print_42}
  };


void print_normal(char *str)
{
  printf(str);
  putchar('\n');
}

void print_reverse(char *str)
{
  int	i;

  i = strlen(str) - 1;
  while (i >= 0)
    putchar(str[i--]);
  putchar('\n');
}

void print_upper(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 97 && str[i] <= 122)
	putchar(str[i] - 32);
      else
	putchar(str[i]);
      i++;
    }
  putchar('\n');
}

void print_42(char *str)
{
  if (str || !str)
    printf("42\n");
}

void do_action(t_action action, char *str)
{
  int	i;

  i = 0;
  while (i < NB_PARAM)
    {
      if (tab_p[i].action == action)
	tab_p[i].ptr(str);
      i++;
    }
}
