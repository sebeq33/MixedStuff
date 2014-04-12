/*
** print_errors.c for print_errors.c in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 12:00:35 2012 sebastien bequignon
** Last update Tue Nov 27 15:18:23 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include "func_prototype.h"
#include "minilib/my.h"
#include "minishell.h"

void	display_error(char *error)
{
  while (*error)
    write(2, error++, 1);
}

void	print_exit_error(char *error)
{
  my_putstr(COLOR_ERROR);
  display_error(error);
  display_error("\n");
  my_putstr(COLOR_DEFAULT);
  exit(0);
}

void	print_func_error(char *error)
{
  my_putstr(COLOR_WARNING);
  display_error(error);
  display_error("\n");
  my_putstr(COLOR_DEFAULT);
}

void	print_file_error(char *file, char *error)
{
  my_putstr(COLOR_WARNING);
  display_error(file);
  display_error(": ");
  display_error(error);
  display_error("\n");
  my_putstr(COLOR_DEFAULT);
}
