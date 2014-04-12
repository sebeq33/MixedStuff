//
// EntityManager.hh for rtype in /home/crocha_b//tech3/C++Advance/rtype/include/Server
//
// Made by benjamin crochard
// Login   <crocha_b@epitech.net>
//
// Started on  Tue Jul 23 12:07:56 2013 benjamin crochard
// Last update Tue Jul 23 12:10:33 2013 benjamin crochard
//

#ifndef		ENTITY_MANAGER_H_
# define	ENTITY_MANAGER_H_

#include <list>
#include <map>
#include <string>
#include "AEntity.hh"
#include "ILibrary.hh"

class EntityManager
{
public:
  EntityManager();
  ~EntityManager();
  bool					loadEntities(const std::string &, std::list<AEntity *> &);
  bool					unloadEntities(const std::string &);
  bool					unloadEntities(unsigned short);
  bool					setEntities(const std::string &, std::list<AEntity *> &);
  bool					setEntities(std::list<AEntity *> &);
  AEntity				*getEntities(const std::string &) const;

private:
  std::list<AEntity *>			entityList;
  std::map<unsigned short, std::string>
libraryList;
  unsigned short			lastEid;
  std::map<std::string, ILibrary *>	library;
};

#endif /* !ENTITY_MANAGER_H_ */
