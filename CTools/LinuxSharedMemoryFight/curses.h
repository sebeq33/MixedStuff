/*
** curses.h for lemipc in /home/bagnos_c//Tek2/System_Unix/Lemipc/lemipc
**
** Made by caroline bagnost
** Login   <bagnos_c@epitech.net>
**
** Started on  Fri Mar 29 16:30:53 2013 caroline bagnost
** Last update Sun Mar 31 15:03:44 2013 caroline bagnost
*/

#ifndef	CURSES_H_
# define CURSES_H_

# include <ncurses.h>
# include "lemipc.h"

typedef struct	s_window
{
  WINDOW	***win;
  WINDOW	*bkgd;
  WINDOW	*info;
  WINDOW	**color;
}		t_win;

int		init();
int		quit(t_win *lemi, t_lemipc *game);

int		background(t_win *lemi);
int		info(t_win *lemi);
int		create_subwin(t_win *lemi);
int		create_game(t_win *lemi);

int		update_pos(t_win *lemi, t_lemipc *game);
void		update_window(WINDOW *ptr, int c);
void		update_info(t_win *lemi, t_lemipc *game);
void		set_color(WINDOW *ptr, int c);

#endif
