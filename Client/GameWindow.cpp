#include "GameWindow.hh"
#include <iostream>

GameWindow::GameWindow()
{
}

GameWindow::~GameWindow()
{

}

void GameWindow::start()
{
  window.create(sf::VideoMode(900, 540), "R-Type");
  window.setKeyRepeatEnabled(false);
}

void GameWindow::cleanWindow()
{
	window.clear();
}

bool GameWindow::isButtonPressed(KeyInfo in) const
{
	switch (in)
	{
		case LEFTCLICK:
			return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
		case DOWN:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::S));
		case UP:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
		case LEFT:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
		case RIGHT:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::D));
		case SHOOT:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
		case SHIELD:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::RShift));
		case FLASH:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::RControl));
		case QUIT:
			return (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	}
}

sf::RenderWindow & GameWindow::getWindow()
{
	return (window);
}

Mouse & GameWindow::getMouse()
{
	return (mouse);
}
