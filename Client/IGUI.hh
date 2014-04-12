#ifndef  IGUI_HH
#define IGUI_HH

#include <SFML/Graphics.hpp>

class RType;

class IGUI
{
public:
	virtual void update(RType &, sf::Event & e) = 0;
	virtual void display(RType &) = 0;
};

#endif 		/* !IGUI_HH */