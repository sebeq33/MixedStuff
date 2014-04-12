/*
** display.c for my_ls in /home/bequig_s//workspace/my_ls/my_ls_fini
** 
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
** 
** Started on  Sat Oct 20 14:30:01 2012 sebastien bequignon
** Last update Sun Oct 21 17:29:27 2012 sebastien bequignon
*/

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my_ls.h"

void	print_mode(mode_t *m)
{
  if (S_ISDIR(*m))
    my_putchar('d');
  else if (S_ISSOCK(*m))
    my_putchar('s');
  else if (S_ISLNK(*m))
    my_putchar('l');
  else if (S_ISCHR(*m))
    my_putchar('c');
  else if (S_ISFIFO(*m))
    my_putchar('p');
  else if (S_ISBLK(*m))
    my_putchar('b');
  else
    my_putchar('-');
  my_putchar(*m & S_IRUSR ? 'r' : '-');
  my_putchar(*m & S_IWUSR ? 'w' : '-');
  my_putchar(*m & S_IXUSR ? 'x' : '-');
  my_putchar(*m & S_IRGRP ? 'r' : '-');
  my_putchar(*m & S_IWGRP ? 'w' : '-');
  my_putchar(*m & S_IXGRP ? 'x' : '-');
  my_putchar(*m & S_IROTH ? 'r' : '-');
  my_putchar(*m & S_IWOTH ? 'w' : '-');
  my_putchar(*m & S_IXOTH ? 'x' : '-');
}

void			print_detail(struct stat *file_stat)
{
  struct passwd		*passwd;
  struct group		*group;

  passwd = getpwuid(file_stat->st_uid);
  group = getgrgid(file_stat->st_gid); 
  print_mode(&file_stat->st_mode);
  my_putchar(' ');
  my_put_nbr((int) file_stat->st_nlink);
  my_putchar(' ');
  my_putstr(passwd->pw_name);
  my_putchar(' ');
  my_putstr(group->gr_name);
  my_putchar(' ');
  my_put_nbr((int) file_stat->st_size);
  my_putchar(' ');
  my_putstr(ctime(&file_stat->st_mtime));
  my_putchar(' ');
}

char			*get_file_path(char *dir_path, char *d_name)
{
  char			*file_path;
  int			nbchar;

  nbchar = (my_strlen(dir_path) + my_strlen(d_name)) * sizeof(char);
  file_path = malloc(nbchar);
  my_strcpy(file_path, dir_path);
  my_strcat(file_path, d_name);
  return (file_path);
}

void			display_file(char *dir_path, struct dirent *dirent,
				     t_param *param)
{
  char			*file_path;
  struct stat		file_stat;

  if (param->l)
    {
      file_path = get_file_path(dir_path, dirent->d_name);
      if (lstat(file_path , &file_stat) != -1)
	{
	 print_detail(&file_stat);
	 free(file_path);
	}
      else
	{
	  perror("Error on stat() on main()");
	  exit(EXIT_FAILLURE);
	}
    }
  my_putstr(dirent->d_name);
}
