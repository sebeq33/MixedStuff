//
// DataBase.cpp for DataBase.cpp in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon May 13 15:02:38 2013 sebastien bequignon
// Last update Fri May 31 21:57:21 2013 sebastien bequignon
//

#include <iostream>
#include <exception>
#include "DataBase.hh"
#include "ClientPacket.hh"

DataBase::DataBase()
  : DBDirectory("./ClientBase/"),
    DBExtension(".dbclient")
{
}

DataBase::~DataBase()
{

}

// ################################
// #                              #
// #                              #
// #       CLIENT MANAGEMENT      #
// #                              #
// #                              #
// ################################

/*
** place on pack the searched client or place file's position at the end
*/
bool	DataBase::searchClient(const std::string &login)
{
  if (!clients.is_open())
    return (false);
  while (clients.good() && !clients.eof())
    {
      clients >> pack;
      if (pack.getLogin() == login)
	return (true);
    }
  clients.clear();
  return (false);
}

const ClientPacket	&DataBase::addClient(const std::string &login, const std::string &passwd)
{
  const std::string	filename(this->DBDirectory +
			     login.substr(0, 1) + "data"
			     + this->DBExtension);

  if (!clients.openOCreate(filename))
    throw FileError();
  if (searchClient(login))
    throw AlreadyExist();
  pack.setValues(login, passwd);
  clients << pack;
  return (pack);
}

const ClientPacket	&DataBase::getClient(const std::string &login)
{
  const std::string	filename(this->DBDirectory +
			     login.substr(0, 1) + "data"
			     + this->DBExtension);

  if (!clients.openOCreate(filename))
    throw FileError();
  if (!searchClient(login))
    throw NotExist();
  return (pack);
}

const ClientPacket	&DataBase::getClient(const std::string &login, const std::string &passwd)
{
  const std::string	filename(this->DBDirectory +
			     login.substr(0, 1) + "data"
			     + this->DBExtension);

  if (!clients.openOCreate(filename))
    throw FileError();
  if (!searchClient(login))
    throw NotExist();
  if (!pack.checkPasswd(passwd))
    throw FalsePasswd();
  return (pack);
}

// ################################
// #                              #
// #                              #
// #        FRIEND/CONTACT        #
// #          MANAGEMENT          #
// #                              #
// ################################

bool	DataBase::searchFriend(const std::string &login, const std::string loginContact)
{
  if (!friends.is_open())
    return (false);
  while (friends.good() && !friends.eof())
    {
      friends >> fpack;
      if (!fpack.isErased() &&
	  fpack.getOrig() == login &&
	  fpack.getFLogin() == loginContact)
	return (true);
    }
  friends.clear();
  return (false);
}

void			DataBase::getContactList(const ClientPacket &pack, std::list<std::string> &list)
{
  const std::string	login = pack.getLogin();
  const std::string	fname(this->DBDirectory +
			      login.substr(0, 1) + "friends"
			      + this->DBExtension);
  const std::string	cname(this->DBDirectory +
			      login.substr(0, 1) + "data"
			      + this->DBExtension);

  if (login == "" || !clients.openFile(cname) || !searchClient(login))
    throw NotExist();
  if (!friends.openOCreate(fname))
    throw FileError();
  // list.clear(); // clear la liste ?
  while (friends.good() && !friends.eof())
    {
      friends >> fpack;
      if (!fpack.isErased() &&
	  fpack.getOrig() == login)
	list.push_back(fpack.getFLogin());
    }
}

void	DataBase::addContact(const ClientPacket &pack, std::string const &loginContact)
{
  const std::string	login = pack.getLogin();

  if (login == loginContact)
    throw AlreadyExist();
  if (login == "" || loginContact == "")
    throw NotExist();

  const std::string	fname(this->DBDirectory +
			      login.substr(0, 1) + "friends" +
			      this->DBExtension);
  const std::string	cname(this->DBDirectory +
			      loginContact.substr(0, 1) + "data" +
			      this->DBExtension);
  const std::string	lname(this->DBDirectory +
  			      login.substr(0, 1) + "data" +
  			      this->DBExtension);

  if (!clients.openFile(cname) || !searchClient(loginContact))
    throw NotExist();
  if (!clients.openFile(lname) || !searchClient(login))
    throw NotExist();
  if (!friends.openOCreate(fname))
    throw FileError();
  std::cout << "Add Contact !!" << std::endl;
  std::cout << "Login : " << login << std::endl;
  std::cout << "LoginContact : " << loginContact << std::endl;
  if (!searchFriend(login, loginContact))
    {
      std::cout << "Serialize" << std::endl;
      fpack.setValues(login, loginContact);
      friends << fpack;
    }
}

void	DataBase::removeContact(const ClientPacket &pack, std::string const &loginContact)
{
  const std::string	login = pack.getLogin();

  if (login == loginContact)
    throw AlreadyExist();
  if (login == "" || loginContact == "")
    throw NotExist();

  const std::string	fname(this->DBDirectory +
			      login.substr(0, 1) + "friends" +
			      this->DBExtension);
  const std::string	cname(this->DBDirectory +
			      loginContact.substr(0, 1) + "data" +
			      this->DBExtension);
  const std::string	lname(this->DBDirectory +
  			      login.substr(0, 1) + "data" +
  			      this->DBExtension);

  if (!clients.openFile(cname) || !searchClient(loginContact))
    throw NotExist();
  if (!clients.openFile(lname) || !searchClient(login))
    throw NotExist();
  if (!friends.openOCreate(fname))
    throw FileError();
  std::cout << "Remove Contact !!" << std::endl;
  std::cout << "Login : " << login << std::endl;
  std::cout << "LoginContact : " << loginContact << std::endl;
  if (searchFriend(login, loginContact))
    {
      fpack.erase();
      friends << fpack;
    }
}
