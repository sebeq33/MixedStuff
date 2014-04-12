#ifndef RTYPE_HH
#define RTYPE_HH

#include <list>
#include <fstream>
#include "Entity.hh"
#include "IGUI.hh"
#include "Timer.hh"
#include "TCPSocket.hh"
#include "UDPSocket.hh"

#include "GameWindow.hh"

class RType
{
private:
	std::list<IGUI *> guiList;
	IGUI * currentGui;
	GameWindow gameWindow;
	std::list<Entity> entitySingleton;
	TCPSocket socketTCP;
	UDPSocket socketUDP;
	bool loadConfig();
public:
	RType();
	~RType();
	void startLoop();
	GameWindow & getGameWindow();
	void pushGUI(IGUI *);
	void popGUI(IGUI *);
	const TCPSocket  &getTCPSocket() const;
	const UDPSocket  &getUDPSocket() const;
};

#endif /* !RTYPE_HH */
