/*
** up_display.c for  in /home/bagnos_c//Tek2/System_Unix/Lemipc/lemipc
**
** Made by caroline bagnost
** Login   <bagnos_c@epitech.net>
**
** Started on  Fri Mar 29 20:54:50 2013 caroline bagnost
** Last update Sun Mar 31 13:29:26 2013 sebastien bequignon
*/

#include "lemipc.h"
#include "curses.h"

int	update_pos(t_win *lemi, t_lemipc *game)
{
  int	x;
  int	y;

  y = 0;
  while (y < MAP_Y)
    {
      x = 0;
      while (x < MAP_X)
	{
	  update_window(lemi->win[y][x], (int)game->map[y][x]);
	  x++;
	}
      y++;
    }
  return (0);
}

void	update_window(WINDOW *ptr, int c)
{
  if ((int) getbkgd(ptr) != c)
    set_color(ptr, c);
}

void	update_info(t_win *lemi, t_lemipc *game)
{
  int i;

  i = 0;
  while (i < 6)
    {
      if (game->nb_ally[i] == '\0')
	{
	  set_color(lemi->color[i], 0);
	  mvwprintw(lemi->info, i + 1, 4, "                       ");
	}
      else
	{
	  mvwprintw(lemi->info, i + 1, 4, "[team %d]  %d player(s)  ", i + 1,
		    NB_ALLY(game, i + 1));
	  set_color(lemi->color[i], i + 1);
	}
      i++;
    }
  mvwprintw(lemi->info, 7, 4, "%d team(s) %d player(s)  ",
	    game->nb_team, game->nb_players);
  box(lemi->info, 0, 0);
  wrefresh(lemi->info);
}
