/*
** func_prototype.h for my_ls in /home/bequig_s//workspace/my_ls/my_ls2/headers
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Nov  1 21:37:17 2012 sebastien bequignon
** Last update Sun Nov  4 22:13:24 2012 sebastien bequignon
*/

#ifndef FUNC_PROTOTYPE
# define FUNC_PROTOTYPE

#include <dirent.h>
#include <sys/stat.h>
#include "file.h"
#include "my_ls.h"

void		set_mode(mode_t *m, char mode[11]);
t_file		*create_file(char *, struct dirent *, t_param *);
char		*get_file_path(char *dir_path, char *d_name);
void		add_file_to_list_end(t_file **list, t_file *to_add);
void		my_ls(t_param *param, int ac, char **av);
void		manage_params(int ac, char **av, t_param *param);
void		display_file_list(char *, t_file *, t_param *, int);
void		display_dir_files(DIR *, t_list **, char *, t_param *);
void		display_dir(t_param *param, t_list *dir_list, int start);
void		add_file_to_list_end(t_file **list, t_file *to_add);
void		delete_first_file_node(t_file **list);
t_list		*create_dir_node(void *data);
t_list		*create_node_copy(char *data);
void		add_dir_to_list_end(t_list **list, t_list *to_add);
void		display_file(t_file *file, t_param *param);
void		add_file_to_list(t_file **list, t_file *file, t_param *param);
void		delete_first_dir_node(t_list **list);
int		my_strcmp_ls(char *s1, char *s2);

#endif /* FUNC_PROTOTYPE */
