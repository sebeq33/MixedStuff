/*
** manage_file.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov  1 15:59:14 2012 sebastien bequignon
** Last update Sun Nov  4 21:24:24 2012 sebastien bequignon
*/

#include "headers/file.h"
#include "headers/func_prototype.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

void	set_mode(mode_t *m, char mode[11])
{
  if (S_ISDIR(*m))
    mode[0] = 'd';
  else if (S_ISSOCK(*m))
    mode[0] = 's';
  else if (S_ISLNK(*m))
    mode[0] = 'l';
  else if (S_ISCHR(*m))
    mode[0] = 'c';
  else if (S_ISFIFO(*m))
    mode[0] = 'p';
  else if (S_ISBLK(*m))
    mode[0] = 'b';
  else
    mode[0] = '-';
  mode[1] = *m & S_IRUSR ? 'r' : '-';
  mode[2] = *m & S_IWUSR ? 'w' : '-';
  mode[3] = *m & S_IXUSR ? 'x' : '-';
  mode[4] = *m & S_IRGRP ? 'r' : '-';
  mode[5] = *m & S_IWGRP ? 'w' : '-';
  mode[6] = *m & S_IXGRP ? 'x' : '-';
  mode[7] = *m & S_IROTH ? 'r' : '-';
  mode[8] = *m & S_IWOTH ? 'w' : '-';
  mode[9] = *m & S_IXOTH ? 'x' : '-';
  mode[10] = '\0';
}

void		set_values(struct dirent *dirent, struct stat *stat,
			   t_file *file)
{
  struct passwd		*passwd;
  struct group		*group;

  passwd = getpwuid(stat->st_uid);
  group = getgrgid(stat->st_gid);
  file->f_name = dirent->d_name;
  file->inode = dirent->d_ino;
  file->nb_link = stat->st_nlink;
  file->u_name = passwd == NULL ? "225" : passwd->pw_name;
  file->g_name = group == NULL ? "26" : group->gr_name;
  file->size = stat->st_size;
  file->time = stat->st_mtime;
  file->next = NULL;
  file->nb_blocks = stat->st_blocks;
}

char		*get_symb_link(char *file_path, int size)
{
  int		ret;
  char		*symb_lnk;

  symb_lnk = malloc(size + 1);
  if (symb_lnk == NULL)
    {
      perror("get_symb_link(): malloc");
      exit(0);
    }
  ret = readlink(file_path, symb_lnk, size + 1);
  if (ret == -1)
    {
      free(symb_lnk);
      return (NULL);
    }
  symb_lnk[size] ='\0';
  return (symb_lnk);
}

t_file		*init_file(t_file *file, char *dir_path, 
			   struct dirent *dirent, t_param *param)
{
  struct stat	stat;

  file->path = get_file_path(dir_path, dirent->d_name);
  if (lstat(file->path , &stat) == -1)
    {
      perror("create_file(): stat()");
      free(file);
      return (NULL);
    }
  set_mode(&stat.st_mode, file->mode);
  if (file->mode[0] == 'l' && param->l)
    {
      file->symb_link = get_symb_link(file->path, stat.st_size);
      if (file->symb_link == NULL)
	{
	  free(file);
	  free(file->path);
	  perror("create_file(): readlink()");
	  return (NULL);
	}
    }
  else
    file->symb_link = NULL;
  set_values(dirent, &stat, file);
  return (file);
}

t_file		*create_file(char *dir_path, struct dirent *dirent, 
			     t_param *param)
{
  t_file	*file;

  file = malloc(sizeof(*file));
  if (file == NULL)
    {
      perror("create_file(): malloc()");
      return (NULL);
    }
  return (init_file(file, dir_path, dirent, param));
}
