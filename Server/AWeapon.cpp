#include "AWeapon.h"



AWeapon::AWeapon(void){}

short int		AWeapon::getDamage() const
{
	return (this->damage);
}

void			AWeapon::use(Game &game, unsigned short nb)
{

}

AWeapon::~AWeapon(void){}
