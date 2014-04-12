//
// GomokuReferee.cpp for GomokuReferee.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun  7 17:31:19 2013 sebastien bequignon
// Last update Tue Jul 30 10:38:47 2013 sebastien bequignon
//

#include "GomokuReferee.hh"

Gomoku::GomokuReferee::GomokuReferee(const GomokuRules &val)
  : rules(val)
{
}

Gomoku::GomokuReferee::~GomokuReferee()
{
}

void Gomoku::GomokuReferee::setRules(const GomokuRules &rules)
{
  this->rules = rules;
}

Gomoku::GomokuRules &Gomoku::GomokuReferee::getRules()
{
  return (rules);
}

const Gomoku::GomokuRules &Gomoku::GomokuReferee::getRules() const
{
  return (rules);
}

void Gomoku::GomokuReferee::updatePlacement(GomokuBoard &board, int8_t x, int8_t y) const
{
  (void) board;
  (void) x;
  (void) y;
  // for (int i = 0; i < 11; ++i)
  //   {

  //   }
}

uint8_t Gomoku::GomokuReferee::checkTake(GomokuBoard &board, Gomoku::Symbol player, int8_t x, int8_t y) const
{
  int		score = 0;

  if (rules == Gomoku::TAKESTONE)
    {
      Gomoku::Symbol	foe = (player == PLAYER1) ? PLAYER2 : PLAYER1;
      int8_t		dirX[8] = {0,  1,  0, -1,  1, -1, -1,  1};
      int8_t		dirY[8] = {1,  0, -1,  0,  1, -1,  1, -1};
      Pattern		check;
      Pattern		take;

      take << player << foe << foe << player;

      for (int8_t i = 0; i < 8; ++i)
  	{
  	  int8_t cx = x + (3 * dirX[i]);
  	  if (cx < 0 || cx > 18)
  	    continue ;
  	  int8_t cy = y + (3 * dirY[i]);
  	  if (cy < 0 || cy > 18)
  	    continue ;
  	  cx = x;
  	  cy = y;
  	  check = 0;
  	  for (int8_t j = 0; j < 4; ++j)
  	    {
  	      check << board(cx, cy);
  	      cx += dirX[i];
  	      cy += dirY[i];
  	    }
  	  if (check == take)
  	    {
  	      board.setCase(x + dirX[i],
  			    y + dirY[i],
  			    Gomoku::EMPTY);
  	      board.setCase(x + (2 * dirX[i]),
  			    y + (2 * dirY[i]),
  			    Gomoku::EMPTY);
	      if (foe == Gomoku::PLAYER1)
		{
		  board.setTakeState(x + dirX[i],
				     y + dirY[i],
				     Gomoku::PLAYER1_TOOK);
		  board.setTakeState(x + (dirX[i] * 2),
				     y + (dirY[i] * 2),
				     Gomoku::PLAYER1_TOOK);
		}
	      else
		{
		  board.setTakeState(x + dirX[i],
				     y + dirY[i],
				     Gomoku::PLAYER2_TOOK);
		  board.setTakeState(x + (dirX[i] * 2),
				     y + (dirY[i] * 2),
				     Gomoku::PLAYER2_TOOK);
		}
  	      score += 2;
  	    }
  	}
    }
  return (score);
}

bool Gomoku::GomokuReferee::checkDoubleThree(const GomokuBoard &board, Gomoku::Symbol p, int8_t x, int8_t y) const
{
  if (rules == Gomoku::DOUBLETHREE)
    {
      Pattern check[4];
      Pattern align3[3];
      Gomoku::Symbol player = p;
      int8_t res = 0;

      fillPos(check, player, board, x, y);

      align3[0].setSize(5);
      align3[0] << Gomoku::EMPTY
  		<< player
  		<< player
  		<< player
  		<< Gomoku::EMPTY;

      align3[1].setSize(6);
      align3[1] << Gomoku::EMPTY
  		<< player
  		<< player
  		<< Gomoku::EMPTY
  		<< player
  		<< Gomoku::EMPTY;

      align3[2].setSize(6);
      align3[2] << Gomoku::EMPTY
  		<< player
  		<< Gomoku::EMPTY
  		<< player
  		<< player
  		<< Gomoku::EMPTY;

      for (int i = 0; i < 4; ++i)
  	{
  	  for (int j = 0; j < 3; ++j)
  	    {
  	      Pattern current(check[i]);
  	      uint32_t mask = align3[j].getSizeMask();
  	      int8_t end = 11 - (align3[j].getSize() / 2);

  	      for (int k = 0; k < end; ++k)
  		{
  		  if (current.match(align3[j], mask))
		    {
		      res++;
		    }
  		  current >>= 2;
  		}
  	    }
  	}

      if (res >= 2)
  	return (true);
    }
  return (false);
}

// fill the 4 directions 5 in both way adding actual between
// each pattern are filled by 11 * 2 bits
void Gomoku::GomokuReferee::fillPos(Pattern check[4],
			    Gomoku::Symbol actual,
			    GomokuBoard const &board,
			    int8_t posX,
			    int8_t posY) const
{
  for (int8_t i = 0; i < 4; ++i)
    check[i] = 0;
  for (int8_t i = -5; i < 6; ++i) /* [hori /] */
    {
      if (i == 0)
	check[0] << actual;
      else
	{
	  int8_t cPosX = posX + i;
	  if (cPosX >= 0 && cPosX < 19)
	    check[0] << board(cPosX, posY);
	  else
	    check[0] << Gomoku::OUT;
	}
    }
  for (int8_t i = -5; i < 6; ++i) /* [vert] */
    {
      if (i == 0)
	check[1] << actual;
      else
	{
	  int8_t cPosY = posY + i;
	  if (cPosY >= 0 && cPosY < 19)
	    check[1] << board(posX, cPosY);
	  else
	    check[1] << Gomoku::OUT;
	}
    }
  for (int8_t i = -5; i < 6; ++i) /* [diag /] */
    {
      if (i == 0)
	check[2] << actual;
      else
	{
	  int8_t cPosY = posY + i;
	  int8_t cPosX = posX - i;
	  if (cPosY >= 0 && cPosY < 19 && cPosX >= 0 && cPosX < 19)
	    check[2] << board(cPosX, cPosY);
	  else
	    check[2] << Gomoku::OUT;
	}
    }
  for (int8_t i = -5; i < 6; ++i) /* [diag \] */
    {
      if (i == 0)
	check[3] << actual;
      else
	{
	  int8_t cPosY = posY + i;
	  int8_t cPosX = posX + i;
	  if (cPosY >= 0 && cPosY < 19 && cPosX >= 0 && cPosX < 19)
	    check[3] << board(cPosX, cPosY);
	  else
	    check[3] << Gomoku::OUT;
	}
    }
}

bool Gomoku::GomokuReferee::checkPlay(const GomokuBoard &board,
			      const GomokuPlayer &p,
			      int8_t x,
			      int8_t y) const
{
  if (x < 0 || y < 0 || x > 18 || y > 18 || board.getCase(x, y) != Gomoku::EMPTY)
    return (false);
  if (checkDoubleThree(board, p.getSymbol(), x, y))
    return (false);
  return (true);
}

bool Gomoku::GomokuReferee::tryPlay(GomokuBoard &board,
				    GomokuPlayer &p,
				    Gomoku::GomokuHistory &history,
				    int8_t x,
				    int8_t y)
{
  if (!checkPlay(board, p, x, y))
    return (false);
  play(board, p, history, x, y);
  return (true);
}

void Gomoku::GomokuReferee::play(GomokuBoard &board,
				 GomokuPlayer &p,
				 GomokuHistory &history,
				 int8_t x,
				 int8_t y)
{
  Gomoku::Turn  turn =
    {
      x,
      y,
      (p.getSymbol() == Gomoku::PLAYER1) ? Gomoku::PLAYER1_TURN : Gomoku::PLAYER2_TURN
    };

  board.setCase(x, y, p.getSymbol());
  history.push_back(turn);
  p.addScore(checkTake(board, p.getSymbol(), x, y));
  this->updatePlacement(board, x, y);
  // this->updateIsPlayable(board, x, y);
}

Gomoku::GameState Gomoku::GomokuReferee::compareFive(Pattern &check,
					uint8_t x,
					uint8_t y,
					int8_t dirx,
					int8_t diry)
{
  if (rules == (Gomoku::BREAKABLE_FIVE | Gomoku::TAKESTONE))
    {
      Five five = {Gomoku::PLAYER1, x, y, dirx, diry};
      if (check == 0b0101010101)
	currentFives.push_back(five);
      five.p = Gomoku::PLAYER2;
      if (check == 0b1010101010)
	currentFives.push_back(five);
      return (Gomoku::NO_WINNER);
    }

  if (check == 0b0101010101)
    return (Gomoku::PLAYER1_WIN);
  if (check == 0b1010101010)
    return (Gomoku::PLAYER2_WIN);
  return (Gomoku::NO_WINNER);
}


Gomoku::GameState Gomoku::GomokuReferee::checkVictory(GomokuBoard   const &board,
						      GomokuHistory const &history,
						      GomokuPlayer  const &player1,
						      GomokuPlayer  const &player2)
{
  if (history.size() < 9)
    return (Gomoku::NO_WINNER);
  if (player1.getScore() > 9)
    return (Gomoku::PLAYER1_WIN);
  if (player2.getScore() > 9)
    return (Gomoku::PLAYER2_WIN);

  Pattern	check;
  GameState	tmp;
  bool		full = true;

  for (int y = 0; y < 19; ++y)
    for (int x = 0; x < 19; ++x)
      {
	if (full && board(x, y) == Gomoku::EMPTY)
	  full = false;
	if (x < 15)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << board(x + i, y);
	    if ((tmp = compareFive(check, x, y, 1, 0)) != Gomoku::NO_WINNER)
	      return (tmp);
	  }
	if (y < 15)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << board(x, y + i);
	    if ((tmp = compareFive(check, x, y, 0, 1)) != Gomoku::NO_WINNER)
	      return (tmp);
	  }
	if (x < 15 && y < 15)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << board(x + i, y + i);
	    if ((tmp = compareFive(check, x, y, 1, 1)) != Gomoku::NO_WINNER)
	      return (tmp);
	  }
	if (x > 3 && y < 15)
	  {
	    check = 0;
	    for (int i = 0; i < 5; ++i)
	      check << board(x - i, y + i);
	    if ((tmp = compareFive(check, x, y, -1, 1)) != Gomoku::NO_WINNER)
	      return (tmp);
	  }
      }

  if (rules == (Gomoku::BREAKABLE_FIVE | Gomoku::TAKESTONE) && currentFives.size() > 0)
    {
      if ((tmp = checkBreakableFive(board)) != Gomoku::NO_WINNER)
  	return (tmp);
      this->reset();
    }
  return (full ? Gomoku::DRAW : Gomoku::NO_WINNER);
}

Gomoku::GameState Gomoku::GomokuReferee::checkBreakableFive(GomokuBoard const &board)
{
  int8_t		dirX[8] = {0,  1,  0, -1,  1, -1, -1,  1};
  int8_t		dirY[8] = {1,  0, -1,  0,  1, -1,  1, -1};
  Gomoku::GameState	state = Gomoku::NO_WINNER;
  std::list<Five>::iterator it;

  it = currentFives.begin();
  while (it != currentFives.end()) //loop on each five repered
    {
      Five		current = *it;
      Gomoku::Symbol	foe = (current.p == PLAYER1) ? PLAYER2 : PLAYER1;
      Pattern		patterns[2];
      int8_t		cx;
      int8_t		cy;

      patterns[0].setSize(4);
      patterns[0] << Gomoku::EMPTY << current.p << current.p << foe;
      patterns[1].setSize(4);
      patterns[1] << foe << current.p << current.p << Gomoku::EMPTY;

      for (int pos = 0; pos < 5; ++pos) //loop on each 5 pos of align five
	{
	  for (int8_t i = 0; i < 8; ++i) //loop on 8 directions
	    {
	      if ((dirX[i] == current.dirx && dirY[i] == current.diry) ||
		  (dirX[i] == (current.dirx * -1) && dirY[i] == (current.diry * -1)))
		continue ;
	      cx = current.x + (2 * dirX[i]);
	      if (cx < 0 || cx > 18)
		continue ;
	      cy = current.y + (2 * dirY[i]);
	      if (cy < 0 || cy > 18)
		continue ;
	      cx = current.x - dirX[i];
	      if (cx < 0 || cx > 18)
		continue ;
	      cy = current.y - dirY[i];;
	      if (cy < 0 || cy > 18)
		continue ;

	      Pattern check;
	      for (int8_t j = 0; j < 4; ++j) //loop on board for getting pattern
		{
		  check << board(cx, cy);
		  cx += dirX[i];
		  cy += dirY[i];
		}
	      if (check == patterns[0] || check == patterns[1]) //if breakable
		{
		  pos = 5; // break until pos align loop continuing on next five
		  break ;
		}
	    }
	  if (pos == 4) //if not breakable
	    {
	      if (current.p == Gomoku::PLAYER1)
		{
		  if (state == PLAYER2_WIN)
		    return (Gomoku::DRAW);
		  state = PLAYER1_WIN;
		}
	      else
		{
		  if (state == PLAYER1_WIN)
		    return (Gomoku::DRAW);
		  state = PLAYER2_WIN;
		}
	    }
	  current.x += current.dirx;
	  current.y += current.diry;
	}
      ++it;
    }
  return (state);
}

void	Gomoku::GomokuReferee::reset()
{
  currentFives.clear();
}
