#include "ALivingEntity.h"



ALivingEntity::ALivingEntity(unsigned int lifinette) : life(lifinette)
{

}

void			ALivingEntity::spawn(void)
{

}

void			ALivingEntity::tick(void)
{

} 

void			ALivingEntity::die(void)
{
	this->life = 0;
}

bool			ALivingEntity::collide(IHitbox &hitbox)const
{
	return (true);
}

Point	ALivingEntity::getCollidePos()const
{
	Point		ret;
	
	ret.x = 0;
	ret.y = 0;
	return (ret);
}



ALivingEntity::~ALivingEntity(void){}
