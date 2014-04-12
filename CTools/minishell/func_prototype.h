/*
** func_prototype.h for func_prototype.h in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 16:55:37 2012 sebastien bequignon
** Last update Wed Nov 28 11:33:28 2012 sebastien bequignon
*/

#ifndef FUNC_PROTOTYPE_H_
# define FUNC_PROTOTYPE_H_

char	**prepare_parse_cmd(char **params, char *str);
int	exec_forked(char *, char **, char **);
int	test_all_paths_exec(char **params, char **envp, char *paths);
char	*test_path_exec(char *exec_name, char *path, int path_size);
int	search_exec(char **params, char **envp);
int	read_cmd(char[], char **);
void	free_tab(char **);
char	**copy_env(char **envp);
int	count_var_lines(char **envp);
char	*create_env(char *str);
char	*get_file_path(char *exec_name, char *dir_path, int path_size);
char	*get_part_string(char *to_copy, int nb_char);
void	print_exit_error(char *);
void	print_func_error(char *);
void	print_file_error(char *, char *);
int	get_env_line(char **envp, char *to_search);
void	add_env(char *buffer, char ***envp);
void	delete_env(char ***envp, int line_to_supr);
int	display_env(char *, char ***envp);
int	change_dir(char *buffer, char ***envp);
int	set_env(char *buffer, char ***envp);
int	unset_env(char *buffer, char ***envp);
int	exit_cleanly(char *, char ***envp);
int	special_cmd(char *, char ***);

#endif /* !FUNC_PROTOTYPE_H_ */
