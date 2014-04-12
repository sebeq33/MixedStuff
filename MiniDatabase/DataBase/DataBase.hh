//
// DataBase.hh for DataBase.hh in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun May 12 17:17:55 2013 sebastien bequignon
// Last update Fri May 31 18:58:05 2013 sebastien bequignon
//

#ifndef DATABASE_H_
# define DATABASE_H_

#include <fstream>
#include <string>
#include <list>
#include "ExceptionClass.hh"
#include "ClientPacket.hh"
#include "FriendPacket.hh"
#include "File.hh"

class DataBase
{
private:
  const std::string DBDirectory;
  const std::string DBExtension;
  ClientPacket	pack;
  FriendPacket	fpack;
  File		clients;
  File		friends;

  bool	searchClient(const std::string &login);
  bool	searchFriend(const std::string &login, const std::string loginContact);

public:
  DataBase();
  ~DataBase();
  const ClientPacket	&addClient(const std::string &login, const std::string &passwd);
  const ClientPacket	&getClient(const std::string &login);
  const ClientPacket	&getClient(const std::string &login, const std::string &passwd);
  void			getContactList(const ClientPacket &, std::list<std::string> &list);
  void			addContact(const ClientPacket &, std::string const &loginContact);
  void			removeContact(const ClientPacket &, std::string const &loginContact);

  DEFINE_EXCEPT_MSG(NotExist, "Client not exist");
  DEFINE_EXCEPT_MSG(FalsePasswd, "Password doesn't match");
  DEFINE_EXCEPT_MSG(AlreadyExist, "Client already exist");
  DEFINE_EXCEPT_MSG(FileError, "An error append on database's files");
};

#endif /* !DATABASE_H_ */
