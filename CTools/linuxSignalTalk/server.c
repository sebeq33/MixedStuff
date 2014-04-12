/*
** server.c for server.c in /home/bequig_s//workspace/module-Unix/minitalk
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Nov 12 15:09:00 2012 sebastien bequignon
** Last update Fri Nov 16 19:52:27 2012 sebastien bequignon
*/

#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include "minitalk.h"
#include "server.h"

static t_client	*client_list;

void		confirm_catch(t_client *client, int pid)
{
  if (search_client(client_list, pid) != NULL)
    if (kill(pid, SIGUSR1) == -1)
      my_putstr("Error : sent 1 confirmation to much to client\n");
}

void		catch_sig1(int signum, siginfo_t *info, void *ucontext_t)
{
  t_client	*client;

  client = get_client(&client_list, info->si_pid);
  if (client->c_val == 0 && client->sign == 0)
    client->sign = 1;
  else
    received_sig1(&client_list, client);
  confirm_catch(client, info->si_pid);
}

void		catch_sig2(int signum, siginfo_t *info, void *ucontext_t)
{
  t_client	*client;

  client = get_client(&client_list, info->si_pid);
  if (client->c_val == 0 && client->sign == 0)
    client->sign = -1;
  else
    received_sig2(client);
  confirm_catch(client, info->si_pid);
}

void	init_sigactions(t_sig *sig1_hand, t_sig *sig2_hand)
{
  sig1_hand->sa_sigaction = catch_sig1;
  sig2_hand->sa_sigaction = catch_sig2;
  sig1_hand->sa_flags = SA_SIGINFO;
  sig2_hand->sa_flags = SA_SIGINFO;
}

int		main(int ac, char **av)
{
  t_sig		sig1_hand;
  t_sig		sig2_hand;

  init_sigactions(&sig1_hand, &sig2_hand);
  my_putstr("Server : ");
  my_put_nbr(getpid());
  my_putchar('\n');
  if (sigaction(SIGUSR1, &sig1_hand, &sig1_hand) == -1 ||
      sigaction(SIGUSR2, &sig2_hand, &sig2_hand) == -1)
    {
      my_putstr("Error while loading signal handlers\n");
      exit(0);
    }
  while (42)
    pause();
  return (0);
}
