//
// GomokuBoard.cpp for GomokuBoard.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 16:10:40 2013 sebastien bequignon
// Last update Thu Jul 25 17:22:11 2013 sebastien bequignon
//

#include "GomokuBoard.hh"

/*
** constructor / destructor
*/

Gomoku::GomokuBoard::GomokuBoard()
{
  map = new uint32_t[19 * 19];
  reset();
}

Gomoku::GomokuBoard::GomokuBoard(GomokuBoard const &other)
{
  map = new uint32_t[19 * 19];
  for (int i = 0; i < 19 * 19; ++i)
    map[i] = other.map[i];
}

Gomoku::GomokuBoard::~GomokuBoard()
{
  erase();
}

Gomoku::GomokuBoard const &Gomoku::GomokuBoard::operator=(const GomokuBoard & other)
{
  if (this != &other)
    {
      for (int i = 0; i < 19; ++i)
	for (int j = 0; j < 19; ++j)
	  map[j + (i * 19)] = other.map[j + (i * 19)];
    }
  return (*this);
}

void Gomoku::GomokuBoard::reset()
{
  for (int i = 0; i < 19 * 19; ++i)
    map[i] = 0;
}

/*
** remove everything but symbol's data
*/
void Gomoku::GomokuBoard::resetData()
{
  for (int i = 0; i < 19 * 19; ++i)
    map[i] &= ~3;
}

/*
** destroy the instance to free memory earlier
*/
void Gomoku::GomokuBoard::erase()
{
  if (map != NULL)
    delete[] map;
  map = NULL;
}

/*
** Symbols
*/

void Gomoku::GomokuBoard::setCase(int x, int y, Gomoku::Symbol val)
{
  map[x + (y * 19)] &= ~3;
  map[x + (y * 19)] |= val;
}

Gomoku::Symbol Gomoku::GomokuBoard::getCase(int x, int y) const
{
  return (static_cast<Gomoku::Symbol> (map[x + (y * 19)] & 3));
}

Gomoku::Symbol Gomoku::GomokuBoard::operator()(int x, int y) const
{
  return (this->getCase(x, y));
}

/*
** General knowledge
*/
uint32_t Gomoku::GomokuBoard::getKnowledge(int x, int y) const
{
  return (map[x + (y * 19)]);
}

/*
** Direction's knowledge
*/
void	Gomoku::GomokuBoard::setDirection(int x, int y, Gomoku::Direction dir, uint8_t k)
{
  uint32_t decal = ((dir * 3) + 2);
  map[x + (y * 19)] &= ~(7 << decal); // 7 => 3 bits at 1
  map[x + (y * 19)] |= (k << decal);
}

uint8_t Gomoku::GomokuBoard::getDirection(int x, int y, Gomoku::Direction dir) const
{
  return ((map[x + (y * 19)] >> ((dir * 3) + 2)) & 7);
}

bool	Gomoku::GomokuBoard::isSet(int x, int y, Gomoku::Direction dir, uint8_t k) const
{
  return (((map[x + (y * 19)] >> ((dir * 3) + 2)) & 7) == k);
}

/*
** state's knowledge
*/

void			Gomoku::GomokuBoard::setTakeState(int x, int y, Gomoku::TakeState s)
{
  map[x + (y * 19)] &= ~(2 << 26);
  map[x + (y * 19)] |= (s << 26);
}

Gomoku::TakeState	Gomoku::GomokuBoard::getTakeState(int x, int y) const
{
  return (static_cast<Gomoku::TakeState> ((map[x + (y * 19)] >> 26) & 2));
}

bool			Gomoku::GomokuBoard::isSet(int x, int y, Gomoku::TakeState s) const
{
  return (((map[x + (y * 19)] >> 26) & 2) == s);
}

// check's knowledge
void	Gomoku::GomokuBoard::setPlayable(int x, int y, Gomoku::Symbol p, bool playable)
{
  if (p != Gomoku::PLAYER1 && p != Gomoku::PLAYER2)
    return ;
  map[x + (y * 19)] &= ~(1 << (27 + p));
  map[x + (y * 19)] |= playable  << (27 + p);
}

bool	Gomoku::GomokuBoard::isPlayable(int x, int y, Gomoku::Symbol p) const
{
  if (p != Gomoku::PLAYER1 && p != Gomoku::PLAYER1)
    return (false);
  return (((map[x + (y * 19)] >> (27 + p)) & 1) == 1);
}

/*
** pattern's utilities
*/

Pattern &Gomoku::GomokuBoard::fill(Pattern &dst,
				   uint8_t x,
				   uint8_t y,
				   int8_t dirX,
				   int8_t dirY,
				   uint8_t size) const
{
  int8_t cx = x;
  int8_t cy = y;

  for (uint8_t i = 0; i < size; ++i)
    {
      if (cx < 0 || cy < 0 || cx > 18 || cy > 18)
	dst << Gomoku::OUT;
      else
	dst << getCase(cx, cy);
      cx += dirX;
      cy += dirY;
    }
  return (dst);
}

/*
** board's utilities
*/

void Gomoku::GomokuBoard::dump() const
{
  for (int y = 0; y < 19; ++y)
    {
      for (int x = 0; x < 19; ++x)
	{
	  switch ((map[x + (y * 19)] & 3)) // 3 => 2 bit at 1
	    {
	    case Gomoku::EMPTY:
	      std::cout << '-'; break;
	    case Gomoku::PLAYER1:
	      std::cout << 'X'; break;
	    case Gomoku::PLAYER2:
	      std::cout << '0'; break;
	    default:
	      std::cout << '?'; break;
	    }
	}
      std::cout << std::endl;
    }
}

void Gomoku::GomokuBoard::dumpbit() const
{
  for (int y = 0; y < 19; ++y)
    for (int x = 0; x < 19; ++x)
      this->dumpbit(x, y);
}

void Gomoku::GomokuBoard::dumpbit(int x, int y) const
{
  std::cout << '[';
  if (x < 10)
    std::cout << ' ';
  std::cout << x << ", ";
  if (y < 10)
    std::cout << ' ';
  std::cout << y << "] : ";
  display_bit(reinterpret_cast<char *> (&map[x + (y * 19)]), sizeof(map[0]));
  std::cout << std::endl;
}

void Gomoku::GomokuBoard::display_bit(char *bytes, size_t size) const
{
  int32_t      i;

  while (size > 0)
    {
      i = 7;
      while (i >= 0)
	{
	  std::cout << (char) ((((bytes[size - 1]) >> i) & 0x01) + '0');
	  i--;
	}
      if (--size > 0)
	std::cout << '.';
    }
}
