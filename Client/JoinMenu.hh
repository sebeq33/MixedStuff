#ifndef JOINMENU_HH
#define JOINMENU_HH

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IGUI.hh"
#include "Time.hh"

class RType;

class JoinMenu : public IGUI
{
private:
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	sf::Font font;
	sf::Text string;
	std::string str;
	Time t;
	bool load(sf::Texture &, const std::string &);
public:
	JoinMenu();
	~JoinMenu();
	void update(RType &, sf::Event &);
	void display(RType &);
	void textBox(RType &);
};

#endif		/*! JOINMENU_HH */