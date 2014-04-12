#include "Weapon.h"

Weapon::Weapon(int dam) : damage(dam)
{}

void			Weapon::setDamage(int daminou)
{
	this->damage = daminou;
}

int				Weapon::getDamage() const
{
	return (this->damage);
}
 Weapon::~Weapon(void){}
