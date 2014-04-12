/*
** main.c for my_ls in /home/bequig_s//workspace/my_ls
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct 18 17:14:17 2012 sebastien bequignon
** Last update Sat Oct 20 16:25:20 2012 sebastien bequignon
*/
#include "my_ls.h"

int	read_set_params(char *str_params, t_param *param)
{
  int	i;

  i = 0;
  while (str_params[i] != '\0')
    {
      if (str_params[i] == 'a')
	param->a = 1;
      if (str_params[i] == 'l')
	param->l = 1;
      if (str_params[i] == 'R')
	param->R = 1;
      if (str_params[i] == 'd')
	param->d = 1;
      if (str_params[i] == 'r')
	param->r = 1;
      if (str_params[i] == 't')
	param->t = 1;
      i = i + 1;
    }
}

int	manage_params(int argc, char **argv, t_param *param)
{
  int	i;
  int	path_nb;

  if (argc > 1)
    {
      i = 0;
      path_nb = 0;
      while (argv[i] != '\0')
	{
	  if (argv[i][0] == '-')
	    read_set_params(&argv[i][1], param);
	  else if (i > 1)
	    {
	      param->dirs_path[path_nb] = argv[i];
	      /*
	      if (param->dirs_path[path_nb][my_strlen(param->dirs_path[path_nb])] != '/')
		param->dirs_path[path_nb][my_strlen(param->dirs_path[path_nb]) + 1] = '/';
	      */
	      path_nb = path_nb + 1;
	    }
	  i = i + 1;
	}
      if (path_nb > 1)
	param->nb_path = path_nb;
    }
  return (0);
}

int		main(int argc, char **argv)
{
  t_param	param;

  param.a = 0;
  param.l = 0;
  param.R = 0;
  param.d = 0;
  param.r = 0;
  param.t = 0;
  param.dirs_path[0] = "./";
  my_putchar('X');
  param.nb_path = 1;
  manage_params(argc, argv, &param);
  my_ls(&param);
}
