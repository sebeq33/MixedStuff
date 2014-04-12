/*
** main.c for main.c in /home/bequig_s//workspace/piscine-Tek2/d02m/ex03
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Jan 10 10:40:47 2013 sebastien bequignon
** Last update Thu Jan 10 10:52:41 2013 sebastien bequignon
*/

#include "func_ptr_enum.h"
#include "func_ptr.h"

int main(void)
{
  char *str = "azertyuiopqsdfghjklAZERTYUIOSDFGHJK6515614454";

  do_action(PRINT_NORMAL, str);
  do_action(PRINT_REVERSE, str);
  do_action(PRINT_UPPER, str);
  do_action(PRINT_42, str);

  return (0);
}
