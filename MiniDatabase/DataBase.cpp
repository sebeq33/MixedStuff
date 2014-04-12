//
// DataBase.cpp for DataBase.cpp in /home/bequig_s//workspace/c++/babel/DataBase
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon May 13 15:02:38 2013 sebastien bequignon
// Last update Sun Jun  2 12:41:40 2013 sebastien bequignon
//

#include <iostream>
#include <exception>
#include "DataBase/DataBase.hh"
#include "DataBase/ClientPacket.hh"

DataBase::DataBase()
  : DBDirectory("./ClientBase/"),
    DBExtension(".dbclient")
{
  if (!File::Mkdir::direxist(DBDirectory.c_str()))
    {
      if (File::Mkdir::mkdir(DBDirectory.c_str()))
	std::cout << "Creation of database's directory : [" << DBDirectory << ']' << std::endl;
      else
	throw FileError("Not able to create database directory");
    }
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
  std::cout << "Database : client [" << login << "] added" << std::endl;
  return (pack);
}

const ClientPacket	&DataBase::getClient(const std::string &login)
{
  const std::string	filename(this->DBDirectory +
			     login.substr(0, 1) + "data"
			     + this->DBExtension);

  if (!clients.openFile(filename))
    throw FileError();
  if (!searchClient(login))
    throw NotExist();
  std::cout << "Database : client [" << login << "] found" << std::endl;
  return (pack);
}

const ClientPacket	&DataBase::getClient(const std::string &login, const std::string &passwd)
{
  const std::string	filename(this->DBDirectory +
			     login.substr(0, 1) + "data"
			     + this->DBExtension);

  if (!clients.openFile(filename))
    throw FileError();
  if (!searchClient(login))
    throw NotExist();
  if (!pack.checkPasswd(passwd))
    throw FalsePasswd();
  std::cout << "Database : client [" << login << "] found (with passwd)" << std::endl;
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
      if (fpack.getOrig() == login && fpack.getFLogin() == loginContact)
	return (!fpack.isErased());
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
  if (!friends.openFile(fname))
    return ;
  while (friends.good() && !friends.eof())
    {
      friends >> fpack;
      if (!fpack.isErased() &&
	  fpack.getOrig() == login)
	list.push_back(fpack.getFLogin());
    }
  std::cout << "Database : getClientContact for [" << login << "] success" << std::endl;
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
  if (searchFriend(login, loginContact))
    throw AlreadyExist();
  if (fpack.isErased())
    {
      friends.seekg(FriendPacket::getSize() * -1, friends.cur);
      fpack.setErase(false);
    }
  else
    fpack.setValues(login, loginContact);
  friends << fpack;
  std::cout << "Database : [" << login << "] is now friend with [" << loginContact << ']' << std::endl;
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
  if (searchFriend(login, loginContact))
    {
      friends.seekg((FriendPacket::getSize()) * -1, friends.cur);
      fpack.setErase();
      friends << fpack;
      std::cout << "Database : [" << login << "] is no more friend with [" << loginContact << ']' << std::endl;
    }
}
