#ifndef IDISPLAY_HH_
#define IDISPLAY_HH_

#include "Grid.hh"
#include "GomokuBoard.hh"

class IDisplay
{
public:
	virtual ~IDisplay() {}

	virtual void init() = 0;

	virtual void drawGrid(QPaintDevice *device,
		const Gomoku::GomokuBoard &gomokuBoard,
		Gomoku::GomokuHistory const &history) = 0;

	virtual QPoint at(const QPoint & pos,
		const QSize & size,
		int traySize) const = 0;
};

#endif
