#include "Client.hh"

Client::Client():
	ready(false)
{
}

Client::Client(int16_t fd):
	ready(false),
	socketTCP(fd)
{
}

Client::~Client()
{
}

bool	Client::isConnected() const
{
	return (socketTCP.isConnected());
}

const TCPSocket  &Client::getTCPSocket() const
{
	return (socketTCP);
}

const UDPSocket  &Client::getUDPSocket() const
{
	return (socketUDP);
}

Player	&Client::getPlayer()
{
	return (this->player);
}

bool	Client::isReady() const
{
	return (this->ready);
}

int16_t  Client::getID() const
{
	return (clientID);
}

int16_t  Client::getGameID() const
{
	return (clientID);
}

void  Client::setID(int16_t value)
{
	clientID = value;
}

void  Client::setGameID(int16_t value)
{
	gameID = value;
}

void  Client::closeSocket()
{
	socketTCP.tryClose();
	socketUDP.tryClose();
}
