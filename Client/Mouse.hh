#ifndef MOUSE_HH
#define MOUSE_HH

#include <SFML/Window.hpp>
#include "Point.hh"

class Mouse
{
private:
	bool isClicked;
	Point pos;
public:
	Mouse();
	~Mouse();
	bool isItClicked() const;
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

#endif /* !MOUSE_HH */