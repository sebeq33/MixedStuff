//
// FriendPacket.cpp for FriendPacket.cpp in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri May 31 18:28:09 2013 sebastien bequignon
// Last update Fri May 31 19:27:47 2013 sebastien bequignon
//

#include "FriendPacket.hh"

FriendPacket::FriendPacket()
  : set(false), erased(false)
{

}

FriendPacket::FriendPacket(std::string const &_orig, std::string const &_fname, uint64_t _offset)
  : set(true), orig(_orig), fname(_fname), offset(_offset), erased(false)
{

}

FriendPacket::~FriendPacket()
{

}

void FriendPacket::setValues(std::string const &_orig,
			     std::string const &_fname,
			     uint64_t _offset)
{
  orig = _orig;
  fname = _fname;
  offset = _offset;
}

std::string const & FriendPacket::getOrig() const
{
  return (orig);
}

std::string const & FriendPacket::getFLogin() const
{
  return (fname);
}

uint64_t FriendPacket::getOffset() const
{
  return (offset);
}
void FriendPacket::erase()
{
  this->erased = true;
}

bool FriendPacket::isErased() const
{
  return (this->erased);
}

bool FriendPacket::serialize(std::fstream &file) const
{
  if (!this->set || !file.is_open())
    return (false);
  file.write(reinterpret_cast<const char *>(&erased), sizeof(this->erased));
  write32oct(file, orig);
  write32oct(file, fname);
  return (true);
}

bool FriendPacket::unserialize(std::fstream &file)
{
  if (!file.is_open())
    return (false);
  char	buf[33];
  buf[0] = '\0';
  buf[32] = '\0';
  file.read(reinterpret_cast<char *>(&erased), sizeof(this->erased));
  file.read(buf, 32);
  orig = buf;
  file.read(buf, 32);
  fname = buf;
  this->set = true;
  return (true);
}
