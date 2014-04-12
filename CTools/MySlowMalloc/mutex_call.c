/*
** mutex_call.c for  in /home/bagnos_c//Tek2/System_Unix/Malloc/BitBucket/malloc
**
** Made by caroline bagnost
** Login   <bagnos_c@epitech.net>
**
** Started on  Fri Feb  8 23:02:22 2013 caroline bagnost
** Last update Sat Feb  9 15:16:10 2013 caroline bagnost
*/

#include "malloc.h"

int		do_lock()
{
  static int	is_init = 0;

  if (is_init == 0)
    {
      if (pthread_mutex_init(&mutex, NULL) != 0)
	{
	  my_putstr_error("Mutex init failed\n");
	  return (1);
	}
      is_init = 1;
    }
  return (pthread_mutex_lock(&mutex));
}

int	unlock()
{
  return (pthread_mutex_unlock(&mutex));
}
