/*
** terminal.h for terminal.h in /home/bequig_s//workspace/module-Unix/my_select
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 19 18:17:26 2012 sebastien bequignon
** Last update Wed Nov 21 09:55:02 2012 sebastien bequignon
*/

#ifndef TERMINAL_H_
# define TERMINAL_H_

int	get_size_term(int *x, int *y);
int	move_abs(int x, int y);
int	reset_getent();
int	clean_term();

#endif /* !TERMINAL_H_ */
