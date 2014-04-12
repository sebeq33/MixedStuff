#include "PowerUp.h"


PowerUp::PowerUp(void){}

void					PowerUp::spawn()
{

}

void					PowerUp::tick()
{

}

void					PowerUp::die()
{

}

bool					PowerUp::collide(IHitbox &hitbox) const
{
	return (true);
}

Point					PowerUp::getCollidePos() const
{
	Point				ret;

	ret.x = 0;
	ret.y = 0;

	return (ret);
}



PowerUp::~PowerUp(void){}
