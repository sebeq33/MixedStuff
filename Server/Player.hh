#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdint.h>
#include "AWeapon.hh"

class				Player
{
  uint8_t			nbRespawn;
  AWeapon			*weapon;
  bool				shield;
  bool				nuclearFlash;
  unsigned int			score;
public:
  bool				fire() const;
  void				setShield(bool);
  void				setFlash(bool);
  void				setWeapon(AWeapon *);
  unsigned int			getScore()const;
  void				addScore(unsigned int)const;
  Player(void);
  ~Player(void);
};

#endif /* !PLAYER_H_ */
