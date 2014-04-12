//
// Packet.hh for Packet.hh in /home/bequig_s//workspace/c++/babel/bdd/bddtest
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri May 10 12:29:35 2013 sebastien bequignon
// Last update Thu May 30 23:39:01 2013 sebastien bequignon
//

#ifndef PACKET_H_
# define PACKET_H_

#include <fstream>
#include <string>
#include <exception>
#include "ISerialize.hpp"

class APacket : public ISerializable<std::fstream>
{
public:
  APacket() {}
  virtual ~APacket() {}
  void write32oct(std::fstream &file, std::string const &str) const
  {
    std::string	tmp;
    int		size;

    size = str.size();
    size = size % 33 + (size < 32 ? 1 : 0);
    file.write(str.c_str(), size);
    size = 32 - size;
    if (size > 0)
      {
	tmp.assign(size, -1);
	file.write(tmp.c_str(), size);
      }
  }
  bool serialize(std::fstream &file) const = 0;
  bool unserialize(std::fstream &file) = 0;
};

// -------------------------------------

class StrPacket : public APacket
{
private:
  std::string value;

public:
  StrPacket() {}
  StrPacket(const std::string &start) : value(start) {}
  ~StrPacket() {}
  void setValue(std::string const &val)
  {
    this->value = val;
  }
  std::string const &getValue() const
  {
    return (value);
  }
  bool serialize(std::fstream &stream) const
  {
    if (!stream.is_open())
      return (0);
    stream.write(value.c_str(), value.size());
    return (true);
  }
  bool unserialize(std::fstream &stream)
  {
    if (!stream.is_open())
      return (false);
    stream >> value;
    return (true);
  }
};


class IntPacket : public APacket
{
private:
  int value;

public:
  IntPacket() {}
  IntPacket(int start) : value(start) {}
  ~IntPacket() {}
  void setValue(int val)
  {
    this->value = val;
  }
  int getValue() const
  {
    return (value);
  }
  bool serialize(std::fstream &stream) const
  {
    if (!stream.is_open())
      return (false);
    stream.write((reinterpret_cast<const char *> (&value)), sizeof(int));
    return (true);
  }
  bool unserialize(std::fstream &stream)
  {
    if (!stream.is_open() || !stream.good())
      return (false);
    stream.read(reinterpret_cast<char *> (&value), sizeof(int));
    return (true);
  }
};

#endif /* !PACKET_H_ */
