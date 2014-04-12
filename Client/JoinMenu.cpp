#include "Convert.hpp"
#include "GameGui.hh"
#include "JoinMenu.hh"
#include "RType.hh"
#include <string.h>

JoinMenu::JoinMenu()
{
	if (!load(titleTexture, "Resources/Title.png"))
	  return ;
	titleSprite.setTexture(titleTexture);
	if (!font.loadFromFile("Resources/JLSSpaceGothicC_NC.otf"))
	 {
	    std::cerr << "Error while loading font" << std::cout;
	    return ;
	 }
}

JoinMenu::~JoinMenu()
{

}

bool JoinMenu::load(sf::Texture & texture, const std::string & filename)
{
	if (!texture.loadFromFile(filename.c_str()))
	{
		std::cerr << "Error while loading " << filename << std::endl;
		return (false);
	}
	return (true);
}

void JoinMenu::update(RType & r, sf::Event & e)
{
	((r.getGameWindow()).getWindow()).clear();

	titleSprite.setTexture(titleTexture);
	titleSprite.setTextureRect(sf::IntRect(0, 0, 581, 123));
	titleSprite.setPosition(159.5, 0);
	//((r.getGameWindow()).getWindow()).draw(titleSprite);
	Time res;
		Time u;
		u.updateTime();
		res = u - t;
		if (res.getSecond() > 1 || res.getMilli() > 100)
		{
			(r.getGameWindow()).getWindow().pollEvent(e);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				if (!str.empty())
				{
					str.erase(str.size() - 1);
					t = u;
				}
			}
			else if (e.type == sf::Event::TextEntered)
			{
				if (e.text.unicode > 47 && e.text.unicode < 58)
				{
					str += static_cast<char>(e.text.unicode);
					t = u;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					int numGame = Convert<int>::convert(str);
					std::cout << "n = " << numGame << std::endl;
					char buf[3];
					buf[0] = 5;
					memcpy(static_cast<void *> (buf + 1), static_cast<void const *> (&numGame), 2);
					r.getTCPSocket().send(buf, 3);
					GameGui		*game = new GameGui();
					r.pushGUI(game);
				}
			}

		}
}

void JoinMenu::textBox(RType & r)
{
	string.setFont(font);
	string.setString(str);
	string.setCharacterSize(30);
	string.setColor(sf::Color::Cyan);
	string.setPosition(375, 290);
	((r.getGameWindow()).getWindow()).draw(string);
}

void JoinMenu::display(RType & r)
{
	((r.getGameWindow()).getWindow()).draw(titleSprite);
	sf::Text text;
	text.setFont(font);
	text.setString("Please enter the ID number of the game you want to join");
	text.setCharacterSize(30);
	text.setColor(sf::Color::Cyan);
	text.setPosition(175, 250);
	((r.getGameWindow()).getWindow()).draw(text);
	textBox(r);
}
