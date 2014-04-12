#ifndef STARTMENU_HH
#define STARTMENU_HH

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IGUI.hh"
#include "Time.hh"

class RType;

class StartMenu : public IGUI
{
private:
	bool createAvailable;
	bool joinAvailable;
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Font font;
	Time t;
	bool load(sf::Texture &, const std::string &);
	bool isOnCreateButton(RType & r);
	bool isOnJoinButton(RType & r);
	bool isOnQuitButton(RType & r);
public:
	StartMenu();
	~StartMenu();
	void update(RType &, sf::Event &e);
	void display(RType &);
	void createGame(RType &);
	void joinGame(RType &);
	void quit(RType &);
};

#endif		/*! STARTMENU_HH */
