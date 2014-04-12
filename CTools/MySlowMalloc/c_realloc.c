/*
** manage_alloc.c for manage_alloc.c in /home/bequig_s//workspace/systemUnixTek2/malloc/malloc
**
** Made by sebastien bequignon
** Login   <bequig_s@epitech.net>
**
** Started on  Fri Feb  1 12:25:42 2013 sebastien bequignon
** Last update Sat Feb  9 15:22:26 2013 caroline bagnost
*/

#include <stdio.h>
#include "malloc.h"

void		copy_block(t_header *src, t_header *dest)
{
  int		*src_data;
  int		*dest_data;
  size_t	i;

  src_data = src->block;
  dest_data = dest->block;
  i = 0;
  while ((i * 4) < src->size && (i * 4) < dest->size)
    {
      dest_data[i] = src_data[i];
      i++;
    }
}

void		*do_realloc(void *ptr, t_header *block, size_t size)
{
  t_header	*new;
  void		*new_ptr;

  if (block->next && block->next->freed &&
      (block->size + block->next->size) >= size + ALIGN)
    {
      concat_mem(block, block->next);
      split(block, size);
      return (ptr);
    }
  else
    {
      if (!(new_ptr = malloc(size)))
	return (0);
      new = (t_header *)((char *)new_ptr - HEADER_SIZE);
      copy_block(block, new);
      free(ptr);
      return (new_ptr);
    }
}

void		*realloc(void *ptr, size_t size)
{
  t_header	*block;

  if (!ptr)
    return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (0);
    }
  if (!is_alloc(ptr))
    return (0);
  size = ALIGN_8(size);
  block = (t_header *)((char *) ptr - HEADER_SIZE);
  if (block->size >= size + HEADER_SIZE + ALIGN)
    split(block, size);
  else
    ptr = do_realloc(ptr, block, size);
  return (ptr);
}

void		*calloc(size_t nb_elem, size_t size)
{
  char		*new;
  size_t	i;

  size = ALIGN_8(nb_elem * size);
  new = malloc(size);
  if (new)
    {
      i = 0;
      while (i < size)
	{
	  new[i] = 0;
	  i++;
	}
    }
  return (new);
}
