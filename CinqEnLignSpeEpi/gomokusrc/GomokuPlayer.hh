//
// GomokuPlayer.hh for GomokuPlayer.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 20:33:07 2013 sebastien bequignon
// Last update Wed Jun 19 13:55:59 2013 sebastien bequignon
//

#ifndef GOMOKUPLAYER_H_
# define GOMOKUPLAYER_H_

#include <stdint.h>
#include "GomokuEnum.hh"

namespace Gomoku
{
  class GomokuGame;

  class GomokuPlayer
  {
  private:
    Gomoku::Symbol me : 2;
    uint8_t points : 6;

  public:
    GomokuPlayer(Gomoku::Symbol me);
    virtual ~GomokuPlayer();

    uint8_t	getScore() const;
    void	addScore(uint8_t points = 2);

    Gomoku::Symbol		getSymbol() const;
    virtual Gomoku::PlayerType	getType() const = 0;

    /*
    ** if playerType == PLAYER just return PLAYER
    ** if playerType == IA then let IA play using game and return IA
    */
    virtual Gomoku::PlayerType play(GomokuGame &game) = 0;

    void reset();
  };
}

#endif /* !GOMOKUPLAYER_H_ */
