/*
** client.h for client.h in /home/bequig_s//workspace/systemUnixTek2/ftp/ftp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Apr 13 14:17:19 2013 sebastien bequignon
** Last update Sun Apr 14 17:43:16 2013 sebastien bequignon
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# define NB_ACTIONS (5)

typedef struct	s_hook
{
  char		*hook;
  int		(*func)(int fd_client, char **cmd);
}		t_hook;

char	**my_str_to_wordtab(char *, char *);
int	wordtab_len(char **wt);
void	free_wordtab(char **tab);
int	client_ls(int fd_client, char **cmd);
int	client_read_line(int server, char **cmd);
int	my_put_file(int fd_client, char **cmd);
int	my_get_file(int fd_client, char **cmd);
void	launch_client(int server);
int	my_putstr_fd(int fd, char *str);
int	my_puterr(char *error);
char	*my_epur_str(char *str);
int	my_getnbr(char *str);

#endif /* !CLIENT_H_ */
