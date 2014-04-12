/*
** actions.c for src in /home/sfez_a/Local/projects/c/svn/tmp/philosophes-2015s-2016-2017si-sfez_a/src
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Mar 23 22:48:13 2013 sebastien bequignon
** Last update Sun Mar 24 20:11:45 2013 sebastien bequignon
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void	take(t_table *table, int nb_bag)
{
  while (table->bag[nb_bag])
    xcond_wait(&table->ask[nb_bag], &table->lock);
  table->bag[nb_bag] = 1;
}

void	let(t_table *table, int nb_bag)
{
  xcond_signal(&table->ask[nb_bag]);
  table->bag[nb_bag] = 0;
}

void	a_sleep(t_philo *philo)
{
  display(philo, "SLEEP", 0);
  usleep(random() % RANDOM_LIMIT + 1);
  xmutex_lock(&philo->table->lock);
  if (!philo->table->bag[LEFT_BAG(philo)] &&
      !philo->table->bag[RIGHT_BAG(philo)] &&
      philo->nb_eat <= RIGHT_PHILO(philo).nb_eat)
    {
      take(philo->table, RIGHT_BAG(philo));
      philo->fork[0] = RIGHT_BAG(philo);
      philo->state = THINK;
    }
  xmutex_unlock(&philo->table->lock);
}

void	a_think(t_philo *philo)
{
  display(philo, "THINK", 1);
  usleep(TIME_THINK);
  xmutex_lock(&philo->table->lock);
  take(philo->table, LEFT_BAG(philo));
  philo->fork[1] = LEFT_BAG(philo);
  philo->state = EAT;
  xmutex_unlock(&philo->table->lock);
}

void	a_eat(t_philo *philo)
{
  display(philo, "EAT", 2);
  usleep(TIME_EAT);
  xmutex_lock(&philo->table->lock);
  philo->nb_eat++;
  let(philo->table, LEFT_BAG(philo));
  let(philo->table, RIGHT_BAG(philo));
  philo->state = SLEEP;
  xmutex_unlock(&philo->table->lock);
}
