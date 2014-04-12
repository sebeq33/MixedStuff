#ifndef IHITBOX_H_
#define IHITBOX_H_

#include "Point.hh"

class						IHitbox
{
public:
  virtual bool					collide(IHitbox &hitbox)const  = 0;
  virtual Point					getCollidePos()const = 0;
  IHitbox(void);
  ~IHitbox(void);
};

#endif /* !IHITBOX_H_ */
