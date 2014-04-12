//
// GomokuReferee.hh for GomokuReferee.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 15:44:27 2013 sebastien bequignon
// Last update Tue Jul 30 10:39:28 2013 sebastien bequignon
//

#ifndef GOMOKUREFEREE_H_
# define GOMOKUREFEREE_H_

#include <list>
#include "GomokuEnum.hh"
#include "GomokuBoard.hh"
#include "GomokuRules.hh"
#include "GomokuPlayer.hh"
#include "Pattern.hh"

namespace Gomoku
{
  class GomokuReferee
  {
  private:
    struct Five
    {
      Gomoku::Symbol p;
      int8_t x;
      int8_t y;
      int8_t dirx;
      int8_t diry;
    };
    std::list<Five> currentFives;
    GomokuRules		rules;

    Gomoku::GameState checkBreakableFive(GomokuBoard const &board);
    Gomoku::GameState compareFive(Pattern &check,
				  uint8_t x,
				  uint8_t y,
				  int8_t dirx,
				  int8_t diry);
      void fillPos(Pattern check[4],
		 Gomoku::Symbol actual,
		 GomokuBoard const &board,
		 int8_t posX,
		 int8_t posY) const;
    void updatePlacement(GomokuBoard &board, int8_t x, int8_t y) const;
    uint8_t checkTake(GomokuBoard &board, Gomoku::Symbol p, int8_t x, int8_t y) const;
    bool checkDoubleThree(const GomokuBoard &board, Gomoku::Symbol p, int8_t x, int8_t y) const;

  public:
    GomokuReferee(const GomokuRules &rules = 0);
    ~GomokuReferee();

    void setRules(const GomokuRules &rules);
    const GomokuRules &getRules() const;
    GomokuRules &getRules();
    void reset();

    bool checkPlay(const GomokuBoard &board,
		   const GomokuPlayer &p,
		   int8_t x,
		   int8_t y) const;
    bool tryPlay(GomokuBoard &board,
		 GomokuPlayer &p,
		 Gomoku::GomokuHistory &history,
		 int8_t x,
		 int8_t y);
    void play(GomokuBoard &board,
	      GomokuPlayer &p,
	      GomokuHistory &history,
	      int8_t x,
	      int8_t y);
    Gomoku::GameState checkVictory(GomokuBoard   const &board,
				   GomokuHistory const &history,
				   GomokuPlayer  const &p,
				   GomokuPlayer  const &p2);
  };
}

#endif /* !GOMOKUREFEREE_H_ */

