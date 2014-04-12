//
// GomokuPlayer.cpp for GomokuPlayer.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun 13 19:29:22 2013 sebastien bequignon
// Last update Sat Jun 15 00:18:15 2013 sebastien bequignon
//

#include "GomokuPlayer.hh"

Gomoku::GomokuPlayer::GomokuPlayer(Gomoku::Symbol me)
  : me(me), points(0)
{

}

Gomoku::GomokuPlayer::~GomokuPlayer()
{

}

uint8_t Gomoku::GomokuPlayer::getScore() const
{
  return (points);
}

void Gomoku::GomokuPlayer::addScore(uint8_t points)
{
  this->points += points;
}

Gomoku::Symbol Gomoku::GomokuPlayer::getSymbol() const
{
  return (me);
}

void Gomoku::GomokuPlayer::reset()
{
  points = 0;
}
