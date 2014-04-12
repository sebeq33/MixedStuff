#include "Entity.hh"

Entity::Entity()
	:name(NULL), EID(0), id(0), x(0), y(0), dirX(0), dirY(0), speed(0, 0)
{

}

Entity::~Entity()
{

}

const std::string & Entity::getName() const
{
	return (name);
}

unsigned short Entity::getEID() const
{
	return (EID);
}

unsigned short Entity::getID() const
{
	return (id);
}

void Entity::update()
{

}

Entity Entity::clone(unsigned short id)
{
	return (*this);
}

unsigned short Entity::getX() const
{
	return (x);
}

unsigned short Entity::getY() const
{
	return (y);
}

short Entity::getDirX() const
{
	return (dirX);
}

short Entity::getDirY() const
{
	return (dirY);
}

const Time & Entity::getSpeed() const
{
	return (speed);
}

void Entity::setX(unsigned short newX)
{
	x = newX;
}

void Entity::setY(unsigned short newY)
{
	y = newY;
}

void Entity::setDirX(short newDirX)
{
	dirX = newDirX;
}	

void Entity::setDirY(short newDirY)
{
	dirY = newDirY;
}

void Entity::setSpeed(const Time & newSpeed)
{
	speed = newSpeed;
}
