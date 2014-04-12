#ifndef		SERVER_HH_
# define	SERVER_HH_

# include <list>
# include <stdint.h>

# include "Client.hh"
# include "Game.hh"
# include "EntityManager.hh"
# include "Timer.hh"
# include "TCPServer.hh"
# include "Protocol.hh"
# include "HandleID.hh"

# ifdef WIN32
# include <windows.h>
# else
# include <signal.h>
# endif

class			Server
{
public:
  Server();
  ~Server();

  static bool     _sigcatch;
  void	start(short);
  void	stop();

  unsigned int  createNewGame(Client *);
  Game          *getGameID(int16_t);

private:
  Server(Server const &);
  Server &operator=(Server const &);

  void  checkNewClient();
  void  checkClientData(int32_t);
  void  prepareClient();
  bool  checkReadableClient(const TCPSocket &,
			    Client *cli,
			    std::list<Client *>::iterator);
  void  checkClientGame(const Client *cli);

  std::list<Game *>     gameList;
  std::list<Client  *>  clientList;
  EntityManager         entityManager;
  Timer                 timer;
  TCPServer             socket;
  HandleID              handleID;
  Protocol              p;
};

#endif /* !SERVER_HH_ */
