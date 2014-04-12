/*
** my_ls.h for my_ls in /home/bequig_s//workspace/my_ls/my_ls_fini
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Sat Oct 20 14:48:11 2012 sebastien bequignon
** Last update Sat Oct 20 16:15:07 2012 sebastien bequignon
*/

#ifndef MY_LS_
#define MY_LS_

struct s_param
{
  int a;
  int l;
  int R;
  int d;
  int r;
  int t;
  char **dirs_path;
  int nb_path;
};

typedef struct s_param t_param;

#endif
