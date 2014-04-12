/*
** main.c for main in /exam//rendu/ex_4
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Dec  8 13:48:29 2012 sebastien bequignon
** Last update Sat Mar 16 02:47:42 2013 sebastien bequignon
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	perror_exit(char *str)
{
  perror(str);
  exit(0);
}

int	count_word(char *cmd)
{
  int	i;

  i = 0;
  while (*cmd)
    {
      while (*cmd == ' ' || *cmd == '\t')
	cmd++;
      if (*cmd)
	{
	  i++;
	  while (*cmd && *cmd != ' ' && *cmd != '\t')
	    cmd++;
	}
    }
  return (i);
}

char	**wordtab(char *cmd) // vieux wordtab sans copie
{
  char	**wtab;
  int	i;

  if ((wtab = malloc((count_word(cmd) + 1) * sizeof(char *))) == NULL)
    perror_exit("malloc");
  i = 0;
  while (*cmd)
    {
      while (*cmd == ' ' || *cmd == '\t')
	cmd++;
      if (*cmd)
	{
	  wtab[i++] = cmd;
	  while (*cmd && *cmd != ' ' && *cmd != '\t')
	    cmd++;
	  if (*cmd)
	    *cmd++ = '\0';
	}
    }
  wtab[i] = 0;
  return (wtab);
}

void	sopipa(int fd_src, char *cmd1, char *cmd2, int fd_dest)
{
  char	**av;
  int	pid;
  int	pipe_fd[2];

  if (pipe(pipe_fd) == -1)
    perror_exit("pipe");
  if ((pid = fork()) == -1)
    perror_exit("fork");
  if (pid == 0)
    {
      // ls or cat
      close(pipe_fd[0]);
      av = wordtab(cmd1);
      dup2(fd_src, 0);
      dup2(pipe_fd[1], 1);
      execvp(av[0], av);
      exit(0);
    }
  else
    {
      // grep or wc
      close(pipe_fd[1]);
      av = wordtab(cmd2);
      dup2(pipe_fd[0], 0);
      dup2(fd_dest, 1);
      execvp(av[0], av);
      exit(0);
    }
}

int	main(int ac, char **av)
{
  int	fd_src;
  int	fd_dest;

  if (ac != 5)
    return (0);
  if ((fd_src = open(av[1], O_RDONLY | O_CREAT)) == -1)
    return (1);
  if ((fd_dest = open(av[4], O_WRONLY | O_CREAT | O_TRUNC)) == -1)
    {
      close(fd_src);
      return (1);
    }
  sopipa(fd_src, av[2], av[3], fd_dest);
  close(fd_src);
  close(fd_dest);
  return (0);
}
