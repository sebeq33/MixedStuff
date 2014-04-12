/*
** client.c for client.c in /home/bequig_s//workspace/module-Unix/minitalk
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 12 14:44:50 2012 sebastien bequignon
** Last update Fri Nov 16 19:51:57 2012 sebastien bequignon
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"
#include "minilib/my.h"

void	wait()
{
  return ;
}

void	send_signal(pid_t pid, int signum)
{
  if (kill(pid, signum) == -1)
    {
      my_putstr("Kill failed (Server closed or false PID)\n");
      exit(0);
    }
  sleep(TIME_OUT_SEC);
}

void	send_letter(pid_t pid, char c)
{
  int	i;

  i = c;
  if (i < START)
    {
      send_signal(pid, SIGUSR2);
      i = i * -1;
    }
  else
    send_signal(pid, SIGUSR1);
  while (i >= SIG1_VAL)
    {
      send_signal(pid, SIGUSR1);
      i = i - SIG1_VAL;
    }
  while (i > 0)
    {
      send_signal(pid, SIGUSR2);
      i = i - SIG2_VAL;
    }
  send_signal(pid, SIGUSR2);
  send_signal(pid, SIGUSR1);
}

void	send_msg(pid_t pid, char *msg)
{
  int	i;

  i = 0;
  while (i == 0 || msg[i - 1] != '\0')
    {
      send_letter(pid, msg[i]);
      i++;
    }
}

int	main(int ac, char **av)
{
  if (signal(SIGUSR1, wait) == SIG_ERR)
    {
      my_putstr("Error while loading signal handlers\n");
      exit(0);
    }
  if (ac == 3 && my_str_isnum(av[1]))
    send_msg(my_getnbr(av[1]), av[2]);
  else
    my_putstr("Usage : client pid \"msg\"\n");
  return (0);
}
