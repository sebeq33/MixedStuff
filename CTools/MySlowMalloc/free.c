/*
** free.c for free.c in /home/bequig_s//workspace/systemUnixTek2/malloc/malloc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Tue Feb  5 15:08:48 2013 sebastien bequignon
** Last update Sat Feb  9 15:16:33 2013 caroline bagnost
*/

#include <stdio.h>
#include "malloc.h"

int		is_alloc(void *ptr)
{
  t_header	*tocheck;

  if (ptr && ptr > (void *) g_start && ptr < sbrk(0))
    {
      tocheck = (t_header *)((char *) ptr - HEADER_SIZE);
      if (ptr == tocheck->block)
	return (1);
      my_putstr_error("malloc/free : Try to access junk pointer\n");
      return (0);
    }
  return (0);
}

t_header	 *concat_mem(t_header *first, t_header *second)
{
  first->size += HEADER_SIZE + second->size;
  if (second->next)
    second->next->prev = first;
  first->next = second->next;
  return (first);
}

void		free_pages(t_header *tofree)
{
  if (tofree->prev)
    {
      tofree = split(tofree, tofree->size % PAGESIZE);
      tofree->freed = 1;
      brk(tofree->next);
      tofree->next = 0;
    }
  else
    {
      g_start = 0;
      brk(tofree);
    }
}

void		free(void *ptr)
{
  t_header	*tofree;

  if (g_start && is_alloc(ptr))
    {
      do_lock();
      tofree = (t_header *)((char *) ptr - HEADER_SIZE);
      if (tofree->freed)
	return ;
      tofree->freed = 1;
      if (tofree->prev && tofree->prev->freed)
	tofree = concat_mem(tofree->prev, tofree);
      if (tofree->next && tofree->next->freed)
	tofree = concat_mem(tofree, tofree->next);
      if (!tofree->next && tofree->size >= (unsigned int)(2 * PAGESIZE))
	free_pages(tofree);
      unlock();
    }
}
