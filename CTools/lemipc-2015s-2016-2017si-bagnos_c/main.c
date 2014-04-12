/*
** main.c for main.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar 28 15:00:37 2013 sebastien bequignon
** Last update Sun Mar 31 03:01:12 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include "lemipc.h"

int	main(int ac, char **av)
{
  int	nb;

  if (ac < 2)
    return (my_puterr("[USAGE] ./lemipc nb_team\n"));
  if (strcmp(av[1], "clean") == 0)
    return (destroy_ipc());
  if ((nb = atoi(av[1])) < 1 || nb > MAX_TEAM)
    return (my_puterr("Error : nb_team must be > 0 && < 7\n"));
  srandom(time(0));
  if (signal(SIGINT, &die) == SIG_ERR)
    my_puterr("SIGINT are not catch due to a signal(2) error, i continue\n");
  if (signal(SIGHUP, &die) == SIG_ERR)
    my_puterr("SIGHUP are not catch due to a signal(2) error, i continue\n");
  if (make_game())
    return (my_puterr("Can't create shared memory for the game\n"));
  if (launch_player(nb))
    {
      die(0);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
