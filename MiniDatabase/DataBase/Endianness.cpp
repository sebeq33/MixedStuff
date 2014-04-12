//
// Endianness.cpp for Endianness.cpp in /home/bequig_s//workspace/c++/babel/bdd/bddtest
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun May 12 14:44:47 2013 sebastien bequignon
// Last update Sun May 12 15:56:54 2013 sebastien bequignon
//

#include <stdio.h>
#include "Endianness.hh"

bool	Endianness::isBigEndian()
{
  union
  {
    int	 i;
    char c[4];
  } endianchecker;

  endianchecker.i = 1;
  return (endianchecker.c[0] == 1);
}

void	Endianness::toBigEndian(void *data, size_t size)
{
  if (!isBigEndian())
    reverse_bytes(data, size);
}

void	Endianness::reverse_bytes(void *data, size_t size)
{
  char	*toRev = reinterpret_cast<char *> (data);
  char	tmp;
  int	i = 0;
  int	j = size - 1;

  while (i < j)
    {
      tmp = toRev[i];
      toRev[i] = toRev[j];
      toRev[j] = tmp;
      i++;
      j--;
    }
}
