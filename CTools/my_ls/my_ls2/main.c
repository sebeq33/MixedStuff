/*
** main.c for my_ls in /home/bequig_s//workspace/my_ls
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct 18 17:14:17 2012 sebastien bequignon
** Last update Sun Nov  4 16:03:23 2012 sebastien bequignon
*/

#include "headers/my_ls.h"
#include "headers/func_prototype.h"
#include <stdlib.h>


#include "headers/file.h"
#include "minilib/my.h"
void		disp_f(t_file *list)
{
  while (list != NULL)
    {
      my_putstr(list->f_name);
      list = list->next;
      my_putchar(' ');
    }
  my_putchar('\n');
}





void		init_params(t_param *params)
{
  params->a = 0;
  params->i = 0;
  params->l = 0;
  params->R = 0;
  params->d = 0;
  params->r = 0;
  params->t = 0;
  params->U = 0;
  params->color = 0;
  params->mult_path = 0;
}

int		main(int ac, char **av)
{
  t_param	params;

  init_params(&params);
  manage_params(ac, av, &params);
  my_ls(&params, ac, av);
  return (0);
}
