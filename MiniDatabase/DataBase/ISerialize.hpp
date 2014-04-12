//
// ISerialize.hpp for ISerialize.hpp in /home/bequig_s//workspace/c++/babel/bdd/bddtest
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri May 10 14:18:34 2013 sebastien bequignon
// Last update Thu May 30 23:23:32 2013 sebastien bequignon
//

#ifndef ISERIALIZE_H_
# define ISERIALIZE_H_

#include <fstream>

template <typename T = std::fstream>
class ISerializable
{
public:
  virtual ~ISerializable() {};
  virtual bool serialize(T &file) const = 0;
  virtual bool unserialize(T &file) = 0;
};

template <typename T>
T & operator<<(T &stream, ISerializable<T> &pack)
{
  pack.serialize(stream);
  return (stream);
}

template <typename T>
T & operator>>(T &stream, ISerializable<T> &pack)
{
  pack.unserialize(stream);
  return (stream);
}

#endif /* !ISERIALIZE_H_ */
