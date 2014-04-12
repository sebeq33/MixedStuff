//
// GomokuEnum.hh for GomokuEnum.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 15:17:09 2013 sebastien bequignon
// Last update Sun Jun  9 16:46:09 2013 sebastien bequignon
//

#ifndef GOMOKUENUM_H_
# define GOMOKUENUM_H_

#include <list>
#include <stdint.h>

namespace Gomoku
{
  enum GameState
    {
      NOTSTARTED,
      PLAYER1_TURN,
      PLAYER2_TURN,
      PLAYER1_WIN,
      PLAYER2_WIN,
      NO_WINNER,
      DRAW,
      ERROR
    };

  enum Symbol
    {
      EMPTY = 0,
      PLAYER1 = 1,
      PLAYER2 = 2,
      OUT = 3
    };

  struct Turn
  {
    uint8_t x;
    uint8_t y;
    GameState state;
  };

  struct Point
  {
    uint8_t x;
    uint8_t y;
  };

  typedef std::list<Turn> GomokuHistory;
};

#endif /* !GOMOKUENUM_H_ */
