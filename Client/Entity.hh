#ifndef ENTITY_HH
#define ENTITY_HH

#include <iostream>
#include "Time.hh"
#include <SFML/Graphics.hpp>

class Entity
{
private:
	const std::string name;
	const unsigned short EID;
	const unsigned short id;
	unsigned short x;
	unsigned short y;
	short dirX;
	short dirY;
	Time speed;
	sf::Texture *texture;
public:
	Entity();
	~Entity();
	const std::string & getName() const;
	unsigned short getEID() const;
	unsigned short getID() const;
	void update();
	Entity clone(unsigned short id);
	unsigned short getX() const;
	unsigned short getY() const;
	short getDirX() const;
	short getDirY() const;
	const Time & getSpeed() const;
	void setX(unsigned short);
	void setY(unsigned short);
	void setDirX(short);
	void setDirY(short);
	void setSpeed(const Time &);
};

#endif /* !ENTITY_HH */