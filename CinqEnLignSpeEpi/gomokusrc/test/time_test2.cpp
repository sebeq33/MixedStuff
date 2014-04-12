//
// time_test2.cpp for time_test2.cpp in /home/bequig_s//workspace/ia/gomoku/test
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Jun  9 16:27:32 2013 sebastien bequignon
// Last update Sun Jun  9 16:32:20 2013 sebastien bequignon
//

#include <iostream>
#include "Pattern.hh"

int main()
{
  Pattern pat;

  for (int i = 0; i < 1000000; ++i)
    {
      Pattern val;

      val = 55;

      std::cout << val.getValue() << std::endl;
    }

  return (0);
}
