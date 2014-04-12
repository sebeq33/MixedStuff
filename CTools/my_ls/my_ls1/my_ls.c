/*
** my_ls.c for my_ls in /home/bequig_s//workspace/my_ls
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Oct 18 17:14:17 2012 sebastien bequignon
** Last update Sat Oct 20 16:37:33 2012 sebastien bequignon
*/

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_ls.h"

int			my_ls(t_param *param)
{
  struct dirent		*dirent;
  DIR			*dir;
  
  dir = opendir(param->dir_path);
  if (dir != NULL)
    dirent = readdir(dir);
  while (dirent != NULL)
    {
      if (dirent->d_name[0] != '.' || param->a)
	{
	  display_file(param->dir_path, dirent, param);
	  if (param->l)
	    my_putchar('\n');
	  else if (readdir(dir) != 0)
	    my_putchar(' ');
	}
      dirent = readdir(dir);
    }
  my_putchar('\n');
  return (0);
}

