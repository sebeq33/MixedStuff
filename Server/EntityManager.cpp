#include "EntityManager.hh"
#include "Library.hh"

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

bool	EntityManager::loadEntities(const std::string &libName, std::list<AEntity *> &list)
{
	ILibrary *lib = new Library();

	(void) list;
	if (lib->load(libName))
	{
		library[libName] = lib;
		/* TODO : call getSymbol() */
		//libraryList[eid] = libName;
		return (true);
	}
	else
		delete lib;
	return (false);
}

bool	EntityManager::unloadEntities(const std::string &libName)
{
	std::map<std::string, ILibrary *>::iterator it;

	it = library.find(libName);
	if (it != library.end())
	{
		library[libName]->unload();
		return (true);
	}
	return (false);
}

bool	EntityManager::unloadEntities(unsigned short eid)
{
	AEntity *entity = NULL;

	for (std::list<AEntity *>::iterator it = entityList.begin(); it != entityList.end() ;++it)
	{
		if ((entity = static_cast<AEntity *>(*it)) != NULL)
		{
			if (entity->getEID() == eid && libraryList.find(eid) != libraryList.end())
			{
				library[libraryList[eid]]->unload();
				return (true);
			}
		}
	}
	return (false);
}

bool	EntityManager::setEntities(const std::string &libName, std::list<AEntity *> &list)
{
	ILibrary *lib = NULL;

	(void) list;
	for (std::map<std::string, ILibrary *>::iterator it = library.begin(); it != library.end() ;++it)
	{
		if ((lib = static_cast<ILibrary *>(it->second)) != NULL
			&& lib->getName() == libName)
		{
			/* TODO */
			return (true);
		}
	}
	return (false);
}

bool	EntityManager::setEntities(std::list<AEntity *> &list)
{
	for (std::list<AEntity *>::iterator it = entityList.begin(); it != entityList.end() ;++it)
		list.push_back(static_cast<AEntity *>(*it));
	return (true);
}

AEntity	*EntityManager::getEntities(const std::string &name) const
{
	AEntity *entity = NULL;

	for (std::list<AEntity *>::const_iterator it = entityList.begin(); it != entityList.end() ;++it)
	{
		if ((entity = static_cast<AEntity *>(*it)) != NULL
			&& entity->getname() == name)
			return (entity);
	}
	return (NULL);
}

