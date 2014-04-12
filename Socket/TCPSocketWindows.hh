//
// TCPSocketWindows.hh for TCPSocketWindows.hh in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 18:50:33 2013 sebastien bequignon
// Last update Mon Jul 22 19:35:20 2013 sebastien bequignon
//

#ifndef TCPSOCKETWINDOWS_H_
# define TCPSOCKETWINDOWS_H_

#ifndef WIN32
#error You tried to use window socket on non-windows OS
#endif

#  include <WinSock2.h>
#  include <WS2tcpip.h>
#  pragma comment(lib, "Ws2_32.lib")

#include <stdint.h>
#include <iostream>
#include "SocketException.hh"
#include "ISelectable.hh"

class TCPSocketWindows : public ISelectable
{
protected:
  int32_t		_sock;

  bool			connected : 1;
  bool			opened : 1;

  void			initProto();
private:
  TCPSocketWindows(const TCPSocketWindows &);
  TCPSocketWindows &operator=(TCPSocketWindows const &);

public:
  TCPSocketWindows();
  TCPSocketWindows(int32_t acceptedFD);
  ~TCPSocketWindows(void);

  void		connect(std::string const& host, int16_t port);
  int32_t	recv(char *buf, int32_t blocksize) const;
  int32_t	send(const char *buf, int32_t blocksize) const;
  int32_t	send(const std::string &str) const;
  void		tryClose(void);
  bool		isConnected() const;
  int32_t	getFD() const;
};

#endif /* !TCPSOCKETWINDOWS_H_ */
