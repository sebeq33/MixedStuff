/*
** read_cmd.c for read_cmd.c in /home/bequig_s//workspace/module-Unix/minishell2
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Wed Nov 28 11:25:41 2012 sebastien bequignon
** Last update Wed Nov 28 11:30:39 2012 sebastien bequignon
*/

#include <unistd.h>
#include "minilib/my.h"
#include "minishell.h"
#include "func_prototype.h"

int	read_cmd(char buffer[BUFFER_WIDTH + 1], char **envp)
{
  int	ret;

  my_putstr(COLOR_PROMPT);
  my_putstr(PROMPT);
  my_putstr(COLOR_DEFAULT);
  if ((ret = read(0, buffer, BUFFER_WIDTH)) < 0)
    {
      print_func_error("read()");
      return (0);
    }
  if (ret > COMMAND_LIMIT)
    {
      free_tab(envp);
      print_exit_error(INPUT_TOO_LONG);
    }
  buffer[ret] = '\0';
  return (1);
}
