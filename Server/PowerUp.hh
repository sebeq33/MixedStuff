#ifndef POWERUP_H_
#define POWERUP_H_

#include "Point.hh"
#include "IHitbox.hh"

class		PowerUp
{
public:
  void		spawn();
  void		tick();
  void		die();
  bool		collide(IHitbox &hitbox)const;
  Point		getCollidePos()const;
  PowerUp(void);
  ~PowerUp(void);
};

#endif /* !POWERUP */
