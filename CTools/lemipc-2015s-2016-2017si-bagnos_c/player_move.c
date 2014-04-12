/*
** player_move.c for player_move.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC/lemipc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Mar 31 06:00:24 2013 sebastien bequignon
** Last update Sun Mar 31 09:22:24 2013 sebastien bequignon
*/

#include <stdlib.h>
#include "lemipc.h"

void		move_random(t_lemipc *game, t_player *player)
{
  int		x;
  int		y;
  int		cont;

  cont = 1;
  while (cont)
    {
      x = random() % 3 - 1 + player->x;
      y = random() % 3 - 1 + player->y;
      if ((x != player->x || y != player->y) &&
	IN_GAME(y, x) && GET_MAP(game, y, x) == 0)
	{
	  game->map[player->y][player->x] = 0;
	  game->map[y][x] = player->nb_team;
	  player->x = x;
	  player->y = y;
	  cont = 0;
	}
    }
}

void		move_target(t_lemipc *game, t_player *player, int x, int y)
{
  if (ABS(player->x - x) <= 1 && ABS(player->y - y) <= 1)
    {
      move_random(game, player);
      return ;
    }
  x = GET_DIRECTION(player->x - x) + player->x;
  y = GET_DIRECTION(player->y - y) + player->y;
  if (!IN_GAME(y, x) || GET_MAP(game, y, x) != 0)
    {
      move_random(game, player);
      return ;
    }
  game->map[player->y][player->x] = 0;
  game->map[y][x] = player->nb_team;
  player->x = x;
  player->y = y;
}
