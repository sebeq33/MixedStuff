//
// FriendPacket.hh for FriendPacket.hh in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu May 30 15:24:38 2013 sebastien bequignon
// Last update Fri May 31 18:58:13 2013 sebastien bequignon
//

#ifndef FRIENDPACKET_H_
# define FRIENDPACKET_H_

#include <stdint.h>
#include "Packet.hpp"

class FriendPacket : public APacket
{
private:
  bool		set;
  std::string	orig;
  std::string	fname;
  uint64_t	offset;
  bool		erased;

public:
  FriendPacket();
  FriendPacket(std::string const &orig, std::string const &fname, uint64_t offset = 0);
  ~FriendPacket();
  void setValues(std::string const &orig, std::string const &fname, uint64_t offset = 0);
  std::string const & getOrig() const;
  std::string const & getFLogin() const;
  uint64_t getOffset() const;
  void erase();
  bool isErased() const;
  bool serialize(std::fstream &file) const;
  bool unserialize(std::fstream &file);
};

#endif /* !FRIENDPACKET_H_ */
