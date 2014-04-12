/*
** player_update.c for player_update.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC/lemipc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Mar 30 16:57:08 2013 sebastien bequignon
** Last update Sun Mar 31 21:50:35 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lemipc.h"

void		get_closest(t_lemipc *game, t_player *player, int *a, int *b)
{
  int		x;
  int		y;
  double	d;
  double	dmin;

  y = 0;
  dmin = MAP_X * MAP_Y;
  while (y < MAP_Y)
    {
      x = 0;
      while (x < MAP_X)
	{
	  if (game->map[y][x] != 0 && game->map[y][x] != player->nb_team)
	    if ((d = GET_DISTANCE(x, y, player->x, player->y)) < dmin
		|| (d == dmin && random() % 2))
	      {
		dmin = d;
		*a = x;
		*b = y;
	      }
	  x++;
	}
      y++;
    }
}

int		give_orders(t_lemipc *game, t_player *player)
{
  int		i;
  int		x_target;
  int		y_target;
  char		target[SIZE_MSG];

  x_target = -1;
  y_target = -1;
  get_closest(game, player, &x_target, &y_target);
  if (x_target != -1 && y_target != -1)
    {
      snprintf(target, SIZE_MSG, "A%d;%d", x_target, y_target);
      while (i < NB_ALLY(game, player->nb_team))
	{
	  if (send_message(player->nb_team, target))
	    return (1);
	  i++;
	}
    }
  return (0);
}

int		follow_orders(t_lemipc *game, t_player *player)
{
  int		x;
  int		y;
  char		*order;

  x = -1;
  y = -1;
  if ((order = get_message(player->nb_team)) == NULL)
    move_random(game, player);
  else if (order[0] == 'A' && sscanf(order, "A%d;%d", &x, &y) > 0
      && x != -1 && y != -1)
    move_target(game, player, x, y);
  else if (order[0] == '\0')
    {
      player->chief = 1;
      if (give_orders(game, player))
	return (0);
    }
  else
    move_random(game, player);
  return (2);
}

int		win(t_lemipc *game, t_player *player)
{
  printf("[team %d] We won \\o/!!\n", player->nb_team);
  remove_player(game, player);
  if (game->nb_players <= 0)
    destroy_ipc();
  return (1);
}

int		tick(t_lemipc *game, t_player *player)
{
  if (should_die(game, player))
    {
      die(0);
      return (1);
    }
  if (game->nb_team <= 1)
    return (win(game, player));
  if (player->chief && give_orders(game, player))
    return (-1);
  if (!follow_orders(game, player))
    return (-1);
  return (0);
}
