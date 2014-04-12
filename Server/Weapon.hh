#ifndef WEAPON_H_
#define WEAPON_H_

class		Weapon
{
  int		damage;
public:
  void		setDamage(int);
  int		getDamage();
  Weapon(int);
  ~Weapon(void);
};

#endif /* !WEAPON_H_ */
