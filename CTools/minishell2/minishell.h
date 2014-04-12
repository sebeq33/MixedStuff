/*
** minishell.h for minishell.h in /home/bequig_s//workspace/module-Unix/minishell
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Nov  6 12:13:10 2012 sebastien bequignon
** Last update Fri Nov 30 18:13:14 2012 sebastien bequignon
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

# define BUFFER_WIDTH (4100)
# define COMMAND_LIMIT (4096)
# define PROMPT "MY_SH $> "
# define SETENV_BAD_SYNTAX "Bad syntax : Usage setenv VAR VAL1 {VAL 2 ...}"
# define UNSETENV_BAD_SYNTAX "Bad syntax : Usage unsetenv VAR VAL"
# define MALLOC_MSG "malloc()"
# define SIGNAL_FAIL "signal failed"
# define PERM_DENIED "Permission denied"
# define CMD_NOT_FOUND "Command not found"
# define FILE_NOT_FOUND "No such file or directory"
# define INPUT_TOO_LONG "Input too long"
# define ENV_NOT_FOUND "Variable not defined"
# define COLOR_PROMPT "\033[0;36m"
# define COLOR_DEFAULT "\033[0;0m"
# define COLOR_WARNING "\033[0;33m"
# define COLOR_ERROR "\033[0;31m"

#endif /* !MINISHELL_H_ */
