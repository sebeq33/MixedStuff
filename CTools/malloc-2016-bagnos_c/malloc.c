/*
** malloc.c for malloc.c in /home/bequig_s//workspace/systemUnixTek2/malloc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Thu Jan 31 11:16:12 2013 sebastien bequignon
** Last update Sat Feb  9 15:14:28 2013 caroline bagnost
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "malloc.h"

t_header	*g_start = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void		*split(t_header *first, size_t size)
{
  t_header	*second;

  second = (t_header *)((char *) first + HEADER_SIZE + size);
  second->next = first->next;
  second->size = first->size - HEADER_SIZE - size;
  second->prev = first;
  second->freed = 1;
  second->block = (char *) second + HEADER_SIZE;
  first->next = second;
  first->size = size;
  first->freed = 0;
  first->block = (char *) first + HEADER_SIZE;
  if (second->next)
    second->next->prev = second;
  return (first);
}

void		*new_header(t_header *prev, size_t size)
{
  t_header	*new;
  size_t	size_pages;
  struct rlimit	limit;

  getrlimit(RLIMIT_DATA, &limit);
  if (size <= 0 || size > (limit.rlim_cur / 2))
    return (0);
  size_pages = (size + HEADER_SIZE * 2) / PAGESIZE * PAGESIZE + PAGESIZE;
  if ((new = (t_header *) sbrk(size_pages)) == (void *) -1)
    return (0);
  new->prev = prev;
  new->next = 0;
  new->size = size_pages - HEADER_SIZE;
  new->freed = 0;
  new->block = (char *)new + HEADER_SIZE;
  return (split(new, size));
}

void		*search_memory(t_header **start, size_t size)
{
  t_header	*current;

  size = ALIGN_8(size);
  if (*start == 0)
    {
      *start = new_header(0, size);
      return (*start);
    }
  current = *start;
  while (current)
    {
      if (current->size == size && current->freed)
	{
	  current->freed = 0;
	  return (current);
	}
      if (current->freed && (int) (current->size - HEADER_SIZE - size)
	  > (int)(HEADER_SIZE + ALIGN))
	return (split(current, size));
      if (!current->next)
	break ;
      current = current->next;
    }
  current->next = new_header(current, size);
  return (current->next);
}

void			*malloc(size_t size)
{
  t_header		*available_block;

  if (size == 0)
    return (0);
  do_lock();
  if ((available_block = search_memory(&g_start, size)) == 0)
    return (0);
  unlock();
  return ((void *)(((char *)available_block) + HEADER_SIZE));
}

