#ifndef GAMEGUI_HH
#define GAMEGUI_HH

#include <SFML/Graphics.hpp>
#include <list>
#include "IGUI.hh"
#include "Entity.hh"
#include "Picture.hh"
#include "Timer.hh"

class GameGui : public IGUI
{
private:
	std::list<Picture *> lstBullets;
	Picture			starship;
	Picture			background1;
	Picture			background2;
	float			x;
	float			y;
	Timer timer;
	int numPlayer;
	sf::Texture textureTab[42];
	//ISocket udpSocket;
	std::list<Entity> entityList;
public:
	GameGui();
	~GameGui();
	void update(RType &, sf::Event & e);
	void display(RType &);
	int getNumPlayer() const;
	//ISocket * getUDPSocket() = 0 const;
};

#endif /* !GAMEGUI_HH */