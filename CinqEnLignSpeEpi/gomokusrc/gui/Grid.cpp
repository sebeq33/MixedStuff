#include <QPainter>
#include <QtGui>

#include "Grid.hh"
#include "GomokuGui.hh"
#include "GomokuHuman.hh"

Grid::Grid(int size, QWidget *parent)
  : QWidget(parent)
{
  TraySize = size;

  setMinimumSize(minimumSize());

  gomokuPlayer1 = new Gomoku::GomokuHuman(Gomoku::PLAYER1);
  gomokuPlayer2 = new Gomoku::GomokuHuman(Gomoku::PLAYER2);
  gomokuGame = new Gomoku::GomokuGame(Gomoku::TAKESTONE, gomokuPlayer1, gomokuPlayer2);
  gomokuGame->start();

  emit gameStateChanged(gomokuGame->getState(),
                        gomokuGame->getPlayer1()->getScore(),
                        gomokuGame->getPlayer2()->getScore());
}

Grid::~Grid()
{
  delete gridDrawer;
  delete gomokuGame;
}

void Grid::setRules(Gomoku::Rules rule, bool activ)
{
  if (activ)
    gomokuGame->setRules(rule);
  else
    gomokuGame->unsetRules(rule);
  emit gameStateChanged(gomokuGame->getState(),
                        gomokuGame->getPlayer1()->getScore(),
                        gomokuGame->getPlayer2()->getScore());
}

QSize Grid::minimumSize()
{
  return QSize(TraySize * 19, TraySize * 19);
}

Gomoku::Symbol Grid::at(QPoint pos)
{
  if(pos.x() < 0 || pos.x() >= TraySize || pos.y() < 0 || pos.y() >= TraySize)
    return (Gomoku::OUT);
  else
    return (gomokuGame->getBoard().getCase(pos.x(), pos.y()));
}

Gomoku::Symbol Grid::at(int x, int y)
{
  return at(QPoint(x, y));
}

void Grid::setDisplay(IDisplay *drawer)
{
  gridDrawer = drawer;
  gridDrawer->init();
}

void Grid::restart(Gomoku::Symbol s)
{
  gomokuGame->reset();
  gomokuGame->start(s);

  emit gameStateChanged(gomokuGame->getState(),
                        gomokuGame->getPlayer1()->getScore(),
                        gomokuGame->getPlayer2()->getScore());

  repaint();
}

void Grid::play(Gomoku::GameState state, QPoint pos)
{
  if(state == Gomoku::PLAYER1_TURN || state == Gomoku::PLAYER2_TURN)
    {
      if (!gomokuGame->play(pos.x(), pos.y()) && gomokuGame->getState() != Gomoku::DRAW)
        {
          emit gameStateChanged(Gomoku::ERROR,
                                gomokuGame->getPlayer1()->getScore(),
                                gomokuGame->getPlayer2()->getScore());
          return ;
        }

      emit gameStateChanged(gomokuGame->getState(),
                            gomokuGame->getPlayer1()->getScore(),
                            gomokuGame->getPlayer2()->getScore());

      repaint();
    }
}

void Grid::paintEvent(QPaintEvent *e)
{
  (void) e;
  if(gridDrawer)
    gridDrawer->drawGrid(this, gomokuGame->getBoard(), gomokuGame->getHistory());
}

void Grid::resizeEvent(QResizeEvent *rEvent)
{
  if(rEvent->size().width() < rEvent->size().height())
    resize(QSize(rEvent->size().width(), rEvent->size().width()));
  else
    resize(QSize(rEvent->size().height(), rEvent->size().height()));

  rEvent->accept();
}

void Grid::mouseReleaseEvent(QMouseEvent *mEvent)
{
  if(mEvent->button() != Qt::LeftButton ||
     gomokuGame->getState() == Gomoku::NOT_STARTED ||
     gomokuGame->getState() == Gomoku::PLAYER1_WIN ||
     gomokuGame->getState() == Gomoku::PLAYER2_WIN ||
     gomokuGame->getState() == Gomoku::DRAW ||
     gomokuGame->getState() == Gomoku::ERROR)
    return;

  play(gomokuGame->getState(), gridDrawer->at(mEvent->pos(), this->size(), TraySize));

  mEvent->accept();
}

Gomoku::PlayerType Grid::getTypePlayer(Gomoku::Symbol p) const
{
  return (gomokuGame->getTypePlayer(p));
}
