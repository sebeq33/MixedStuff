/*
** manage_param.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov  1 13:37:28 2012 sebastien bequignon
** Last update Sun Nov  4 16:21:54 2012 sebastien bequignon
*/

#include "headers/my_ls.h"
#include "minilib/my.h"
#include <stdlib.h>

void	display_param_error(char c)
{
  my_putstr("ls: invalid option '");
  my_putchar(c);
  my_putstr("'\n");
  exit(0);

}

void	read_set_params2(char param_char, t_param *param)
{
  if (param_char == 'U')
    param->U = 1;
  else
    display_param_error(param_char);
}

void	read_set_params(char param_char, t_param *param)
{
    if (param_char == 'a')
      param->a = 1;
    else if (param_char == 'i')
      param->i = 1;
    else if (param_char == 'l')
      param->l = 1;
    else if (param_char == 'd')
      param->d = 1;
    else if (param_char == 'r')
      param->r = 1;
    else if (param_char == 't')
      param->t = 1;
    else if (param_char == 'f')
      {
	param->a = 1;
	param->U = 1;
      }
    else if (param_char == 'R')
      {
	param->mult_path = 1;
	param->R = 1;
      }
    else
      read_set_params2(param_char, param);
}

void	manage_params(int ac, char **av, t_param *param)
{
  int	i;
  int	j;
  int	nb_path;

  if (ac < 2)
    return ;
  i = 1;
  nb_path = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	if (my_strcmp(&av[i][1], "-color") == 0)
	  param->color = 1;
	else
	  {
	    j = 1;
	    while (av[i][j] != '\0')
	      read_set_params(av[i][j++], param);
	  }
      else
	nb_path++;
      i++;
    }
  if (nb_path > 1)
    param->mult_path = 1;
}
