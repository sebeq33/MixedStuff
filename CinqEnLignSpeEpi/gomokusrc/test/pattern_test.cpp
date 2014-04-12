//
// pattern_test.cpp for pattern_test.cpp in /home/bequig_s//workspace/ia/gomoku/test
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Sun Jun  9 15:52:57 2013 sebastien bequignon
// Last update Sun Jun  9 16:26:02 2013 sebastien bequignon
//

#include <iostream>
#include "GomokuEnum.hh"
#include "Pattern.hh"

int main()
{
  Pattern patterns[] =
    {
      0b01010111,
      0b01010101,
      0b01010110,
      0
    };
  int	i = 0;
  patterns[0] = 0b01010101; //85
  std::cout << patterns[0].getValue() << std::endl;

  while (patterns[i].getValue() != 0 && patterns[i + 1].getValue() != 0)
    {
      std::cout << patterns[i + 1][0] << std::endl;
      if (patterns[i] == patterns[i + 1])
	std::cout << patterns[i].getValue() << " == " <<  patterns[i + 1].getValue() << std::endl;
      else
	std::cout << patterns[i].getValue() << " != " <<  patterns[i + 1].getValue() << std::endl;
      ++i;
    }

  std::cout << std::endl << sizeof(Pattern) << std::endl;;
  return (0);
}
