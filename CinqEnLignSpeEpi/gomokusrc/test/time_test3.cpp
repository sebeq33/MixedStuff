//
// time_test3.cpp for time_test3.cpp in /home/bequig_s//workspace/ia/gomoku/test
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jun 10 15:25:23 2013 sebastien bequignon
// Last update Thu Jun 13 18:21:20 2013 sebastien bequignon
//

#include <iostream>
#include "GomokuEnum.hh"
#include "Pattern.hh"

//check tout une zone
void test1()
{
  const int	map[10][10] =
    {
      {0,0,1,1,1,1,1,0,0,0}, //hori
      {0,0,0,0,0,0,0,0,0,0},
      {0,0,2,2,2,2,2,0,0,0},
      {0,0,0,1,0,0,0,0,0,0}, //diag
      {0,0,0,0,1,0,1,0,0,0},
      {1,0,0,0,1,1,0,0,0,0}, //vert
      {1,0,0,0,0,0,1,0,0,0},
      {1,0,0,0,0,0,0,1,0,0},
      {1,0,1,0,0,0,0,0,0,0},
      {1,0,0,0,0,1,1,1,1,1}  //hori
    };

  Pattern	pattern(0b0101010101, 10);
  Pattern	check;
  int		res = 0;

  for (int y = 0; y < 10; ++y)
    for (int x = 0; x < 10; ++x)
      {
	uint8_t test = 0;

	if (x < 6)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << static_cast<Gomoku::Symbol>(map[y][x + i]);
	    // std::cout << pattern << " == " << check;
	    if (check.match(pattern, pattern.getSizeMask()))
	      {
		res++;
		// std::cout << " <============== hori [" << y << "; " << x << ']';
	      }
	    test++;
	    // std::cout << std::endl;
	  }
	if (y < 6)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << static_cast<Gomoku::Symbol>(map[y + i][x]);
	    // std::cout << pattern << " == " << check;
	    if (check.match(pattern, pattern.getSizeMask()))
	      {
		res++;
		// std::cout << " <============== vert [" << y << "; " << x << ']';
	      }
	    test++;
	    // std::cout << std::endl;
	  }
	if (test == 2)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << static_cast<Gomoku::Symbol>(map[y + i][x + i]);
	    // std::cout << pattern << " == " << check;
	    if (check.match(pattern, pattern.getSizeMask()))
	      {
		res++;
		// std::cout << " <============== diag [" << y << "; " << x << ']';
	      }
	    // std::cout << std::endl;
	  }
      }

  std::cout << "Result = " << res << std::endl; // normalement == 4
}

//test autour d'une position
void test2()
{
    const int	map[10][10] =
    {
      {0,0,0,0,1,0,0,0,0,0},
      {0,0,0,0,1,0,0,1,0,0},
      {0,0,1,0,1,0,2,0,0,0},
      {0,0,0,1,1,1,0,0,0,0},
      {0,0,0,0,1,0,0,1,0,0},
      {0,0,0,1,0,1,0,0,0,0},
      {0,0,0,0,0,0,1,0,0,0},
      {0,0,0,0,0,0,0,2,0,0},
      {0,0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0,0}
    };
  int		posX = 4;
  int		posY = 4;

  Pattern	pattern(0, 10);
  Pattern	check[4];
  uint32_t	mask;
  int		res = 0;
  int		end;

  for (int i = -5; i < 6; ++i) /* [hori /] */
    {
      int cPosX = posX + i;
      if (cPosX >= 0 && cPosX < 10)
	check[0] << static_cast<Gomoku::Symbol>(map[posY][cPosX]);
      else
	check[0] << static_cast<Gomoku::Symbol>(0);
    }
  for (int i = -5; i < 6; ++i) /* [vert] */
    {
      int cPosY = posY + i;
      if (cPosY >= 0 && cPosY < 10)
	check[1] << static_cast<Gomoku::Symbol>(map[cPosY][posX]);
      else
	check[1] << static_cast<Gomoku::Symbol>(0);
    }
  for (int i = -5; i < 6; ++i) /* [diag /] */
    {
      int cPosY = posY + i;
      int cPosX = posX - i;
      if (cPosY >= 0 && cPosY < 10 && cPosX >= 0 && cPosX < 10)
	check[2] << static_cast<Gomoku::Symbol>(map[cPosY][cPosX]);
      else
	check[2] << static_cast<Gomoku::Symbol>(0);
    }
  for (int i = -5; i < 6; ++i) /* [diag \] */
    {
      int cPosY = posY + i;
      int cPosX = posX + i;
      if (cPosY >= 0 && cPosY < 10 && cPosX >= 0 && cPosX < 10)
	check[3] << static_cast<Gomoku::Symbol>(map[cPosY][cPosX]);
      else
	check[3] << static_cast<Gomoku::Symbol>(0);
    }
  pattern = 0b0101010101;
  mask = pattern.getSizeMask();
  end = 11 - pattern.getSize() / 2;
  for (int i = 0; i < 4; ++i)
    {
      for (int j = 0; j < end; ++j)
	{
	  // std::cout << "==============" << std::endl;
	  // Pattern maskp(mask);
	  // std::cout << "i       = " << i << std::endl;
	  // std::cout << "pattern = " << pattern << std::endl;
	  // std::cout << "maskp   = " << maskp << std::endl;
	  // std::cout << "check   = " << check[i] << std::endl;

	  if (check[i].match(pattern, mask))
	    {
	      // std::cout << "############ found ###########" << std::endl;
	      res++;
	    }
	  // std::cout << std::endl << std::endl;
	  check[i] >>= 2;
	}
    }

  std::cout << "Result = " << res << std::endl; // normalement == 2
}

int main()
{
  // for (int i = 0; i < 10000; ++i)
  //   test1();
  for (int i = 0; i < 10000; ++i)
    test2();
  return (0);
}
