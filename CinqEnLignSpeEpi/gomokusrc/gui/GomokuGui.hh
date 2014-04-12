#ifndef DISPLAY_HH_
#define DISPLAY_HH_

#include "IDisplay.hh"
#include "Grid.hh"
#include "GomokuBoard.hh"

class GomokuGui : public QObject, public IDisplay
{
  Q_OBJECT
  public:
  void          init();
  QPoint                at(const QPoint &pos,
                           const QSize &size,
                           int traySize) const;

  void          drawGrid(QPaintDevice *device,
                         const Gomoku::GomokuBoard &gomokuBoard,
                         Gomoku::GomokuHistory const &history);
  void        drawPlate(QPainter &p,
                        QRect &tray,
                        int traySize);
  void        placeSymbol(QPainter &p,
                          QRect &tray,
                          int traySize,
                          const Gomoku::GomokuBoard &gomokuBoard);
  void        lastMove(QPainter &p,
                       QRect &tray,
                       int traySize,
                       Gomoku::GomokuHistory const &history);
  void        drawHeaders(QPainter &p,
                          QRect &tray,
                          int traySize,
                          QPaintDevice *device,
                          int headerHeight,
                          int headerWidth);

private:
  QColor                dot;

  QFont                 headerFont;
  QColor                headerColor;

  QColor                trayColor;

  QPixmap               Symbol1;
  QPixmap               Symbol2;

  QPixmap               goban;
};

#endif
