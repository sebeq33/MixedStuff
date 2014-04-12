//
// GomokuHuman.hh for GomokuHuman.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun 14 17:38:57 2013 sebastien bequignon
// Last update Fri Jun 14 17:51:23 2013 sebastien bequignon
//

#ifndef GOMOKUHUMAN_H_
# define GOMOKUHUMAN_H_

#include <stdint.h>
#include "GomokuPlayer.hh"
#include "GomokuEnum.hh"

namespace Gomoku
{
  class GomokuHuman : public GomokuPlayer
  {
  public:
    GomokuHuman(Gomoku::Symbol me);
    ~GomokuHuman();
    virtual Gomoku::PlayerType getType() const;
    virtual Gomoku::PlayerType play(GomokuGame &game);
  };
}

#endif /* !GOMOKUHUMAN_H_ */
