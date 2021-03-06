/*
** philo.h for bequig_s in /home/bequig_s//workspace/systemUnixTek2/philosophe/clean
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Sat Mar 23 22:40:28 2013 sebastien bequignon
** Last update Fri Apr  5 15:24:07 2013 sebastien bequignon
*/

#ifndef PHILO_H_
# define PHILO_H_

#include <pthread.h>

# define NB_PHILO	(7)
# define LIMIT_EAT	(10000)
# define TIME_EAT	(1000000)
# define TIME_THINK	(4000000)
# define RANDOM		(-1)
# define RANDOM_LIMIT	(2000000)
# define NB_STATE	(3)

# define LEFT_BAG(philo) (philo->pos)
# define RIGHT_BAG(philo) (philo->pos == NB_PHILO - 1 ? 0 : philo->pos + 1)

# define NB_LEFT_PHILO(x) (x == 0 ? NB_PHILO - 1 : x - 1)
# define NB_RIGHT_PHILO(x) (x == NB_PHILO - 1 ? 0 : x + 1)
# define LEFT_PHILO(philo) (philo->table->philos[NB_LEFT_PHILO(philo->pos)])
# define RIGHT_PHILO(philo) (philo->table->philos[NB_RIGHT_PHILO(philo->pos)])

typedef enum
  {
    SLEEP = 0,
    THINK,
    EAT
  } e_state;

typedef struct s_table t_table;

typedef struct	s_philo
{
  t_table	*table;
  e_state	state;
  int		pos;
  int		nb_eat;
  int		fork[2];
}		t_philo;

typedef struct		s_table
{
  t_philo		philos[NB_PHILO];
  int			bag[NB_PHILO];
  pthread_t		thread[NB_PHILO];
  pthread_cond_t	ask[NB_PHILO];
  pthread_mutex_t	lock;
}			t_table;

typedef void (*t_behavior)(t_philo *);

void	a_sleep(t_philo *philo);
void	a_think(t_philo *philo);
void	a_eat(t_philo *philo);
int	finished(t_table *table);
void	xmutex_lock(pthread_mutex_t *mutex);
void	xmutex_unlock(pthread_mutex_t *mutex);
void	xcond_wait(pthread_cond_t * cond, pthread_mutex_t * mutex);
void	xcond_signal(pthread_cond_t * cond);
void	display(t_philo *philo, char *action, int nb_fork);

#endif /* !PHILO_H_ */
