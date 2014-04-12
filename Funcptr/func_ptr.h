/*
** func_ptr.h for func_ptr.h in /home/bequig_s//workspace/piscine-Tek2/d02m/ex03
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Jan 10 10:35:51 2013 sebastien bequignon
** Last update Thu Jan 10 10:45:08 2013 sebastien bequignon
*/

#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

#include "func_ptr_enum.h"

# define NB_PARAM (4)

typedef struct
{
  t_action	action;
  void (*ptr)(char *);
}	t_hook;

void print_normal(char *str);
void print_reverse(char *str);
void print_upper(char *str);
void print_42(char *str);
void do_action(t_action action, char *str);

#endif /* !FUNC_PTR_H_ */
