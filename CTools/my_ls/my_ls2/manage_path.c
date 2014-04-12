/*
** manage_path.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Oct 31 10:43:26 2012 sebastien bequignon
** Last update Sun Nov  4 21:11:34 2012 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include "minilib/my.h"

char		*get_file_path(char *dir_path, char *d_name)
{
  char		*f_path;
  int		size;
  int		path_size;
  int		have_slash;

  path_size = my_strlen(dir_path);
  have_slash = dir_path[path_size - 1] == '/';
  size = path_size + my_strlen(d_name) + 1 + !have_slash;
  f_path = malloc(size * sizeof(char));
  if (f_path == NULL)
    {
      perror("get_file_path : malloc");
      exit(0);
    }
  my_strcpy(f_path, dir_path);
  if (!have_slash)
    {
      f_path[path_size] = '/';
      path_size++;
    }
  f_path[path_size] = '\0';
  my_strcat(f_path, d_name);
  f_path[size - 1] = '\0';
  return (f_path);
}


