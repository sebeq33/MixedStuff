#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"

int	i = 7;
char	c = 0;

void	my_catch_signal(int sig)
{
  if (sig == 10)
    i--;
  else if (sig == 12)
    {
      c |= (1 << i);
      i--;
    }
  if (i == -1)
    {
      i = 7;
      my_putchar(c);
      c = 0;
    }
}

int	main(int ac, char **av)
{
  my_putstr("Pid server: ");
  my_put_nbr(getpid());
  my_putstr("\n");
  while (42)
    {
      signal(SIGUSR1, my_catch_signal);
      signal(SIGUSR2, my_catch_signal);
      pause();
    }
}
