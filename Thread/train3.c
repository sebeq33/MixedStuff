/*
** train.c for train.c in /home/bequig_s//workspace/systemUnixTek2/tp
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Mon Mar 18 10:41:01 2013 sebastien bequignon
** Last update Tue Mar 26 15:26:41 2013 sebastien bequignon
*/

#include <pthread.h>
#include <termios.h>
#include <curses.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
#include <fcntl.h>

# define NB_TRAINS	(15)
# define NB_BRIDGES	(2)
# define RAIL_LENGHT	(30)
# define BRIDGE_START	(12)
# define BRIDGE_END	(18)
# define TIME_USLEEP	(50000)

int		g_trains[NB_TRAINS];
pthread_mutex_t	m_display = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	m_bridges[NB_BRIDGES];

void	clean(void)
{
  char	*tmp;

  tmp = tgetstr("cm", NULL);
  assert(tmp != NULL);
  tmp = tgoto(tmp, 0, 0);
  assert(tmp != NULL);
  write(1, tmp, strlen(tmp));
  tmp = tgetstr("cd", NULL);
  assert(tmp != NULL);
  write(1, tmp, strlen(tmp));
}

int	start(void)
{
  char	*tmp;
  int	i;

  if (NB_TRAINS < 0 ||
      NB_BRIDGES < 0 ||
      RAIL_LENGHT < 0 ||
      BRIDGE_START < 0 ||
      BRIDGE_END < 0 ||
      BRIDGE_START >= BRIDGE_END)
    return (-1);
  if ((tmp = getenv("TERM")) == NULL || tgetent(0, tmp) != 1)
    return (-1);
  for (i = 0; i < NB_TRAINS; i++)
    g_trains[i] = 0;
  for (i = 0; i < NB_TRAINS; i++)
    pthread_mutex_init(&m_bridges[i], NULL);
  return (0);
}

void	display()
{
  int	i;
  int	j;

  if (pthread_mutex_lock(&m_display) != 0)
    return ;
  clean();
  i = 0;
  while (i < NB_TRAINS)
    {
      j = 0;
      while (j < RAIL_LENGHT)
	{
	  if (j == BRIDGE_START)
	    putchar('[');
	  else if (j == BRIDGE_END)
	    putchar(']');
	  if (j == g_trains[i])
	    putchar('#');
	  else
	    putchar('=');
	  j++;
	}
      putchar('\n');
      i++;
    }
  pthread_mutex_unlock(&m_display);
}

void	*display_loop(void *arg)
{
  (void) arg;

  while (!finished())
    {
      //lock display
      /* display(); */
      usleep(TIME_USLEEP);
      //unlock all trains
    }
  display();
  return (0);
}

void	*train(void *arg)
{
  int	i;
  int	j;
  int	n;
  int	nb_mut;

  i = *((int *)arg);
  while (g_trains[i] < RAIL_LENGHT)
    {
      //lock 1 trains
      display();
      usleep(TIME_USLEEP);
      if (g_trains[i] + 1 == BRIDGE_START)
	{
	  n = 0;
	  nb_mut = -1;
	  while (n < NB_BRIDGES)
	    {
	      if (pthread_mutex_trylock(&m_bridges[n]) == 0)
		{
		  nb_mut = n;
		  break ;
		}
	      n++;
	    }
	  if (nb_mut == -1)
	    continue ;
	}
      g_trains[i]++;
      if (g_trains[i] == BRIDGE_END)
	pthread_mutex_unlock(&m_bridges[nb_mut]);
      // if all trains finished unlock display
    }
  return (0);
}

int	finished(void)
{
  int	i;

  for (i = 0; i < NB_TRAINS; ++i)
    if (g_trains[i] != RAIL_LENGHT)
      return (0);
  return (1);
}

int		main(int ac, char **av)
{
  int		i;
  int		j;
  pthread_t	th_trains[NB_TRAINS];
  pthread_t	th_display;
  int		i_trains[NB_TRAINS];

  if (start() < 0)
    return (0);
  for (i = 0; i < NB_TRAINS; i++)
    i_trains[i] = i;
  //lock all trains
  pthread_create(&th_display, NULL, &display_loop, NULL);
  for (j = 0; j < NB_TRAINS; j++)
    pthread_create(&th_trains[j], NULL, &train, &i_trains[j]);
  pthread_join(th_display, NULL);
  return (0);
}
