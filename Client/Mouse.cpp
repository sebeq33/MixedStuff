#include "Mouse.hh"

Mouse::Mouse()
{
	isClicked = false;
}

Mouse::~Mouse()
{

}

bool Mouse::isItClicked() const
{
	return (isClicked);
}

int Mouse::getX() const
{
	return (pos.x);
}

int Mouse::getY() const
{
	return (pos.y);
}
