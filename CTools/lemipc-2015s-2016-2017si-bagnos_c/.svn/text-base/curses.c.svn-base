/*
** curses.c for lemipc  in /home/bagnos_c//Tek2/System_Unix/Lemipc/lemipc
**
** Made by caroline bagnost
** Login   <bagnos_c@epitech.net>
**
** Started on  Thu Mar 28 14:14:22 2013 caroline bagnost
** Last update Sun Mar 31 14:56:26 2013 caroline bagnost
*/

#include <unistd.h>
#include "curses.h"

int		init()
{
  initscr();
  if (noecho() == ERR
      || curs_set(0) == ERR
      || start_color() == ERR)
    return (my_puterr("Init curses failure\n"));
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_WHITE, COLOR_RED);
  init_pair(4, COLOR_WHITE, COLOR_CYAN);
  init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(6, COLOR_WHITE, COLOR_YELLOW);
  return (0);
}

int		quit(t_win *lemi, t_lemipc *game)
{
  int		l;
  int		n;

  l = 0;
  while (l < MAP_Y)
    {
      n = 0;
      while (n < MAP_Y)
        delwin(lemi->win[l][n++]);
      l++;
    }
  delwin(lemi->bkgd);
  n = 0;
  if (game)
    while (n < game->nb_team + 1)
      delwin(lemi->color[n++]);
  delwin(lemi->info);
  endwin();
  return (0);
}

int		main()
{
  t_win		lemi;
  t_lemipc	*game;
  int		game_on;

  make_game();
  if ((game = get_game()) == NULL)
    return (my_puterr("Can't retrieve the map\n"));
  if (init() == 1)
    return (my_puterr("Init failure\n"));
  game_on = 0;
  if (background(&lemi) == 1
      || create_game(&lemi) == 1
      || info(&lemi) == 1)
    return (my_puterr("Display failure\n"));
  while ((!game_on || game->nb_team > 0) && (game = get_game()) != NULL)
    {
      if (game->nb_team > 0)
	game_on = 1;
      update_pos(&lemi, game);
      update_info(&lemi, game);
      usleep(USLEEP_TIME);
    }
  sleep(5);
  quit(&lemi, game);
  return (0);
}
