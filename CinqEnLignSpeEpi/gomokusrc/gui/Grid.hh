#ifndef GRID_HH_
#define GRID_HH_

#include <QWidget>

#include "GomokuGame.hh"

class IDisplay;

class Grid : public QWidget
{
  Q_OBJECT
  public:
  Grid(int s1, QWidget *parent = 0);
  ~Grid();

  QSize         minimumSize();

  Gomoku::Symbol                at(QPoint pos);
  Gomoku::Symbol                at(int x, int y);

  void          setDisplay(IDisplay *drawer);
  void		setRules(Gomoku::Rules rule, bool activ);
  Gomoku::PlayerType getTypePlayer(Gomoku::Symbol) const;

public slots:
  void          restart(Gomoku::Symbol s = Gomoku::EMPTY);
  void          play(Gomoku::GameState, QPoint pos);

protected :
  void          paintEvent(QPaintEvent *e);
  void          resizeEvent(QResizeEvent *rEvent);
  void          mouseReleaseEvent(QMouseEvent *mEvent);

signals:
  void          gameStateChanged(Gomoku::GameState, uint8_t, uint8_t);

private:
  int                   TraySize;

  IDisplay		*gridDrawer;

  Gomoku::GomokuGame	*gomokuGame;

  Gomoku::GomokuPlayer	*gomokuPlayer1;
  Gomoku::GomokuPlayer	*gomokuPlayer2;
};

#endif
