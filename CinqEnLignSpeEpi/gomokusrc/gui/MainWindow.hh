#ifndef MAINWINDOW_HH_
#define MAINWINDOW_HH_
#include <QtGui>
#include <QMainWindow>
#include "Grid.hh"

class MainWindow : public QMainWindow
{
  Q_OBJECT
  public:
  MainWindow();
  ~MainWindow();

protected:
  void		closeEvent(QCloseEvent *cEvent);

private slots:
  void		newGame();
  void		applyGameState(Gomoku::GameState, uint8_t, uint8_t);
  void		applyPlayMode();
  void		applyDoubleThree();
  void		applyBreakableFive();
  void		applyTakeStone();

  private:

  QHBoxLayout		*windowLayout;

  Grid			*grid;

  IDisplay		*gridDrawer;

  QMenu                 *gameMenu;
  QWidget		*centralWidget;

  QAction		*newGameAction;
  QAction		*quitAction;

  QMenu			*optionMenu;

  QMenu			*player1Menu;
  QAction		*player1HumanAction;
  QAction		*player1AIAction;

  QMenu			*player2Menu;
  QAction		*player2HumanAction;
  QAction		*player2AIAction;

  QLabel		*statusBarLabel;
  QLabel		*scorePlayer1;
  QLabel		*scorePlayer2;

  QMenu			*rulesMenu;
  QAction		*doubleThree;
  QAction		*breakableFive;
  QAction		*takeStone;

  void			createMenu();
  void			setFirstPlayer();
  void			setSecondPlayer();
  void			setRulesOptions();

  //unused
  MainWindow(const MainWindow &other);
  MainWindow &operator=(const MainWindow &other);
};

#endif
