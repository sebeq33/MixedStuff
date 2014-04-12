//
// main.cpp for main.cpp in /tmp
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri May 10 10:44:33 2013 sebastien bequignon
// Last update Fri May 31 22:02:06 2013 sebastien bequignon
//

#include <fstream>
#include <string>
#include <iostream>
#include "DataBase.hh"
#include "File.hh"
#include "Packet.hpp"
#include "ClientPacket.hh"

bool		OpenOCreate(std::fstream &file, const std::string &name)
{
  const char	*str = name.c_str();

  file.open(str,
	    std::fstream::in |
	    std::fstream::out |
	    std::fstream::binary);
  if (!file.is_open())
    {
      file.open(str,
		std::fstream::in |
		std::fstream::out |
		std::fstream::binary |
		std::fstream::trunc);
      return (true);
    }
  return (false);
}

void	teststr(int ac, char **av)
{
  std::fstream	file;

  OpenOCreate(file, "test");

  StrPacket	test;
  test.setValue(ac < 2 ? "test1" : av[1]);
  std::cout << test.getValue() << std::endl;
  file << test;
  test.setValue(ac < 3 ? "test2" : av[2]);
  file << test;
  test.setValue(ac < 3 ? "test3" : av[2]);
  std::cout << test.getValue() << std::endl;
  file.seekg(0, file.beg);
  file >> test;
  std::cout << test.getValue() << std::endl;

}

void	testInt()
{
  IntPacket	test;
  std::fstream	file;

  OpenOCreate(file, "test2");
  test.setValue(0);
  file << test;
  test.setValue(55);
  file << test;
  test.setValue(66);
  file << test;
  test.setValue(47);
  file << test;
  test.setValue(28);
  file << test;

  file.seekg((2 * sizeof(int)), file.beg);
  file >> test;
  std::cout << test.getValue() << std::endl;
}

void	testClient()
{
  std::fstream	file;
  ClientPacket	man;

  if (OpenOCreate(file, "test3") && file.is_open())
    {
      man.setValues("zelda", "hello world", 0);
      file << man;
      man.setValues("link", "passwd", 1);
      file << man;
      man.setValues("plop", "passwd", 2);
      file << man;
      man.setValues("plop", "passwd", 2);
      file << man;
      man.setValues("plop", "passwd", 2);
      file << man;
      man.setValues("linkazejazejaozijeaozijeoazjeoazijeoazjeoazijeoazije",
		    "anotherpasswzdhaohdoaidhaodhaizdhaiudhauidhauizhdiaudhaudd", 3);
      file << man;
    }

  file.seekg(ClientPacket::getSize() * 1, file.beg);
  file >> man;
  file >> man;

  std::cout << "ID : " << man.getOffset() << std::endl
	    << "NAME : " << man.getLogin() << std::endl;
}


void	testFileFStream()
{
  std::cout << "---------#############START############--------" << std::endl;

  File file;

  file.openOCreate("plop");
  // std::cout << "open : " << std::boolalpha << file->is_open() << std::endl;
  // *file << "hello\n";
  // file->close();
  // std::cout << "close : " << std::boolalpha << file->is_open() << std::endl;

  StrPacket	test;

  file.reset();
  test.setValue("test1\n");
  file << test;
  test.setValue("test2\n");
  file << test;
  test.setValue("test3");
  file << test << std::endl;
  file.reset();
  test.setValue("ERROR");


  std::cout << "---------------------" << std::endl;
  file >> test;
  std::cout << "## Received " << '[' << test.getValue() << ']' << std::endl;
  file >> test;
  std::cout << "## Received " << '[' << test.getValue() << ']' << std::endl;
  file >> test;
  std::cout << "## Received " << '[' << test.getValue() << ']' << std::endl;
  file.reset();
  file >> test;
  std::cout << "## Received " << '[' << test.getValue() << ']' << std::endl;
  file >> test;
  std::cout << "## Received " << '[' << test.getValue() << ']' << std::endl;
}

#include <ctype.h>
void	testDataBase()
{
  DataBase base;
  ClientPacket pack;
  std::string friends[2] =
    {
      "machin",
      "machine"
    };
  std::string values[6] =
    {
      "machin",
      "machine",
      "muche",
      "truc",
      "trac",
      "bidule",
    };
  for (int i = 0; i < 6; ++i)
    {
      std::cout << '[' << values[i] << ']' << std::endl;
      try { base.addClient(values[i], "hello"); }
      catch (std::exception &ex) {std::cout << ex.what() << std::endl;}
    }
  for (int i = 0; i < 6; ++i)
    {
      try { std::cout << base.getClient(values[i]).getLogin() << std::endl; }
      catch (std::exception &ex) {std::cout << ex.what() << std::endl;}
    }
  std::cout << "------------- ADD FRIEND --------------" << std::endl;
  for (int i = 0; i < 6; ++i)
    {
      std::cout << "##### [" << static_cast<char>(::toupper(values[i][0])) << "] #####" << std::endl;
      pack.setValues(values[i], "hello");
      for (int j = 0; j < 2; ++j)
	{
	  try
	    {
	      std::cout << "-----" << std::endl;
	      std::cout << "Add friend [" << friends[j] << "] for : ["
			<< pack.getLogin() << "]" << std::endl;
	      base.addContact(pack, friends[j]);
	    }
	  catch (std::exception &ex)
	    {
	      std::cout << ex.what() << std::endl;
	    }
	}
    }
  std::cout << "------------- REMOVE FRIEND  ---------------" << std::endl;
  for (int i = 0; i < 6; i += 2)
    {
      std::cout << "##### [" << static_cast<char>(::toupper(values[i][0])) << "] #####" << std::endl;
      pack.setValues(values[i], "hello");
      for (int j = 0; j < 2; ++j)
	{
	  try
	    {
	      std::cout << "-----" << std::endl;
	      std::cout << "Remove friend [" << friends[j] << "] for : ["
			<< pack.getLogin() << "]" << std::endl;
	      base.removeContact(pack, friends[j]);
	    }
	  catch (std::exception &ex)
	    {
	      std::cout << ex.what() << std::endl;
	    }
	}
    }
  std::cout << "--------------- QI SAIS KE C'ES MAIS Z'AMMI ? -------------" << std::endl;
  std::list<std::string> meszami;
  pack.setValues(values[0], "hello");
  try
  {
	base.getContactList(pack, meszami);
	while (!meszami.empty())
		{
		  std::cout << "Bonjour l'ami de [" << values[0] << "]: " << meszami.front() << std::endl;
		  meszami.pop_front();
		}
  }
  catch (std::exception &ex)
  {
	  std::cout << ex.what() << std::endl;
  }
}

int	main(int ac, char **av)
{
  // testFileFStream();
  // testClient();
  testDataBase();
  return (0);
}
