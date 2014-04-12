/*
** my_ls.h for my_ls in /home/bequig_s//workspace/my_ls/my_ls_fini
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Sat Oct 20 14:48:11 2012 sebastien bequignon
** Last update Sun Nov  4 16:01:03 2012 sebastien bequignon
*/

#ifndef MY_LS_
# define MY_LS_

#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

typedef struct s_param
{
  int a;
  int i;
  int l;
  int R;
  int d;
  int r;
  int t;
  int U;
  int color;
  int mult_path;
} t_param;

#endif /* MY_LS_ */
