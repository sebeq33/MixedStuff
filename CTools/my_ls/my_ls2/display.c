/*
** display.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls_fini
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Oct 20 14:30:01 2012 sebastien bequignon
** Last update Sun Nov  4 20:52:04 2012 sebastien bequignon
*/

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "headers/my_ls.h"
#include "headers/file.h"
#include "minilib/my.h"

void			print_time(time_t time)
{
  char		*char_time;
  int		i;

  i = 0;
  char_time = ctime(&time);
  char_time[my_strlen(char_time) - 9] = '\0';
  while (char_time[i] != ' ' && char_time[i] != '\0')
    i = i + 1;
  char_time = &char_time[i + 1];
  my_putstr(char_time);
}

void			print_detail(t_file *file)
{
  my_putstr(file->mode);
  my_putchar(' ');
  my_put_nbr(file->nb_link);
  my_putchar(' ');
  my_putstr(file->u_name);
  my_putchar(' ');
  my_putstr(file->g_name);
  my_putchar(' ');
  my_put_nbr(file->size);
  my_putchar(' ');
  print_time(file->time);
  my_putchar(' ');
  if (file->mode[0] == 'l')
    {
      my_putstr("-> ");
      my_putstr(file->symb_link);
    }
}

void			display_file(t_file *file, t_param *param)
{
  if (param->i)
    {
      my_put_nbr(file->inode);
      my_putchar(' ');
    }
  if (param->l)
    print_detail(file);
  my_putstr(file->f_name);
}
