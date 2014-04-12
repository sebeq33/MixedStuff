//
// Bullet.hh for rtype in /home/crocha_b//tech3/C++Advance/rtype/include/Server
//
// Made by benjamin crochard
// Login   <crocha_b@epitech.net>
//
// Started on  Tue Jul 23 12:07:40 2013 benjamin crochard
// Last update Tue Jul 23 12:07:42 2013 benjamin crochard
//

#ifndef BULLET_H
#define BULLET_H_

class Bullet
{
	unsigned int		sourdeID;
public:
	unsigned int		getSourceID()const;
	Bullet(void);
	~Bullet(void);
};

#endif /* !BULLET_H_ */
