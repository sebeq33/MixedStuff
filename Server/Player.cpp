#include "Player.hh"


Player::Player(void){}

bool	Player::fire() const
{
	return (true);
}

void	Player::setShield(bool val)
{
	this->shield = val;
}

void	Player::setFlash(bool val)
{
	this->nuclearFlash = val;
}

void	Player::setWeapon(AWeapon *weap)
{
	this->weapon = weap;
}

unsigned int	Player::getScore() const
{
	return (this->score);
}

void	Player::addScore(unsigned int value) const
{
	(void) value;
}

Player::~Player(void){}
