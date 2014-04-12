/*
** xfunc.c for xfunc.c in /home/bequig_s//workspace/systemUnixTek2/philosophe/clean
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sun Mar 24 05:45:11 2013 sebastien bequignon
** Last update Sun Mar 24 06:06:02 2013 sebastien bequignon
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	xmutex_lock(pthread_mutex_t *mutex)
{
  if (pthread_mutex_lock(mutex) != 0)
    {
      printf("\033[0;0H\033[0J\033[?25hpthread_mutex_lock failed\n");
      exit(0);
    }
}

void	xmutex_unlock(pthread_mutex_t *mutex)
{
  if (pthread_mutex_unlock(mutex) != 0)
    {
      printf("\033[0;0H\033[0J\033[?25hpthread_mutex_lock failed\n");
      exit(0);
    }
}

void	xcond_wait(pthread_cond_t * cond, pthread_mutex_t * mutex)
{
  if (pthread_cond_wait(cond, mutex) != 0)
    {
      printf("\033[0;0H\033[0J\033[?25hpthread_cond_wait failed\n");
      exit(0);
    }
}

void	xcond_signal(pthread_cond_t * cond)
{
  if (pthread_cond_signal(cond) != 0)
    {
      printf("\033[0;0H\033[0J\033[?25hpthread_mutex_lock failed\n");
      exit(0);
    }
}
