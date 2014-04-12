/*
** player_utils.c for player_utils.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC/lemipc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Mar 29 22:41:44 2013 sebastien bequignon
** Last update Sun Mar 31 19:33:11 2013 sebastien bequignon
*/

#include <stdio.h>
#include "lemipc.h"

int		check_double(char team[8], int nb_team)
{
  int		i;
  int		j;

  i = 0;
  while (i < 8)
    {
      j = 0;
      if (team[i] != nb_team && team[i] != 0)
	while (j < 8)
	  {
	    if (i != j && team[i] == team[j])
	      return (1);
	    j++;
	  }
      i++;
    }
  return (0);
}
int		should_die(t_lemipc *game, t_player *player)
{
  char		team[8];

  team[0] = GET_MAP(game, player->y, player->x + 1);
  team[1] = GET_MAP(game, player->y, player->x - 1);
  team[2] = GET_MAP(game, player->y + 1, player->x);
  team[3] = GET_MAP(game, player->y - 1, player->x);
  team[4] = GET_MAP(game, player->y + 1, player->x + 1);
  team[5] = GET_MAP(game, player->y - 1, player->x + 1);
  team[6] = GET_MAP(game, player->y + 1, player->x - 1);
  team[7] = GET_MAP(game, player->y - 1, player->x - 1);
  return (check_double(team, player->nb_team));
}

int		will_be_killed(t_lemipc *game, int nb_team, int y, int x)
{
  t_player	other = {nb_team, x, y, 0};

  return (GET_MAP(game, y, x) && should_die(game, &other));
}

int		will_kill(t_lemipc *game, t_player *player)
{
  char		side[8];
  int		i;
  int		team;

  team = player->nb_team;
  side[0] = will_be_killed(game, team, player->y, player->x + 1);
  side[1] = will_be_killed(game, team, player->y, player->x - 1);
  side[2] = will_be_killed(game, team, player->y + 1, player->x);
  side[3] = will_be_killed(game, team, player->y - 1, player->x);
  side[4] = will_be_killed(game, team, player->y + 1, player->x + 1);
  side[5] = will_be_killed(game, team, player->y - 1, player->x + 1);
  side[6] = will_be_killed(game, team, player->y + 1, player->x - 1);
  side[7] = will_be_killed(game, team, player->y - 1, player->x - 1);
  i = 0;
  while (i < 8)
    {
      printf("KILL %d %d\n", i, side[i]);
      if (side[i])
	return (1);
      i++;
    }
  printf("NO KILL\n");
  return (0);
}
