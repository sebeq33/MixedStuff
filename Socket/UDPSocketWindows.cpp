//
// UDPSocketWindows.cpp for UDPSocketWindows.cpp in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 19:01:52 2013 sebastien bequignon
// Last update Wed Jul 24 16:14:32 2013 sebastien bequignon
//

#include "UDPSocketWindows.hh"

UDPSocketWindows::UDPSocketWindows()
  : opened(false), listening(false), focusing(false)
{
}

UDPSocketWindows::~UDPSocketWindows(void)
{
  tryClose();
}

void	UDPSocketWindows::init()
{
  if (this->opened)
    throw (SocketException("Error socket already initialized."));
  WORD                  wVersionRequested;
  WSADATA               wsaData;

  wVersionRequested = MAKEWORD(2, 2);
  if (WSAStartup(wVersionRequested, &wsaData) != 0)
    throw (SocketException("Error while starting the Windows Socket API."));
  if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
      throw (SocketException("Error while starting the Windows Socket API."));
      WSACleanup();
    }
  if ((this->_sock = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP,
			       NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
    {
      WSACleanup();
      throw SocketException("Error while creating the socket.");
    }
  opened = true;
}

void	UDPSocketWindows::listen(int16_t port)
{
  char i = 1;
  if (this->listening)
    throw (SocketException("Error socket already listening, close before changing it."));
  setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
  struct sockaddr_in sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(this->_sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    throw (SocketException("Error while binding the socket."));
  listening = true;
}

void	UDPSocketWindows::listen(std::string const& host, int16_t port)
{
  char i = 1;
  if (!this->listening)
    throw (SocketException("Error socket already listening, close before changing it."));
  setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
  struct sockaddr_in sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(host.c_str());
  if (bind(this->_sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    throw (SocketException("Error while binding the socket."));
  listening = true;
}

int32_t	UDPSocketWindows::recv(char *buf, int32_t blocksize) const
{
  int32_t bytes_received;

  if (!this->listening)
    throw (SocketExceptionIO("Error, listening not initialized."));
  if ((bytes_received = ::recv(this->_sock, buf, blocksize, 0)) == -1)
    throw (SocketExceptionIO("Error while reading."));
  std::cout << "I just read " << bytes_received << " bytes" << std::endl;
  return (bytes_received);
}

void	UDPSocketWindows::focusSend(std::string const& host, int16_t port)
{
  focus.sin_family = AF_INET;
  focus.sin_port = htons(port);
  focus.sin_addr.s_addr = inet_addr(host.c_str());
  focusing = true;
}

int32_t	UDPSocketWindows::send(const char *buf, int32_t blocksize) const
{
  int32_t sent;

  if (!this->focusing)
    throw (SocketException("Error socket not actually focusing on someone."));
  if ((sent = ::sendto(_sock, buf, blocksize, 0,
		       reinterpret_cast<const struct sockaddr *>(&this->focus)
           , sizeof(this->focus))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

int32_t	UDPSocketWindows::send(const std::string &str) const
{
  int32_t sent;

  if (!this->focusing)
    throw (SocketException("Error socket not actually focusing on someone."));
  if ((sent = ::sendto(_sock, str.c_str(), str.size(), 0,
		       reinterpret_cast<const struct sockaddr *>(&this->focus),
           sizeof(this->focus))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

void	UDPSocketWindows::tryClose(void)
{
  if (this->opened)
    {
      if (closesocket(_sock) == SOCKET_ERROR)
	{
	  WSACleanup();
	  throw (SocketException("Error while closing the socket."));
	}
      WSACleanup();
      this->opened = false;
      this->listening = false;
      this->focusing = false;
    }
}

int32_t	UDPSocketWindows::send(std::string const& host, int16_t port,
	     const char *buf, int32_t blocksize) const
{
  struct sockaddr_in    target;
  int32_t sent;

  target.sin_family = AF_INET;
  target.sin_port = htons(port);
  target.sin_addr.s_addr = inet_addr(host.c_str());
  if ((sent = ::sendto(_sock, buf, blocksize, 0,
		       reinterpret_cast<struct sockaddr *>(&target), sizeof(target))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);

}

int32_t	UDPSocketWindows::send(std::string const& host, int16_t port,
	     const std::string &str) const
{
  struct sockaddr_in    target;
  int32_t sent;

  target.sin_family = AF_INET;
  target.sin_port = htons(port);
  target.sin_addr.s_addr = inet_addr(host.c_str());
  if ((sent = ::sendto(_sock, str.c_str(), str.size(), 0,
		       reinterpret_cast<struct sockaddr *>(&target), sizeof(target))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

int32_t	UDPSocketWindows::getFD() const
{
  return (_sock);
}

