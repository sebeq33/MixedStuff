/*
** file.h for my_ls in /home/bequig_s//workspace/my_ls/my_ls2/headers
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Thu Nov  1 16:17:49 2012 sebastien bequignon
** Last update Sun Nov  4 19:17:06 2012 sebastien bequignon
*/

#ifndef FILE_
# define FILE_

#include <time.h>

typedef struct s_file
{
  int		inode;
  char		*path;
  char		mode[11];
  char		*f_name;
  int		nb_link;
  char		*u_name;
  char		*g_name;
  int		size;
  int		nb_blocks;
  time_t	time;
  char		*symb_link;
  struct s_file *next;
} t_file;

#endif /* FILE_ */
