//
// Gomoku.hh for Gomoku.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 16:37:38 2013 sebastien bequignon
// Last update Mon Jun 17 17:21:27 2013 sebastien bequignon
//

#ifndef GOMOKU_H_
# define GOMOKU_H_

#include "GomokuEnum.hh"
#include "GomokuBoard.hh"
#include "GomokuRules.hh"
#include "GomokuPlayer.hh"
#include "GomokuReferee.hh"

namespace Gomoku
{
  class GomokuGame
  {
  private:
    GomokuBoard		board;
    GomokuReferee	referee;
    GomokuHistory	history;
    GomokuPlayer	*player1;
    GomokuPlayer	*player2;
    Gomoku::GameState	state;

  public:
    GomokuGame(uint8_t rule = 0,
	       GomokuPlayer *player1 = NULL,
	       GomokuPlayer *player2 = NULL);
    ~GomokuGame();
    void setRules(uint8_t rule);
    void unsetRules(uint8_t rule);
    void setPlayer(GomokuPlayer *player);
    void start(Gomoku::Symbol first = Gomoku::PLAYER1);
    bool play(uint8_t x, uint8_t y);
    GomokuBoard const &getBoard() const;
    GomokuRules const &getRules() const;
    GomokuPlayer const *getPlayer1() const;
    GomokuPlayer const *getPlayer2() const;
    Gomoku::GomokuHistory const &getHistory() const;
    Gomoku::GameState getState() const;
    Gomoku::PlayerType getTypePlayer() const;
    Gomoku::PlayerType getTypePlayer(Gomoku::Symbol player) const;
    void reset();
  };
}

#endif /* !GOMOKU_H_ */
