/*
** my_ftp.h for my_ftp.h in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Apr 11 04:27:22 2013 sebastien bequignon
** Last update Sun Apr 14 17:42:54 2013 sebastien bequignon
*/

#ifndef SERVER_H_
# define SERVER_H_

# define NB_ACTIONS (5)

typedef struct	s_hook
{
  char		*hook;
  int		(*func)(int fd_client, char **cmd, char *limit);
}		t_hook;

char	**my_str_to_wordtab(char *, char *);
int	wordtab_len(char **wt);
void	free_wordtab(char **tab);
int	my_cd(int fd_client, char **cmd, char *limit);
int	my_pwd(int fd_client, char **cmd, char *limit);
int	my_ls(int fd_client, char **cmd, char *limit);
int	my_put_file(int fd_client, char **cmd);
int	my_get_file(int fd_client, char **cmd);
int	my_put_file_server(int fd_client, char **cmd, char *limit);
int	my_get_file_server(int fd_client, char **cmd, char *limit);
char	*get_file_path(char *d_name);
int	my_putstr_fd(int fd, char *str);
int	my_puterr(char *str);
void	listen_clients(int sock, char *limit);
int	execute_command(int client_fd, char *line, char *limit);
int	valid_path(char *dest, char *limit);
int	my_getnbr(char *str);

#endif /* !SERVER_H_ */
