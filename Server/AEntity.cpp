#include "AEntity.hh"

AEntity::AEntity(unsigned short posx, unsigned short posy, short dirx, short diry,
				std::string &naminou, unsigned short id, unsigned short eid, AEntity::EntityType typinou)
				: posX(posx), posY(posy), dirX(dirx), dirY(diry), name(naminou), Id(id), EId(eid), type(typinou)
{
	this->died = true;
}

bool			AEntity::isDead() const
{
	return (this->died);
}

unsigned short	AEntity::getPosX() const
{
	return (this->posX);
}

unsigned short	AEntity::getPosY() const
{
	return (this->posY);
}

short			AEntity::getDirX() const
{
	return (this->dirX);
}

short			AEntity::getDirY() const
{
	return (this->dirY);
}

unsigned short	AEntity::getID() const
{
	return (this->Id);
}

unsigned short	AEntity::getEID() const
{
	return (this->EId);
}

AEntity::EntityType	AEntity::getType() const
{
	return (this->type);
}

std::string		&AEntity::getname() const
{
	return (this->name);
}

AEntity::~AEntity(void){}
