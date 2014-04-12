//
// AWeapon.hh for rtype in /home/crocha_b//tech3/C++Advance/rtype/include/Server
//
// Made by benjamin crochard
// Login   <crocha_b@epitech.net>
//
// Started on  Tue Jul 23 12:07:34 2013 benjamin crochard
// Last update Tue Jul 23 12:07:35 2013 benjamin crochard
//

#ifndef AWEAPON_H_
#define AWEAPON_H_

class Game;

class		AWeapon
{
  short int	damage;
public:
  short int	getDamage() const;
  void		use(Game &, unsigned short);
  AWeapon(void);
  ~AWeapon(void);
};

#endif /* !AWEAPON_H_ */
