//
// Endianness.hh for Endianness.hh in /home/bequig_s//workspace/c++/babel/bdd/bddtest
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun May 12 14:36:34 2013 sebastien bequignon
// Last update Mon May 13 16:08:57 2013 sebastien bequignon
//

#ifndef ENDIANNESS_H_
# define ENDIANNESS_H_

class Endianness
{
public:
  static bool isBigEndian();
  static void toBigEndian(void *data, size_t size);
  static void reverse_bytes(void *data, size_t size);
};

#endif /* !ENDIANNESS_H_ */
