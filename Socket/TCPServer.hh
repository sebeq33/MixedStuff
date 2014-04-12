//
// ServerSocketUnix.hh for ServerSocketUnix.hh in /home/bequig_s//workspace/c++/rtype/socket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jul 18 16:28:24 2013 sebastien bequignon
// Last update Mon Jul 22 19:26:17 2013 sebastien bequignon
//

#ifndef TCP_SERVER_UNIX_WINDOWS_H_
# define TCP_SERVER_UNIX_WINDOWS_H_

#include "TCPSocket.hh"
#include "Select.hh"

class TCPServer : public TCPSocket, public Select
{
private:
  TCPServer(const TCPServer &);
  TCPServer &operator=(const TCPServer &);

public:
  TCPServer();
  ~TCPServer();
  void		      init(std::string const & listenHost, short listenPort);
  void		      init(short listenPort = 4242);
  TCPSocket*	  accept();
  bool		      hasPendingConnection() const;
};

#endif /* !TCP_SERVER_UNIX_WINDOWS_H_ */
