/*
** player.c for player.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Mar 29 15:50:31 2013 sebastien bequignon
** Last update Sun Mar 31 21:51:14 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "lemipc.h"

static t_player *	g_player_stat = NULL;

void		remove_player(t_lemipc *game, t_player *player)
{
  game->map[player->y][player->x] = 0;
  game->nb_ally[player->nb_team - 1]--;
  if (NB_ALLY(game, player->nb_team) <= 0)
    game->nb_team--;
  game->nb_players--;
}

void		die(int signum)
{
  t_lemipc	*game;

  if (signum == SIGINT)
    printf("\r\r  \r\r");
  if (sem_lock())
    my_puterr("Can't lock semaphore\n");
  if ((game = get_game()) == NULL)
    my_puterr("Can't retrieve shared game\n");
  if (game && g_player_stat)
    {
      printf("I DIEEEeeEeergh !!\n");
      get_message(g_player_stat->nb_team);
      remove_player(game, g_player_stat);
    }
  if (!game || game->nb_team <= 0 || game->nb_players <= 0)
    destroy_ipc();
  else
    {
      release_game(game);
      if (sem_unlock())
	my_puterr("Can't unlock semaphore\n");
    }
  if (signum == SIGINT || signum == SIGHUP)
    exit(0);
}

void		place_player(t_lemipc *game, t_player *player, int nb_team)
{
  int		found;

  found = 0;
  while (!found)
    {
      player->x = random() % MAP_X;
      player->y = random() % MAP_Y;
      if (game->map[player->y][player->x] == 0 && !should_die(game, player))
	{
	  game->map[player->y][player->x] = nb_team;
	  if (will_kill(game, player))
	    game->map[player->y][player->x] = 0;
	  else
	    found = 1;
	}
    }
  if (NB_ALLY(game, nb_team) <= 0)
    {
      player->chief = 1;
      game->nb_team++;
    }
  else
    player->chief = 0;
}

int		init_player(t_player *player, int nb_team)
{
  t_lemipc	*game;

  if ((game = get_game()) == NULL)
    return (my_puterr("Can't retrieve shared game\n"));
  if (sem_lock())
    return (my_puterr("Can't lock semaphore\n"));
  if (game->nb_players >= MAX_PLAYER)
    {
      release_game(game);
      return (my_puterr("Not enough place for another player\n"));
    }
  place_player(game, player, nb_team);
  player->nb_team = nb_team;
  game->nb_players++;
  game->nb_ally[nb_team - 1]++;
  printf("Pop !! I'm in [%d; %d]\n", player->y, player->x);
  if (sem_unlock())
    return (my_puterr("Can't unlock semaphore\n"));
  release_game(game);
  g_player_stat = player;
  return (0);
}

int		launch_player(int nb_team)
{
  t_player	player;
  t_lemipc	*game;
  int		end;

  if (init_player(&player, nb_team))
    return (my_puterr("Can't init the player\n"));
  if (wait_game_start())
    return (1);
  end = 0;
  while (!end)
    {
      if ((game = get_game()) == NULL)
	return (my_puterr("Can't retrieve shared game\n"));
      if (sem_lock())
	return (my_puterr("Can't lock semaphore\n"));
      if ((end = tick(game, &player)) == 0)
	{
	  if (sem_unlock())
	    return (my_puterr("Can't unlock semaphore\n"));
	  release_game(game);
	}
      if (!end)
	usleep(USLEEP_TIME);
    }
  return (end == -1);
}
