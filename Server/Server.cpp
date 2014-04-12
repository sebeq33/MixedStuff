#include "Server.hh"
#include "TCPSocket.hh"

bool Server::_sigcatch = false;

#ifdef WIN32
BOOL WINAPI sighandler(DWORD signum)
{
  (void) signum;
  Server::_sigcatch = true;
  return (true);
}
#else
void		sighandler(int32_t signum)
{
  (void) signum;
  Server::_sigcatch = true;
}
#endif

Server::Server()
{
}

Server::~Server()
{
}

void	Server::start(short	port)
{
	int32_t	ret;

	#ifdef WIN32
		SetConsoleCtrlHandler(sighandler, true);
	#else
		signal(SIGINT, &sighandler);
	#endif
	socket.init(port);
	while (!Server::_sigcatch)
	{
		std::cout << "Select" << std::endl;
		prepareClient();
		ret = socket.selectTimeOut(5);
		checkNewClient();
		checkClientData(ret);
		socket.clearSet();
	}
}

void	Server::checkNewClient()
{
	if (socket.hasPendingConnection())
	{
		TCPSocket	*sock = socket.accept();
		Client		*cli = new Client(sock->getFD());
		if (cli == NULL)
				return ;
		cli->setID(handleID.getNewId(HandleID::CLIENT));
		clientList.push_back(cli);
		std::cout << "New client : " << cli->getID() << std::endl;
	}
}

void	Server::checkClientData(int32_t	ret_select)
{
	Client	*cli = NULL;

	for (std::list<Client *>::iterator it = clientList.begin();
		it != clientList.end() && ret_select > 0;
		++it)
	{
		cli = static_cast<Client *>(*it);
		if (checkReadableClient(cli->getTCPSocket(), cli, it))
			ret_select--;
	}
}

bool	Server::checkReadableClient(const TCPSocket &sock,
				    Client *cli,
				    std::list<Client *>::iterator it)
{
	char		buf[4096];

	if (socket.readable(sock))
	{
		int32_t len = sock.recv(buf, 4096);
		if (len == 0)
		{
			std::cout << "TCP Client disconnected" << std::endl;
			checkClientGame(cli);
			cli->closeSocket();
			delete cli;
			it = clientList.erase(it);
		}
		else
		{
			buf[len] = '\0';
			len = p.executeRequest(this, cli, buf);
		}
		return (true);
	}
	return (false);
}

void	Server::prepareClient()
{
  Client	*cli;

  for (std::list<Client *>::iterator it = clientList.begin(); it != clientList.end() ;++it)
    {
      cli = static_cast<Client *>(*it);
      socket.prepareRead(cli->getTCPSocket());
    }
  socket.prepareRead(socket);
}

void	Server::checkClientGame(const Client *cli)
{
	Game	*game = NULL;

	for (std::list<Game *>::iterator it = gameList.begin(); it != gameList.end() ;++it)
	{
		game = static_cast<Game *>(*it);
		if (game->getID() == cli->getGameID()
			&& game->getNBPlayer() <= 1)
		{
			handleID.removeId(game->getID());
			delete game;
			it = gameList.erase(it);
			handleID.removeId(cli->getID());
			return ;
		}
	}
}

unsigned int	Server::createNewGame(Client *cli)
{
  Game	*game = new Game(cli);
  if (game == NULL)
    return (-1);
  game->setID(handleID.getNewId(HandleID::GAME));
  cli->setGameID(game->getID());
  gameList.push_back(game);
  std::cout << "New game id : " << game->getID() << std::endl;
  return (game->getID());
}

Game  *Server::getGameID(int16_t id)
{
	Game	*game = NULL;

	for (std::list<Game *>::iterator it = gameList.begin(); it != gameList.end() ;++it)
	{
		game = static_cast<Game *>(*it);
		if (game->getID() == id)
			return (game);
	}
	return (NULL);
}

void	Server::stop()
{
	Client	*cli = NULL;

	for (std::list<Game *>::iterator it = gameList.begin(); it != gameList.end() ;++it)
		delete *it;
	for (std::list<Client *>::iterator it = clientList.begin(); it != clientList.end() ;++it)
	{
		cli = static_cast<Client *>(*it);
		cli->closeSocket();
		delete cli;
	}
}
