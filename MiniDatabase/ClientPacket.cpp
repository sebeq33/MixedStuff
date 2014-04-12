#include <iostream>
#include "DataBase/ClientPacket.hh"

ClientPacket::ClientPacket()
  : set(false)
{

}

ClientPacket::ClientPacket(std::string const &setlogin,
			   std::string const &setpasswd,
			   uint32_t off)
  : login(setlogin), passwd(setpasswd), offset(off), set(true)
{

}

ClientPacket::ClientPacket(const ClientPacket &pack)
  : login(pack.login), passwd(pack.passwd), offset(pack.offset), set(pack.set)
{

}

void ClientPacket::operator=(const ClientPacket &pack)
{
  if (this != &pack && pack.set)
    {
      login = pack.login;
      passwd = pack.passwd;
      offset = pack.offset;
      set = true;
    }
}

void ClientPacket::setValues(std::string const &setlogin,
			     std::string const &setpasswd,
			     uint32_t off)
{
  login = setlogin;
  passwd = setpasswd;
  offset = off;
  set = true;
}

ClientPacket::~ClientPacket()
{

}

bool ClientPacket::serialize(std::fstream &file) const
{
  if (!this->set || !file.is_open())
    return (false);
  write32oct(file, login);
  write32oct(file, passwd);
  file.write(reinterpret_cast<const char *>(&offset), sizeof(this->offset));
  return (true);
}

bool ClientPacket::unserialize(std::fstream &file)
{
  char	buf[33];

  if (!file)
    return (false);
  buf[0] = '\0';
  buf[32] = '\0';
  file.read(buf, 32);
  login = buf;
  file.read(buf, 32);
  passwd = buf;
  file.read(reinterpret_cast<char *>(&offset), sizeof(this->offset));
  this->set = true;
  return (true);
}

bool ClientPacket::isSet() const
{
  return (this->set);
}

bool ClientPacket::checkPasswd(std::string const &pass) const
{
  return (this->set && pass == this->passwd);
}

int32_t ClientPacket::getSize()
{
  //size of a client packet (2 * 32oct + 1 * 4oct)
  return (68);
}

const std::string & ClientPacket::getLogin() const
{
  return (this->login);
}

uint32_t ClientPacket::getOffset() const
{
  return (this->offset);
}
