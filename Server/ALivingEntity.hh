//
// ALivingEntity.hh for rtype in /home/crocha_b//tech3/C++Advance/rtype/include/Server
//
// Made by benjamin crochard
// Login   <crocha_b@epitech.net>
//
// Started on  Tue Jul 23 12:07:26 2013 benjamin crochard
// Last update Tue Jul 23 12:07:27 2013 benjamin crochard
//

#ifndef ALIVINGENTITY_H_
#define ALIVINGENTITY_H_

#include "Point.h"
#include "IHitbox.h"

class				ALivingEntity
{
  unsigned int			life;
public:
  void				spawn();
  void				tick();
  void				die();
  bool				collide(IHitbox &hitbox)const;
  Point				getCollidePos()const;
  ALivingEntity(unsigned int);
  ~ALivingEntity(void);
};

#endif /* !ALIVINGENTITY_H_ */
