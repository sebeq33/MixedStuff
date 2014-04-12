//
// GomokuEnum.hh for GomokuEnum.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 15:17:09 2013 sebastien bequignon
// Last update Tue Jun 25 15:03:39 2013 sebastien bequignon
//

#ifndef GOMOKUENUM_H_
# define GOMOKUENUM_H_

#include <list>
#include <stdint.h>

namespace Gomoku
{
  enum Knowledge
    {
      NOTHING		= 0,
      ONE		= 1,
      TWO		= 2,
      THREE		= 3,
      THREE_FREE	= 4,
      FOUR		= 5,
      FIVE		= 6,
      TAKE		= 7
    };

  enum Direction
    {
      LEFT		= 0,
      TOP_LEFT		= 1,
      UP		= 2,
      TOP_RIGHT		= 3,
      RIGHT		= 4,
      BOTTOM_RIGHT	= 5,
      DOWN		= 6,
      BOTTOM_LEFT	= 7
    };

  enum TakeState
    {
      NORMAL		= 0,
      PLAYER1_TOOK	= 1,
      PLAYER2_TOOK	= 2,
      TAKEABLE		= 3
    };

  enum Rules
    {
      DOUBLETHREE	= 1,
      BREAKABLE_FIVE	= 2,
      TAKESTONE		= 4
    };

  enum GameState
    {
      NOT_STARTED,
      PLAYER1_TURN,
      PLAYER2_TURN,
      PLAYER1_WIN,
      PLAYER2_WIN,
      NO_WINNER,
      DRAW,
      ERROR
    };

  enum PlayerType
    {
      IA,
      HUMAN,
      UNKNOWN
    };

  enum Symbol
    {
      EMPTY	= 0,
      PLAYER1	= 1,
      PLAYER2	= 2,
      OUT	= 3
    };

  struct Turn
  {
    uint8_t	x : 6;
    uint8_t	y : 6;
    GameState	state : 8;
  };

  typedef std::list<Turn> GomokuHistory;
};

#endif /* !GOMOKUENUM_H_ */
