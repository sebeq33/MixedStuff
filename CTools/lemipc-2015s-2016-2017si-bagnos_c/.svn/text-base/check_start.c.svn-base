/*
** check_start.c for check_start.c in /home/bequig_s//SVN/lemipc-2015s-2016-2017si-bagnos_c
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Mar 31 19:01:06 2013 sebastien bequignon
** Last update Sun Mar 31 19:16:49 2013 sebastien bequignon
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lemipc.h"

int		have_two_complete_team(t_lemipc *game)
{
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (i < MAX_TEAM)
    {
      if (NB_ALLY(game, i) > 1)
	nb++;
      i++;
    }
  return (nb >= 2);
}

int		should_continue_wait(t_lemipc *game)
{
  if (game->started)
    return (0);
  else if (game->nb_team < 2)
    usleep(USLEEP_TIME * 2);
  else if (have_two_complete_team(game))
    {
      printf("press enter to start\n");
      while (!game->started && my_getch(0) != '\n')
	usleep(USLEEP_TIME * 2);
      game->started = 1;
      return (0);
    }
  return (1);
}

int		wait_game_start()
{
  int		cont;
  t_lemipc	*game;

  cont = 1;
  printf("Waiting for another team\n");
  while (cont)
    {
      if ((game = get_game()) == NULL)
	return (my_puterr("Can't retrieve shared game\n"));
      if (sem_lock())
	return (my_puterr("Can't lock semaphore\n"));
      cont = should_continue_wait(game);
      if (sem_unlock())
	return (my_puterr("Can't unlock semaphore\n"));
      release_game(game);
    }
  printf("Lets do this !!\n");
  return (0);
}
