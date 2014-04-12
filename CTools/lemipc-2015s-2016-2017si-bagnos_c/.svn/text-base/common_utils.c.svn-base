/*
** common_utils.c for common_utils.c in /home/bequig_s//workspace/systemUnixTek2/lemiPC/lemiPC/lemipc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Mar 30 15:10:21 2013 sebastien bequignon
** Last update Sun Mar 31 14:50:42 2013 caroline bagnost
*/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <sys/shm.h>
#include "lemipc.h"

void	*my_puterr_ptr(char *err)
{
  write(2, err, strlen(err));
  return (NULL);
}

int	my_puterr(char *err)
{
  write(2, err, strlen(err));
  return (1);
}

int			my_getch(int blocking)
{
  struct termios	oldt;
  struct termios	newt;
  int			ch;

  if (!blocking)
    {
      tcgetattr(0, &oldt);
      tcgetattr(0, &newt);
      newt.c_lflag &= ~ICANON;
      newt.c_lflag &= ~ECHO;
      newt.c_cc[VMIN] = 0;
      newt.c_cc[VTIME] = 0;
      tcsetattr(0, TCSANOW, &newt);
    }
  ch = getchar();
  if (!blocking)
    {
      while (getchar() != -1)
	;
      tcsetattr(0, TCSANOW, &oldt);
    }
  return (ch);
}

int	release_game(t_lemipc *game)
{
  if (game != NULL)
    shmdt((void *) game);
  return (0);
}

