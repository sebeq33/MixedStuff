/*
** free_exit.c for free_exit.c in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 28 11:22:46 2012 sebastien bequignon
** Last update Wed Nov 28 15:10:42 2012 sebastien bequignon
*/

#include <stdlib.h>
#include "minilib/my.h"

int	display_env(char *buffer, char ***env)
{
  int	i;
  char	**envp;

  i = 0;
  envp = *env;
  while (envp[i] != NULL)
    {
      my_putstr(envp[i]);
      my_putchar('\n');
      i++;
    }
  return (1);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  if (tab != NULL)
    free(tab);
}

int		exit_cleanly(char *buffer, char ***tab)
{
  free_tab(*tab);
  exit(0);
  return (0);
}

