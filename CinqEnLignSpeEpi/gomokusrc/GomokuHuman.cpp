//
// GomokuHuman.cpp for GomokuHuman.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun 14 17:41:31 2013 sebastien bequignon
// Last update Fri Jun 14 17:53:34 2013 sebastien bequignon
//

#include "GomokuGame.hh"
#include "GomokuHuman.hh"

Gomoku::GomokuHuman::GomokuHuman(Gomoku::Symbol me)
  : GomokuPlayer(me)
{

}

Gomoku::GomokuHuman::~GomokuHuman()
{

}

Gomoku::PlayerType Gomoku::GomokuHuman::getType() const
{
  return (Gomoku::HUMAN);
}

Gomoku::PlayerType Gomoku::GomokuHuman::play(GomokuGame &game)
{
  (void) game;
  return (Gomoku::HUMAN);
}
