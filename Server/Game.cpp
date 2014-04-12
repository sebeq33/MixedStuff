#include "Game.hh"

Game::Game(Client	*cli):
	status(WAITING_ROOM)
{
	players[0] = cli;
	for (int8_t i = 1; i < 4;++i)
		players[i] = NULL;
}

Game::~Game()
{
}

Game::GameState	Game::getStatus() const
{
	return (status);
}

void	Game::update(const Timer &timer, EntityManager &entityManager)
{
	(void) timer;
	(void) entityManager;
}

void	Game::addEntity(AEntity *entity)
{
	(void) entity;
}

bool	Game::addPlayer(Client *cli)
{
	for (int8_t i = 0; i < 4;++i)
	{
		if (players[i] == NULL)
		{
			players[i] = cli;
			return (true);
		}
	}
	return (false);
}

bool	Game::removePlayer(const Client *cli)
{
	for (int8_t i = 0; i < 4;++i)
	{
		if (players[i] == cli)
		{
			players[i] = NULL;
			return (true);
		}
	}
	return (false);
}

int8_t	Game::getNBPlayer() const
{
	int8_t	nbPlayer = 0;

	for (int8_t i = 0; i < 4;++i)
	{
		if (players[i] == NULL)
			return (nbPlayer);
		++nbPlayer;
	}
	return (nbPlayer);
}

int16_t	Game::getID() const
{
	return (id);
}

void  Game::setID(int16_t	value)
{
	id = value;
}
