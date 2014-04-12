#ifndef		CLIENT_HH_
# define	CLIENT_HH_

# include <list>
# include "Player.hh"
# include "TCPSocket.hh"
# include "UDPSocket.hh"

class		Client
{
public:
	Client();
  Client(int16_t);
  ~Client();

  bool		isConnected() const;
  Player	&getPlayer();
  const TCPSocket  &getTCPSocket() const;
  const UDPSocket  &getUDPSocket() const;
  int16_t getID() const;
  int16_t getGameID() const;
  void  setID(int16_t);
  void  setGameID(int16_t);
  bool  isReady() const;
  void  closeSocket();

private:
	Client(Client const &);
	Client &operator=(Client const &);

  bool					ready;
  int16_t       clientID;
  int16_t       gameID;
  TCPSocket			socketTCP;
  UDPSocket     socketUDP;
  Player		    player;
};

#endif /* !CLIENT_HH_ */
