//
// Map.hh for Map.hh in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 15:44:43 2013 sebastien bequignon
// Last update Thu Jul 25 17:20:38 2013 sebastien bequignon
//

#ifndef  GOMOKUBOARD_H_
# define GOMOKUBOARD_H_

#include <iostream>
#include <stdint.h>
#include "GomokuEnum.hh"
#include "Pattern.hh"

namespace Gomoku
{
  class GomokuBoard
  {
  private:
    uint32_t *map;

    void display_bit(char *bytes, size_t size) const;

  public:
    GomokuBoard();
    GomokuBoard(GomokuBoard const &);
    ~GomokuBoard();
    GomokuBoard const &operator=(const GomokuBoard & other);

    // Symbols
    void		setCase(int x, int y, Gomoku::Symbol val);
    Gomoku::Symbol	getCase(int x, int y) const;
    Gomoku::Symbol	operator()(int x, int y) const;

    // general knowledge
    uint32_t	getKnowledge(int x, int y) const;

    // direction's knowledge
    void	setDirection(int x, int y, Gomoku::Direction dir, uint8_t k);
    uint8_t	getDirection(int x, int y, Gomoku::Direction dir) const;
    bool	isSet(int x, int y, Gomoku::Direction dir, uint8_t k) const;

    // state's knowledge
    void		setTakeState(int x, int y, Gomoku::TakeState s);
    Gomoku::TakeState	getTakeState(int x, int y) const;
    bool		isSet(int x, int y, Gomoku::TakeState s) const;

    // check's knowledge
    void	setPlayable(int x, int y, Gomoku::Symbol p, bool playable);
    bool	isPlayable(int x, int y, Gomoku::Symbol p) const;

    // Pattern's utilities
    Pattern &fill(Pattern &dst,
		  uint8_t x,
		  uint8_t y,
		  int8_t dirX,
		  int8_t dirY,
		  uint8_t size = 5) const;

    // board's utilities
    void dump() const;
    void dumpbit() const;
    void dumpbit(int x, int y) const;
    void reset();	//set all values to 0 and symbols to empty
    void resetData();	//reset all values but Symbols
    void erase();	//free tab completely
  };
}

#endif /* !GOMOKUBOARD_H_ */
