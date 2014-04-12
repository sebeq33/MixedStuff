#include "Protocol.hh"
#include "Server.hh"

std::map<int8_t, Protocol::funcPtr>	Protocol::_binProtocol;

Protocol::Protocol()
{
  if (Protocol::_binProtocol.empty())
  {
    Protocol::_binProtocol[2] = &Protocol::createGame;
    Protocol::_binProtocol[5] = &Protocol::joinGame;
  }
}

Protocol::~Protocol()
{
}

int32_t Protocol::executeRequest(Server *serv, Client *cli, char *buf)
{
  try
  {
    std::cout << std::endl;
    std::cout << "[LOG] Receveiving request number " << (int) buf[0] << std::endl;
    return ((this->*_binProtocol.at(buf[0]))(serv, cli, buf));
  }
  catch (std::out_of_range const& oor)
  {
    (void) oor;
    std::cerr << "[ERROR] Bad request (ID = " << (int) buf[0] << "). Request rejected." << std::endl;
    return (-1);
  }
}

int32_t Protocol::createGame(Server *serv, Client *cli, char *buf)
{
  int32_t gameID;

  std::cout << "createGame" << std::endl;
  if ((gameID = serv->createNewGame(cli)) == -1)
  {
    buf[0] = 4;
    return (1);
  }
  else
  {
    buf[0] = 3;
    return (1);
  }
}

int32_t Protocol::joinGame(Server *serv, Client *cli, char *buf)
{
  int16_t idGame = (reinterpret_cast<const int16_t *>(buf + 1))[0];

  std::cout << "joinGame : " << idGame << std::endl;
  Game  *game = serv->getGameID(idGame);
  if (game != NULL && game->addPlayer(cli))
  {
    buf[0] = 6;
    return (1);
  }
  else
  {
    buf[0] = 7;
    return (1);
  }
}
