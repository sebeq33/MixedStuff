#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"

int kill(pid_t pid, int sig);

int	main(int ac, char **av)
{
  int	i;
  char	*str;
  pid_t	pid;

    if (ac == 3)
    {
      str = av[2];
      pid = my_getnbr(av[1]);
      while (*str)
	{
	  i = 7;
	  while (i >= 0)
	    {
	      if (((*str >> i) & 0x01) == 0)
		kill(pid, SIGUSR1);
	      else if (((*str >> i) & 0x01) == 1)
		kill(pid, SIGUSR2);
	      i--;
	      usleep(1700);
	    }
	  str++;
	}
    }
    return (0);
}
