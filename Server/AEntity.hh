//
// AEntity.hh for rtype in /home/crocha_b//tech3/C++Advance/rtype/include/Server
//
// Made by benjamin crochard
// Login   <crocha_b@epitech.net>
//
// Started on  Tue Jul 23 12:07:17 2013 benjamin crochard
// Last update Tue Jul 23 12:07:19 2013 benjamin crochard
//

#ifndef AENTITY_H_
#define AENTITY_H_

#include <string>
#include <iostream>

class AEntity
{
public :
  enum				EntityType
    {
      Bullet,
      Monsters,
      Obstacles,
      Player,
      PowerUp,
      Event
    };
private :
  unsigned short		posX;
  unsigned short		posY;
  short				dirX;
  short				dirY;
  std::string			&name;
  bool				died;
  unsigned short		Id;
  unsigned short		EId;
  AEntity::EntityType			type;

public:
  virtual void			spawn() = 0;
  virtual void			tick() = 0;
  virtual void			die() = 0;
  bool				isDead() const;
  unsigned short		getPosX()const;
  unsigned short		getPosY()const;
  short				getDirX()const;
  short				getDirY()const;
  unsigned short		getID()const;
  unsigned short		getEID()const;
  AEntity::EntityType		getType()const;
  std::string			&getname()const;
  AEntity(unsigned short, unsigned short, short, short, std::string &, unsigned short, unsigned short, AEntity::EntityType);
  ~AEntity(void);
};

#endif /* !AENTITY_H_ */
