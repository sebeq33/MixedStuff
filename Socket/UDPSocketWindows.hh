//
// UDPSocketWindows.hh for UDPSocketWindows.hh in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 18:48:22 2013 sebastien bequignon
// Last update Mon Jul 22 18:49:31 2013 sebastien bequignon
//

#ifndef UDPSOCKETWINDOWS_H_
# define UDPSOCKETWINDOWS_H_

#ifndef WIN32
#error You tried to use window socket on non-windows OS
#endif

#  include <WinSock2.h>
#  include <WS2tcpip.h>
#  pragma comment(lib, "Ws2_32.lib")

# include <stdint.h>
# include <string>
# include <iostream>
# include "SocketException.hh"
# include "ISelectable.hh"

class UDPSocketWindows : ISelectable
{
protected:
  int32_t		_sock;
  struct sockaddr_in    focus;

  bool			listening : 1;
  bool			opened : 1;
  bool			focusing : 1;

private:
  UDPSocketWindows(const UDPSocketWindows &);
  UDPSocketWindows &operator=(UDPSocketWindows const &);

public:
  UDPSocketWindows();
  UDPSocketWindows(int32_t acceptedFD);
  ~UDPSocketWindows(void);

  void		init();
  void		listen(std::string const& host, int16_t port);
  void		listen(int16_t port);
  int32_t	recv(char *buf, int32_t blocksize) const;

  void		focusSend(std::string const& host, int16_t port);
  int32_t	send(const char *buf, int32_t blocksize) const;
  int32_t	send(const std::string &str) const;

  int32_t	send(std::string const& host, int16_t port,
		     const char *buf, int32_t blocksize) const;
  int32_t	send(std::string const& host, int16_t port,
		     const std::string &str) const;

  void		tryClose(void);
  int32_t	getFD() const;
};

#endif /* !UDPSOCKETWINDOWS_H_ */
