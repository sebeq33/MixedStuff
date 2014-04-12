//
// main.cpp for main.cpp in /home/bequig_s//workspace/ia/gomoku
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jun  6 16:29:34 2013 sebastien bequignon
// Last update Tue Jun 25 17:52:37 2013 sebastien bequignon
//

#include "GomokuGame.hh"
#include "GomokuPlayer.hh"
#include "GomokuHuman.hh"
#include "Pattern.hh"

void test0()
{
  Gomoku::GomokuBoard	board;
  Pattern		pat;

  std::cout << "KNOWLEDGE DIRECTIONS ===================================" << std::endl;

  board.setCase(5, 5, Gomoku::PLAYER2);
  board.dumpbit(5, 5);

  board.setDirection(5, 5, Gomoku::UP, Gomoku::TAKE);
  board.dumpbit(5, 5);
  board.setDirection(5, 5, Gomoku::TOP_LEFT, Gomoku::TAKE);
  board.dumpbit(5, 5);
  board.setDirection(5, 5, Gomoku::LEFT, Gomoku::TAKE);
  board.dumpbit(5, 5);
  std::cout << std::endl;

  board.setDirection(5, 5, Gomoku::UP, Gomoku::ONE);
  board.dumpbit(5, 5);
  std::cout << "Direction UP ONE     : " << board.isSet(5, 5, Gomoku::UP, Gomoku::ONE) << std::endl;
  std::cout << "Direction UP TAKE    : " << board.isSet(5, 5, Gomoku::UP, Gomoku::TAKE) << std::endl;
  std::cout << std::endl;

  board.setDirection(5, 5, Gomoku::UP, Gomoku::NOTHING);
  board.dumpbit(5, 5);
  std::cout << "Direction UP NOTHING : " << board.isSet(5, 5, Gomoku::UP, Gomoku::NOTHING) << std::endl;
  std::cout << "Direction UP TAKE    : " << board.isSet(5, 5, Gomoku::UP, Gomoku::TAKE) << std::endl;
  std::cout << std::endl;

  board.dump();
  std::cout << std::endl;

  std::cout << std::endl << "KNOWLEDGE STATE =========================================" << std::endl;

  board.dumpbit(5, 5);
  board.setTakeState(5, 5, Gomoku::PLAYER1_TOOK);
  board.dumpbit(5, 5);
  board.setTakeState(5, 5, Gomoku::TAKEABLE);
  board.dumpbit(5, 5);

  std::cout << std::endl << "KNOWLEDGE CHECK =========================================" << std::endl;

  board.setCase(6, 6, Gomoku::PLAYER2);
  board.dumpbit(6, 6);
  board.setChecked(6, 6, Gomoku::LEFT, true);
  board.setChecked(6, 6, Gomoku::TOP_LEFT, true);
  board.setChecked(6, 6, Gomoku::UP, true);
  board.setChecked(6, 6, Gomoku::TOP_RIGHT, true);
  board.dumpbit(6, 6);
  board.setChecked(6, 6, Gomoku::LEFT, false);
  board.setChecked(6, 6, Gomoku::TOP_LEFT, false);
  board.dumpbit(6, 6);

  std::cout << std::endl << "KNOWLEDGE ALL =========================================" << std::endl;

  board.setCase(7, 7, Gomoku::OUT);
  board.setDirection(7, 7, Gomoku::LEFT		, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::TOP_LEFT	, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::UP		, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::TOP_RIGHT	, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::RIGHT	, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::BOTTOM_RIGHT	, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::DOWN		, Gomoku::TAKE);
  board.setDirection(7, 7, Gomoku::BOTTOM_LEFT	, Gomoku::TAKE);
  board.setTakeState(7, 7, Gomoku::TAKEABLE);
  board.setChecked(7, 7, Gomoku::LEFT, true);
  board.setChecked(7, 7, Gomoku::TOP_LEFT, true);
  board.setChecked(7, 7, Gomoku::UP, true);
  board.setChecked(7, 7, Gomoku::TOP_RIGHT, true);
  board.dumpbit(7, 7);

  std::cout << std::endl << "PATTERN =================================================" << std::endl;

  // PATTERN
  pat = 0b01010101;
  std::cout << "Pattern : " << pat << std::endl;

  board.setCase(14, 14, Gomoku::PLAYER1);
  board.setCase(14, 15, Gomoku::PLAYER1);
  board.setCase(14, 16, Gomoku::PLAYER1);
  board.setCase(14, 17, Gomoku::PLAYER1);
  board.setCase(14, 18, Gomoku::PLAYER1);
  pat = 0;
  board.fill(pat, 14, 14, 0, 1, 5);
  std::cout << "Pattern : " << pat << std::endl;

  pat = 0;
  board.fill(pat, 14, 14, 0, 1, 11);
  std::cout << "Pattern : " << pat << std::endl;

  std::cout << std::endl; board.dump();
}

void test1()
{
  Gomoku::GomokuHistory history;
  Gomoku::GomokuBoard	board;
  Gomoku::GomokuReferee referee(Gomoku::DOUBLETHREE);
  Gomoku::GomokuPlayer	*player = new Gomoku::GomokuHuman(Gomoku::PLAYER1);

  std::cout << "[10; 10] : " << referee.tryPlay(board, *player, history, 10, 10) << std::endl;

  board.dumpbit();
  delete player;
}

void test2()
{
  Gomoku::GomokuHistory history;
  Gomoku::GomokuBoard	board;
  Gomoku::GomokuReferee referee(Gomoku::DOUBLETHREE);
  Gomoku::GomokuPlayer	*player = new Gomoku::GomokuHuman(Gomoku::PLAYER1);

  board.setCase(10, 10, Gomoku::PLAYER1); //normal case
  board.setCase(11, 10, Gomoku::PLAYER1); // - N - x x
  board.setCase(9, 12, Gomoku::PLAYER1);  // - x - - -
  board.setCase(9, 13, Gomoku::PLAYER1);  // - x - - -

  board.setCase(5, 0, Gomoku::PLAYER1); //special case
  board.setCase(6, 0, Gomoku::PLAYER1); // x x - Y x x
  board.setCase(9, 0, Gomoku::PLAYER1);
  board.setCase(10, 0, Gomoku::PLAYER1);

  board.setCase(5, 5, Gomoku::PLAYER1); //special case
  board.setCase(6, 5, Gomoku::PLAYER1); // - - - N -
  board.setCase(7, 5, Gomoku::PLAYER1); // - x x x -
  board.setCase(7, 6, Gomoku::PLAYER1); // - - - x -

  board.dump();

  std::cout << "===================================" << std::endl;
  std::cout << "[10; 10] : " << referee.tryPlay(board, *player, history, 10, 10) << std::endl;
  std::cout << "[ 9; 10] : " << referee.tryPlay(board, *player, history, 9, 10) << std::endl;
  std::cout << "[ 9; 11] : " << referee.tryPlay(board, *player, history, 9, 11) << std::endl;
  std::cout << "[ 9; 10] : " << referee.tryPlay(board, *player, history, 9, 10) << std::endl;
  std::cout << "[ 7;  0] : " << referee.tryPlay(board, *player, history, 7, 0) << std::endl;
  std::cout << "[ 7;  4] : " << referee.tryPlay(board, *player, history, 7, 4) << std::endl;
  std::cout << "===================================" << std::endl;

  board.dump();

  delete player;
}

void test3()
{
  Gomoku::GomokuHistory history;
  Gomoku::GomokuBoard	board;
  Gomoku::GomokuReferee referee(Gomoku::TAKESTONE);
  Gomoku::GomokuPlayer	*player = new Gomoku::GomokuHuman(Gomoku::PLAYER1);

  board.setCase(0, 1, Gomoku::PLAYER2);
  board.setCase(0, 2, Gomoku::PLAYER2);
  board.setCase(0, 3, Gomoku::PLAYER2);
  board.setCase(0, 4, Gomoku::PLAYER2);
  board.setCase(0, 5, Gomoku::PLAYER2);

  board.setCase(10, 7, Gomoku::PLAYER1);
  board.setCase(10, 8, Gomoku::PLAYER2);
  board.setCase(10, 9, Gomoku::PLAYER2);

  board.setCase(10, 11, Gomoku::PLAYER2);
  board.setCase(10, 12, Gomoku::PLAYER2);
  board.setCase(10, 13, Gomoku::PLAYER1);

  board.setCase(7, 10, Gomoku::PLAYER1);
  board.setCase(8, 10, Gomoku::PLAYER2);
  board.setCase(9, 10, Gomoku::PLAYER2);

  board.setCase(11, 10, Gomoku::PLAYER2);
  board.setCase(12, 10, Gomoku::PLAYER2);
  board.setCase(13, 10, Gomoku::PLAYER1);

  board.setCase(11, 11, Gomoku::PLAYER2);
  board.setCase(12, 12, Gomoku::PLAYER2);
  board.setCase(13, 13, Gomoku::PLAYER1);

  board.setCase(9, 9, Gomoku::PLAYER2);
  board.setCase(8, 8, Gomoku::PLAYER2);
  board.setCase(7, 7, Gomoku::PLAYER1);

  board.setCase(9, 11, Gomoku::PLAYER2);
  board.setCase(8, 12, Gomoku::PLAYER2);
  board.setCase(7, 13, Gomoku::PLAYER1);

  board.setCase(11, 9, Gomoku::PLAYER2);
  board.setCase(12, 8, Gomoku::PLAYER2);
  board.setCase(13, 7, Gomoku::PLAYER1);

  board.setCase(11, 8, Gomoku::PLAYER2);

  board.setCase(0, 18, Gomoku::PLAYER1);
  board.setCase(1, 18, Gomoku::PLAYER2);
  board.setCase(2, 18, Gomoku::PLAYER2);

  board.dump();
  std::cout << "===================================" << std::endl;
  std::cout << "[10; 10] : " << referee.tryPlay(board, *player, history, 10, 10) << std::endl;
  std::cout << "[ 3; 18] : " << referee.tryPlay(board, *player, history, 3, 18) << std::endl;
  std::cout << "===================================" << std::endl;

  board.dump();
  std::cout << "Score : " << (int)player->getScore() << std::endl;

  delete player;
}

void test4()
{
  Gomoku::GomokuBoard	board;
  Gomoku::GomokuReferee referee;
  Gomoku::GomokuHistory history;
  Gomoku::Turn		turn = {1, 1, Gomoku::PLAYER1_TURN};
  Gomoku::GomokuPlayer	*player = new Gomoku::GomokuHuman(Gomoku::PLAYER1);

  // referee.setRules(Gomoku::BREAKABLE_FIVE);
  for (int i = 0; i < 9; ++i)
    history.push_back(turn);
  board.setCase(10, 10, Gomoku::PLAYER1);
  board.setCase(11, 9, Gomoku::PLAYER1);
  board.setCase(12, 8, Gomoku::PLAYER1);
  board.setCase(13, 7, Gomoku::PLAYER1);
  board.setCase(14, 6, Gomoku::PLAYER1);

  board.dump();
  std::cout << "===================================" << std::endl;
  std::cout << "victory : ";
  switch (referee.checkVictory(board, history, *player, *player))
    {
    case Gomoku::NO_WINNER :
      std::cout << "NO_WINNER"; break ;
    case Gomoku::PLAYER1_WIN :
      std::cout << "PLAYER1_WIN"; break ;
    case Gomoku::PLAYER2_WIN :
      std::cout << "PLAYER2_WIN"; break ;
    default :
      std::cout << "ERROR"; break ;
    }
  std::cout << std::endl;
  std::cout << "===================================" << std::endl;

  delete player;
}

int main()
{
  std::cout << std::boolalpha;

  test0();
  // std::cout << std::endl;

  // test1(); //play and update
  // std::cout << std::endl;

  // test2(); //double trois
  // std::cout << std::endl;

  // test3(); //prise de pierres
  // std::cout << std::endl;

  // test4(); //victoire + 5 cassables //todo

  return (0);
}
