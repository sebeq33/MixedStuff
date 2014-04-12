/*
** hook.h for hook.h in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov 27 14:27:19 2012 sebastien bequignon
** Last update Tue Nov 27 15:11:32 2012 sebastien bequignon
*/

#ifndef HOOK_H_
# define HOOK_H_

# define NB_HOOK (5)

typedef struct s_hook
{
  char *hook;
  int	(*func)(char *buffer, char ***envp);
} t_hook;

#endif /* !HOOK_H_ */
