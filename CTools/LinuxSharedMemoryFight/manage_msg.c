/*
** manage_msg.c for manage_msg.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC/lemipc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Mar 31 05:26:28 2013 sebastien bequignon
** Last update Sun Mar 31 09:33:19 2013 sebastien bequignon
*/

#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include "lemipc.h"

int		send_message(int nb_team, char *message)
{
  t_msg		msg;
  key_t		key;
  int		id;

  msg.type = nb_team;
  bzero(msg.str, SIZE_MSG);
  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr("Error while retrieving key\n"));
  if ((id = msgget(key, SHM_R | SHM_W)) == -1)
    {
      if ((id = msgget(key, SHM_R | SHM_W | IPC_CREAT)) == -1)
	return (my_puterr("Error while creating msg\n"));
    }
  strncpy(msg.str, message, SIZE_MSG - 1);
  if (msgsnd(id, &msg, sizeof(t_msg), 0) == -1)
    return (my_puterr("Can't send message\n"));
  return (0);
}

char		*get_message(int nb_team)
{
  static t_msg	msg;
  key_t		key;
  int		id;

  bzero(msg.str, SIZE_MSG);
  if ((key = ftok(PATH, 0)) == -1)
    return (my_puterr_ptr("Error while retrieving key\n"));
  if ((id = msgget(key, SHM_R | SHM_W)) == -1)
    return (msg.str);
  if (msgrcv(id, &msg, sizeof(t_msg), nb_team, IPC_NOWAIT) == -1)
    return (NULL);
  return (msg.str);
}

