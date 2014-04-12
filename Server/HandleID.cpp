#include "HandleID.hh"

HandleID::HandleID()
{
}

HandleID::~HandleID()
{
}

void	HandleID::removeId(int16_t id)
{
	IDList.erase(id);
}

int16_t HandleID::getNewId(ClassName name)
{
	int16_t	lastID = 0;

	for (std::map<int16_t, ClassName>::iterator it = IDList.begin(); it != IDList.end();++it)
	{
		if (it->second == name)
		{
			if (lastID < it->first)
			{
				IDList[lastID] = name;
				return (lastID);
			}
			++lastID;
		}
	}
	IDList[lastID] = name;
	return (lastID);
}
