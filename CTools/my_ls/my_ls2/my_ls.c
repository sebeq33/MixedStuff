/*
** my_ls.c for my_ls in /home/bequig_s//workspace/my_ls
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Oct 18 17:14:17 2012 sebastien bequignon
** Last update Sun Nov  4 23:00:24 2012 sebastien bequignon
*/

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "headers/my_ls.h"
#include "headers/file.h"
#include "headers/func_prototype.h"
#include "minilib/my.h"

void	display_file_list(char *dir_path, t_file *file_list,
			  t_param *param, int nb_blocks)
{
  int	start;

  start = 1;
  if (param->l)
    {
      my_putstr("total ");
      my_put_nbr(nb_blocks / 2);
      my_putchar('\n');
    }
  while	(file_list != NULL)
    {
      if (!start)
	{
	  if (param->l)
	    my_putchar('\n');
	  else
	    my_putstr("  ");
	}
      start = 0;
      display_file(file_list, param);
      delete_first_file_node(&file_list);
    }
  my_putchar('\n');
}

void		display_dir_files(DIR *dir, t_list **dir_list,
					  char *dir_path, t_param *param)
{
  struct dirent *dirent;
  t_list	*new_dir_list;
  t_file	*file_list;
  t_file	*file;
  int		nb_blocks;

  file_list = NULL;
  new_dir_list = NULL;
  nb_blocks = 0;
  while ((dirent = readdir(dir)) != NULL)
    {
      if (dirent->d_name[0] != '.' || param->a)
	if ((file = create_file(dir_path, dirent, param)) != NULL)
	  {
	    nb_blocks += file->nb_blocks;
	    add_file_to_list(&file_list, file, param);
	    if (param->R && file->mode[0] == 'd' &&
		my_strcmp(file->f_name, ".") != 0 &&
		my_strcmp(file->f_name, "..") != 0)
	      add_dir_to_list_end(&new_dir_list, create_node_copy(file->path));
	  }
      }
  display_file_list(dir_path, file_list, param, nb_blocks);
  display_dir(param, new_dir_list, 0);
}

void		display_dir(t_param *param, t_list *dir_list, int start)
{
  DIR		*dir;

  while (dir_list != NULL)
    {
      dir = opendir(dir_list->data);
      if (dir != NULL)
	{
	  if (param->mult_path && !start)
	    my_putchar('\n');
	  if (param->mult_path)
	    {
	      my_putstr(dir_list->data);
	      my_putstr(":\n");
	    }
	  display_dir_files(dir, &dir_list, dir_list->data, param);
	  if (closedir(dir) == -1)
	    perror("Error : closedir()");
	}
      else
	perror("Error : opendir()");
      delete_first_dir_node(&dir_list);
    }
}

void		my_ls(t_param *param, int ac, char **av)
{
  int		i;
  int		path_in_param;

  i = 1;
  path_in_param = 0;
  while (i < ac)
    {
      if (av[i][0] != '-')
	{
	  if (path_in_param)
	    my_putstr("\n");
	  display_dir(param, create_dir_node(my_strdup(av[i])), path_in_param);
	  path_in_param = 1;
	}
      i++;
    }
  if (!path_in_param)
    display_dir(param, create_dir_node(my_strdup("./")), 1);
}

