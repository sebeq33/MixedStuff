#include "Convert.hpp"
#include "StartMenu.hh"
#include "JoinMenu.hh"
#include "GameGui.hh"
#include "RType.hh"

StartMenu::StartMenu()
{
	if (!load(titleTexture, "Resources/Menu.png"))
	{
		std::cerr << "Error while loading texture" << std::cout;
		return ;
	}
	titleSprite.setTexture(titleTexture);
	createAvailable = true;
	joinAvailable = true;
	if (!font.loadFromFile("Resources/JLSSpaceGothicC_NC.otf"))
	 {
	    std::cerr << "Error while loading font" << std::cout;
	    return ;
	 }
}

StartMenu::~StartMenu()
{


}

bool StartMenu::load(sf::Texture & texture, const std::string & filename)
{
	if (!texture.loadFromFile(filename.c_str()))
	{
		std::cerr << "Error while loading " << filename << std::endl;
		return (false);
	}
	return (true);
}

bool StartMenu::isOnCreateButton(RType & r)
{
	sf::Vector2i pos = sf::Mouse::getPosition((r.getGameWindow()).getWindow());
	if ((pos.x >= 207 && pos.x <= 339) && (pos.y >= 300 && pos.y <= 428))
		return (true);
	return (false);
}

bool StartMenu::isOnJoinButton(RType & r)
{
	sf::Vector2i pos = sf::Mouse::getPosition((r.getGameWindow()).getWindow());
	if ((pos.x >= 455 && pos.x <= 675) && (pos.y >= 305 && pos.y <= 340))
		return (true);
	return (false);
}

bool StartMenu::isOnQuitButton(RType & r)
{
	sf::Vector2i pos = sf::Mouse::getPosition((r.getGameWindow()).getWindow());
	if ((pos.x >= 455 && pos.x <= 675) && (pos.y >= 377 && pos.y <= 407))
		return (true);
	return (false);
}

void  StartMenu::update(RType & r, sf::Event & e)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (isOnCreateButton(r) && createAvailable == true)
		{
			createAvailable = false;
			createGame(r);
		}
		else if (isOnJoinButton(r) && joinAvailable == true)
		{
			joinAvailable = false;
			t.updateTime();
			joinGame(r);
		}
		else if (isOnQuitButton(r))
			quit(r);
	}
}

void  StartMenu::display(RType & r)
{
	((r.getGameWindow()).getWindow()).draw(titleSprite);
}

void StartMenu::createGame(RType &r)
{
	char buf[1];

	buf[0] = 2;
	r.getTCPSocket().send(buf, 1);
	GameGui		*game = new GameGui();
	r.pushGUI(game);
	std::cout << "launch new game" << std::endl;
}

void StartMenu::joinGame(RType & r)
{
	JoinMenu	*join = new JoinMenu();
	r.pushGUI(join);

	std::cout << "Joined new game" << std::endl;
}

void StartMenu::quit(RType & r)
{
	((r.getGameWindow()).getWindow()).close();
}
