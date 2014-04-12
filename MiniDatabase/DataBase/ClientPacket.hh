//
// ClientPacket.hh for ClientPacket.hh in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon May 13 15:59:04 2013 sebastien bequignon
// Last update Fri May 31 19:14:03 2013 sebastien bequignon
//

#ifndef CLIENTPACKET_H_
# define CLIENTPACKET_H_

#include <string>
#include <stdint.h>
#include "ExceptionClass.hh"
#include "Packet.hpp"

class ClientPacket : public APacket
{
private:
  std::string login;
  std::string passwd;
  uint32_t offset;
  bool set;

public:
  ClientPacket();
  ClientPacket(std::string const &login,
	       std::string const &passwd,
	       uint32_t offset_friend = 0);
  ClientPacket(const ClientPacket &pack);
  void operator=(const ClientPacket &pack);
  ~ClientPacket();

  void setValues(std::string const &login,
		 std::string const &passwd,
		 uint32_t offset_friend = 0);
  void setOffset(uint32_t offset);

  bool checkPasswd(std::string const &passwd) const;
  bool isSet() const;
  const std::string & getLogin() const;
  uint32_t getOffset() const;

  bool serialize(std::fstream &file) const;
  bool unserialize(std::fstream &file);
  static uint32_t getSize();
};

#endif /* !CLIENTPACKET_H_ */
