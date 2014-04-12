/*
** philo.c for src in /home/sfez_a/Local/projects/c/svn/tmp/philosophes-2015s-2016-2017si-sfez_a/src
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Mar 23 21:52:15 2013 sebastien bequignon
** Last update Sun Mar 24 23:03:10 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

static t_behavior		g_behavior[NB_STATE] =
  {
    &a_sleep,
    &a_think,
    &a_eat
  };

int		init(t_table *table)
{
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      table->philos[i].table = table;
      table->philos[i].pos = i;
      table->philos[i].state = SLEEP;
      table->philos[i].nb_eat = 0;
      table->bag[i] = 0;
      if (pthread_cond_init(&table->ask[i], NULL) != 0)
	return (0);
      i++;
    }
  return (pthread_mutex_init(&table->lock, NULL) == 0);
}

int	finished(t_table *table)
{
  int	i;

  i = 0;
  while (i < NB_PHILO)
    if (table->philos[i++].nb_eat < LIMIT_EAT)
      return (0);
  return (1);
}

void		*philo(void *arg)
{
  t_philo	*philo;

  philo = (t_philo *) arg;
  srandom(time(0) + philo->pos);
  while (42)
    g_behavior[philo->state](philo);
  return (0);
}

void		display(t_philo *philo, char *action, int nb_fork)
{
  int		i;

  xmutex_lock(&philo->table->lock);
  printf("\033[%d;0H\033[2K", philo->pos + 1);
  printf("[%2d] [\033[0;36m%5s\033[0;0m] [Eated %d time(s)]",
	 philo->pos + 1,
	 action,
	 philo->nb_eat);
  i = 0;
  while (i < nb_fork)
    printf(" [chopstick %d]", philo->fork[i++] + 1);
  printf("\n");
  xmutex_unlock(&philo->table->lock);
}

int		main()
{
  t_table	table;
  int		i;

  if (!init(&table))
    return (0);
  printf("\033[0;0H\033[0J\033[?25l");
  i = 0;
  while (i < NB_PHILO)
    {
      if (pthread_create(&table.thread[i], NULL, &philo, &table.philos[i]))
	return (0);
      i++;
    }
  while (!finished(&table))
    usleep(5000000);
  pthread_mutex_destroy(&table.lock);
  printf("\033[%d;0H\033[?25hPhilosophers no longer hungry, finished.\n",
	 NB_PHILO + 1);
  return (0);
}
