/*
** manage_ipc.c for manage_ipc.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Mar 28 15:28:31 2013 sebastien bequignon
** Last update Sun Mar 31 01:30:43 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include "lemipc.h"

int		make_game()
{
  t_lemipc	*game;
  key_t		key;
  int		shm;

  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr("Error while retrieving key\n"));
  if ((shm = shmget(key, sizeof(t_lemipc), SHM_R | SHM_W)) == -1)
    {
      if ((shm = shmget(key, sizeof(t_lemipc),
			IPC_CREAT | SHM_R | SHM_W)) == -1)
	return (my_puterr("Error while retrieving shm\n"));
      if ((game = (t_lemipc *) shmat(shm, NULL, SHM_R | SHM_W)) == (void *) -1)
	return (my_puterr("Error when attaching shared memory\n"));
      printf("Generating shm game\n");
      bzero(game->map, MAP_X * MAP_Y);
      bzero(game->nb_ally, MAX_TEAM);
      game->nb_players = 0;
      game->nb_team = 0;
      game->started = 0;
    }
  else if ((game = (t_lemipc *) shmat(shm, NULL, SHM_R | SHM_W))
	   == (void *) -1)
    return (my_puterr("Error when attaching shared memory\n"));
  release_game(game);
  return (0);
}

t_lemipc	*get_game()
{
  t_lemipc	*game;
  key_t		key;
  int		shm;

  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr_ptr("Error while retrieving key\n"));
  if ((shm = shmget(key, sizeof(t_lemipc), SHM_R | SHM_W)) == -1)
    return (my_puterr_ptr("Error while retrieving shm\n"));
  if ((game = (t_lemipc *) shmat(shm, NULL, SHM_R | SHM_W)) == (void *) -1)
    return (my_puterr_ptr("Error when attaching shared memory\n"));
  return (game);
}

int		sem_lock()
{
  key_t		key;
  int		sem;
  struct sembuf sembuf;

  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr("Error while retrieving key\n"));
  if ((sem = semget(key, 1, SHM_R | SHM_W)) == -1)
    {
      if ((sem = semget(key, 1, IPC_CREAT | SHM_R | SHM_W)) == -1)
	return (my_puterr("Error while retriving sem\n"));
      if (semctl(sem, 0, SETVAL, 1) == -1)
	return (my_puterr("Error while semctl SETVAL\n"));
    }
  sembuf.sem_num = 0;
  sembuf.sem_op = -1;
  sembuf.sem_flg = 0;
  if (semop(sem, &sembuf, 0) == 1)
    return (my_puterr("Error while semop\n"));
  return (0);
}

int		sem_unlock()
{
  key_t		key;
  int		sem;
  struct sembuf sembuf;

  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr("Error while retrieving key\n"));
  if ((sem = semget(key, NSEM, SHM_R | SHM_W)) == -1)
    return (my_puterr("Error while retriving sem\n"));
  sembuf.sem_num = 0;
  sembuf.sem_op = 1;
  sembuf.sem_flg = 0;
  semop(sem, &sembuf, 0);
  return (0);
}

int		destroy_ipc()
{
  key_t		key;
  int		id;

  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr("Error while retrieving key\n"));
  if ((id = msgget(key, SHM_R | SHM_W)) != -1)
    msgctl(id, IPC_RMID, 0);
  if ((id = semget(key, NSEM, SHM_R | SHM_W)) != -1)
    semctl(id, IPC_RMID, 0);
  if ((id = shmget(key, sizeof(t_lemipc), SHM_R | SHM_W)) != -1)
    shmctl(id, IPC_RMID, 0);
  printf("All shared element have been deleted =D, bye\n");
  return (0);
}
