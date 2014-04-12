/*
** malloc.h for malloc.h in /home/bequig_s//workspace/systemUnixTek2/malloc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Jan 31 11:17:01 2013 sebastien bequignon
** Last update Sat Feb  9 15:16:55 2013 caroline bagnost
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct		s_header
{
  struct s_header	*next;
  struct s_header	*prev;
  void			*block;
  size_t		size;
  char			freed;
}			t_header;

# define HEADER_SIZE	(sizeof(t_header))
# define PAGESIZE	(getpagesize())
# define ALIGN		(8)

# define ALIGN_8(x) (((((x) - 1) >> 3) << 3) + 8)
# define ALIGN_4(x) (((((x) - 1) >> 2) << 2) + 4)

void		*search_memory(t_header **, size_t);
t_header	*concat_mem(t_header *, t_header *);
void		*realloc(void *, size_t);
void		free(void *);
int		is_alloc(void *);
void		*malloc(size_t);
void		*split(t_header *, size_t);

void		show_alloc_mem();
void		my_putstr(char *);
void		my_putstr_error(char *);
void		my_putnbr(int);
void		my_put_pointer(void *);

int		do_lock();
int		unlock();

extern t_header		*g_start;
extern pthread_mutex_t	mutex;

#endif /* !MALLOC_H_ */
