#include <QtGui>
#include <QDebug>

#include "Grid.hh"
#include "GomokuGui.hh"
#include "GomokuEnum.hh"

void GomokuGui::init()
{
  headerFont = QApplication::font();
  headerColor = QColor(Qt::black);

  trayColor = QColor(Qt::black);

  Symbol1 = QPixmap(QString("Images/noir.xpm"));
  Symbol2 = QPixmap(QString("Images/blanc.xpm"));
  goban = QPixmap(QString("Images/test.xpm"));

  dot = QColor(Qt::red);
}

QPoint GomokuGui::at(const QPoint &pos, const QSize &size, int traySize) const
{
  int headerWidth = 0, headerHeight = 20;

  QFontMetrics fm(headerFont);

  headerWidth = fm.maxWidth() + 10;
  headerHeight = fm.height() + 10;
  if (headerWidth > headerHeight)
    headerHeight = headerWidth;
  else
    headerWidth= headerHeight;

  QRect tray(headerWidth,
             headerHeight,
             size.width() - 2 * headerWidth,
             size.height() - 2 * headerHeight);

  if (!tray.contains(pos))
    return QPoint(-1, -1);
  else
    {
      QPoint newPos = QPoint(pos.x() - tray.left(), pos.y() - tray.top());

      return QPoint(newPos.x() * traySize / tray.size().width(),
                    newPos.y() * traySize / tray.size().height());
    }

  return QPoint(0, 0);
}

void GomokuGui::drawPlate(QPainter &p, QRect &tray, int traySize)
{
  p.setPen(trayColor);

  for (int i = 0; i < traySize; ++i)
    {
      p.drawLine(tray.left(),
                 i * tray.height() / traySize + tray.top() + tray.height() / (2 * traySize),
                 tray.right(),
                 i * tray.height() / traySize + tray.top() + tray.height() / (2 * traySize));
      p.drawLine(i * tray.width() / traySize + tray.left() + tray.width() / (2 * traySize),
                 tray.top(),
                 i * tray.width() / traySize + tray.left() + tray.width() / (2 * traySize),
                 tray.bottom());
    }
}

void GomokuGui::placeSymbol(QPainter &p, QRect &tray, int traySize, const Gomoku::GomokuBoard &gomokuBoard)
{
  for (int i = 0; i < 19; ++i)
    for (int j = 0; j < 19; ++j)
      {
        if (gomokuBoard.getCase(j, i) == Gomoku::PLAYER1)
          {
            p.drawPixmap(QRect(j * tray.width() / traySize + tray.left() + 2,
                               i * tray.height() / traySize + tray.top() + 2,
                               tray.width() / traySize - 2,
                               tray.height() / traySize - 2),
                         Symbol1);
          }
        else if (gomokuBoard.getCase(j, i) == Gomoku::PLAYER2)
          {
            p.drawPixmap(QRect(j * tray.width() / traySize + tray.left() + 2,
                               i * tray.height() / traySize + tray.top() + 2,
                               tray.width() / traySize - 2,
                               tray.height() / traySize - 2),
                         Symbol2);
          }
      }
}

void    GomokuGui::lastMove(QPainter &p, QRect &tray,
                            int traySize, Gomoku::GomokuHistory const &history)
{
  if (history.empty())
    return ;
  Gomoku::Turn turn = history.back();
  int x = 0, y = 0;


  if (turn.state == Gomoku::PLAYER1_TURN || turn.state == Gomoku::PLAYER2_TURN)
    {
      p.setPen(dot);
      p.setBrush(dot);
      x = turn.x;
      y = turn.y;

      int sizex = (tray.width() / traySize) / 5;
      int sizey = (tray.height() / traySize) / 5;
      p.drawRect(x * tray.height() / traySize + tray.top() + tray.height() / (2 * traySize) - sizex / 2,
                 y * tray.height() / traySize + tray.top() + tray.height() / (2 * traySize) - sizey / 2,
                 sizex,
                 sizey);
    }

  if (history.size() >= 2)
    {
      Gomoku::GomokuHistory::const_iterator it = history.begin();
      std::advance(it, history.size() - 2);
      turn = *it;
      if (turn.state == Gomoku::PLAYER1_TURN || turn.state == Gomoku::PLAYER2_TURN)
        {
          x = turn.x;
          y = turn.y;

          int sizex = (tray.width() / traySize) / 8;
          int sizey = (tray.height() / traySize) / 8;
          p.drawRect(x * tray.height() / traySize + tray.top() + tray.height() / (2 * traySize) - sizex / 2,
                     y * tray.height() / traySize + tray.top() + tray.height() / (2 * traySize) - sizey / 2,
                     sizex,
                     sizey);


        }
    }
}

void GomokuGui::drawHeaders(QPainter &p, QRect &tray, int traySize,
                            QPaintDevice *device, int headerHeight, int headerWidth)
{
  p.setPen(headerColor);
  if (headerColor == QColor(Qt::transparent))
    p.setPen(QColor(Qt::black));

  p.setFont(headerFont);

  for (int i = 0; i < traySize; ++i)
    {
      p.drawText(i * tray.width() / traySize + tray.left(),
                 5,
                 tray.width() / traySize,
                 headerHeight - 10,
                 Qt::AlignVCenter | Qt::AlignHCenter,
                 QString(QChar('A' + i)));
      p.drawText(i * tray.width() / traySize + tray.left(),
                 device->height() - headerHeight + 5,
                 tray.width() / traySize,
                 headerHeight - 10,
                 Qt::AlignVCenter | Qt::AlignHCenter,
                 QString(QChar('A' + i)));
      p.drawText(5,
                 i * tray.height() / traySize + tray.top(),
                 headerWidth - 10,
                 tray.height()/traySize,
                 Qt::AlignVCenter | Qt::AlignHCenter,
                 QString("%1").arg(i + 1));
      p.drawText(device->width() - headerWidth + 5,
                 i * tray.height() / traySize + tray.top(),
                 headerWidth - 10,
                 tray.height() / traySize,
                 Qt::AlignVCenter | Qt::AlignHCenter,
                 QString("%1").arg(i + 1));
    }
}

void GomokuGui::drawGrid(QPaintDevice *device,
			 const Gomoku::GomokuBoard &gomokuBoard,
			 Gomoku::GomokuHistory const &history)
{
  QPainter p(device);
  int headerWidth = 0, headerHeight = 0;

  QFontMetrics fm(headerFont);

  headerWidth = fm.maxWidth() + 10;
  headerHeight = fm.height() + 10;
  if (headerWidth > headerHeight)
    headerHeight = headerWidth;
  else
    headerWidth = headerHeight;

  QRect tray(headerWidth,
             headerHeight,
             device->width() - 2 * headerWidth - 1,
             device->height() - 2 * headerHeight - 1);
  int traySize = 19;

  p.drawPixmap(QRect(0, 0, device->width(), device->height()), goban);
  drawPlate(p, tray, traySize);
  placeSymbol(p, tray, traySize, gomokuBoard);
  lastMove(p, tray, traySize, history);
  drawHeaders(p, tray, traySize, device, headerHeight, headerWidth);
}
