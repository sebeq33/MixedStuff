//
// Event.hh for rtype in /home/crocha_b//tech3/C++Advance/rtype/include/Server
//
// Made by benjamin crochard
// Login   <crocha_b@epitech.net>
//
// Started on  Tue Jul 23 12:10:52 2013 benjamin crochard
// Last update Tue Jul 23 12:11:06 2013 benjamin crochard
//

#ifndef EVENT_H_
#define EVENT_H_

class			Event
{
public:
  void			spawn();
  void			tick();
  void			die();
  Event(void);
  ~Event(void);
};

#endif /* !EVENT_H_ */
