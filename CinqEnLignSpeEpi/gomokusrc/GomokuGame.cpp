//
// GomokuGame.cpp for GomokuGame.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jun 14 15:32:17 2013 sebastien bequignon
// Last update Mon Jun 24 18:47:18 2013 sebastien bequignon
//

#include "GomokuGame.hh"

Gomoku::GomokuGame::GomokuGame(uint8_t rule,
			       GomokuPlayer *player1,
			       GomokuPlayer *player2)
  : referee(rule), player1(player1), player2(player2), state(Gomoku::NOT_STARTED)
{
}

Gomoku::GomokuGame::~GomokuGame()
{
  if (player1)
    delete player1;
  if (player2)
    delete player2;
}

void Gomoku::GomokuGame::setRules(uint8_t rule)
{
  referee.getRules().enableRule(rule);
  Gomoku::GameState res = referee.checkVictory(board, history, *player1, *player2);
  if (res != NO_WINNER)
    state = res;
}

void Gomoku::GomokuGame::unsetRules(uint8_t rule)
{
  referee.getRules().disableRule(rule);
  Gomoku::GameState res = referee.checkVictory(board, history, *player1, *player2);
  if (res != NO_WINNER)
    state = res;
}

void Gomoku::GomokuGame::setPlayer(GomokuPlayer *player)
{
  if (player->getSymbol() == PLAYER1)
    {
      if (player2)
	delete player2;
      player1 = player;
    }
  else if (player->getSymbol() == PLAYER2)
    {
      if (player2)
	delete player2;
      player2 = player;
    }
}

void Gomoku::GomokuGame::start(Gomoku::Symbol first)
{
  if (state == Gomoku::NOT_STARTED)
    {
      if (first == Gomoku::PLAYER1)
	state = PLAYER1_TURN;
      else if (first == Gomoku::PLAYER2)
	state = PLAYER2_TURN;
    }
}

bool Gomoku::GomokuGame::play(uint8_t x, uint8_t y)
{
  GomokuPlayer *player = NULL;

  switch (state)
    {
    case PLAYER1_TURN:
      player = player1; break;
    case PLAYER2_TURN:
      player = player2; break;
    default:
      return (false);
    }
  if (player == NULL)
    return (false);
  if (!referee.checkPlay(board, *player, x, y))
    return (false);
  referee.play(board, *player, history, x, y);
  Gomoku::GameState res = referee.checkVictory(board, history, *player1, *player2);
  if (res != NO_WINNER)
    state = res;
  else if (state == PLAYER1_TURN)
    state = PLAYER2_TURN;
  else
    state = PLAYER1_TURN;
  return (true);
}

Gomoku::GomokuBoard const &Gomoku::GomokuGame::getBoard() const
{
  return (board);
}

Gomoku::GomokuRules const &Gomoku::GomokuGame::getRules() const
{
  return (referee.getRules());
}

Gomoku::GomokuPlayer const *Gomoku::GomokuGame::getPlayer1() const
{
  return (player1);
}

Gomoku::GomokuPlayer const *Gomoku::GomokuGame::getPlayer2() const
{
  return (player2);
}

Gomoku::GomokuHistory const &Gomoku::GomokuGame::getHistory() const
{
  return (history);
}

Gomoku::GameState Gomoku::GomokuGame::getState() const
{
  return (state);
}

Gomoku::PlayerType Gomoku::GomokuGame::getTypePlayer() const
{
  if (state == PLAYER1_TURN && player1)
    return (player1->getType());
  else if (state == PLAYER2_TURN && player2)
    return (player2->getType());
  return (Gomoku::UNKNOWN);
}

Gomoku::PlayerType Gomoku::GomokuGame::getTypePlayer(Gomoku::Symbol p) const
{
  if (p == PLAYER1 && player1)
    return (player1->getType());
  else if (p == PLAYER2 && player2)
    return (player2->getType());
  return (Gomoku::UNKNOWN);
}

void Gomoku::GomokuGame::reset()
{
  board.reset();
  referee.reset();
  if (player1)
    player1->reset();
  if (player2)
    player2->reset();
  history.clear();
  state = Gomoku::NOT_STARTED;
}
