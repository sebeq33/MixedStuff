#ifndef MONSTERS_H_
#define MONSTERS_H_

#include "AWeapon.hh"

class			Monsters
{
  AWeapon		*weapon;
  bool			shield;
public:
  void			setWeapon(AWeapon *);
  Monsters(void);
  ~Monsters(void);
};

#endif /* !MONSTERS_H_ */
