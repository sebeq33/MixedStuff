//
// main.cpp for main.cpp in /home/bequig_s//workspace/test_perso/circular_buffer
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jul 26 16:22:12 2013 sebastien bequignon
// Last update Fri Jul 26 23:02:27 2013 sebastien bequignon
//

#include <iostream>
#include <string>
#include "CircBuff.hh"

void test1()
{
  CircBuff	buff(128);
  std::string	read;
  char		get[21];
  int		ret;

  buff.setOverride();
  do
    {
      get[0] = '\0';
      read.clear();
      std::cin >> read;
      // std::cin.read(get, 20);
      // read = get;
      if (read.size() != 0)
	{
	  ret = buff.fill(read.c_str(), read.size());
	  std::cout << "Fill : ["
		    << read << "] ["
		    << read.size() << "] |||| ret = "
		    << ret << std::endl;
	}
    }
  while (ret != 0 && read.size() != 0);

  while ((ret = buff.getline(get, 20)) > 0)
    {
      get[ret] = '\0';
      std::cout << get << std::endl;
    }
}

void test2()
{
  CircBuff	buff(128);
  int		i;

  buff << (i = 55);
  buff << (i = 56);
  buff << (i = 57);

  buff >> i;
  std::cout << i << std::endl;
  buff >> i;
  std::cout << i << std::endl;
  buff >> i;
  std::cout << i << std::endl;
  buff >> i;
  std::cout << i << std::endl;
}

int main()
{
  test1();
  test2();
  return (0);
}
