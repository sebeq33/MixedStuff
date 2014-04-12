//
// TCPSocketWindows.cpp for TCPSocketWindows.cpp in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jul 19 16:42:10 2013 sebastien bequignon
// Last update Mon Jul 22 19:36:02 2013 sebastien bequignon
//

#include "TCPSocketWindows.hh"

TCPSocketWindows::TCPSocketWindows()
  : connected(false), opened(false)
{
}

TCPSocketWindows::TCPSocketWindows(int32_t acceptedFD)
  : _sock(acceptedFD), connected(true), opened(true)
{
  WORD                  wVersionRequested;
  WSADATA               wsaData;

  wVersionRequested = MAKEWORD(2, 2);
  if (WSAStartup(wVersionRequested, &wsaData) != 0)
    throw (SocketException("Error while starting the Windows Socket API."));
}

TCPSocketWindows::~TCPSocketWindows(void)
{
  tryClose();
}

void	TCPSocketWindows::initProto()
{
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
  if ((this->_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP,
			       NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
    {
      WSACleanup();
      throw SocketException("Error while creating the socket.");
    }
  opened = true;
}

void	TCPSocketWindows::connect(std::string const& host, int16_t port)
{
  this->initProto();
  struct sockaddr_in    sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(host.c_str());
  if (::connect(_sock, (struct sockaddr *) &sin, sizeof(sin)) != 0)
    throw (SocketException("Error while connecting the socket."));
  connected = true;
}

int32_t	TCPSocketWindows::recv(char *buf, int32_t blocksize) const
{
  int32_t bytes_received;

  if ((bytes_received = ::recv(_sock, buf, blocksize, 0)) == -1)
    throw (SocketExceptionIO("Error while reading."));
  std::cout << "I just read " << bytes_received << " bytes" << std::endl;
  return (bytes_received);
}

int32_t	TCPSocketWindows::send(const char *buf, int32_t blocksize) const
{
  int32_t sent;

  if ((sent = ::send(_sock, buf, blocksize, 0)) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

int32_t	TCPSocketWindows::send(const std::string &str) const
{
  int32_t sent;

  if ((sent = ::send(_sock, str.c_str(), str.size(), 0)) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

void	TCPSocketWindows::tryClose(void)
{
  if (this->opened)
    {

      if (closesocket(_sock) != 0)
	{
	  WSACleanup();
	  if (WSAGetLastError() != WSANOTINITIALISED)
		throw (SocketException("Error while closing the socket."));
	}
      WSACleanup();
      opened = false;
      connected = false;
    }
}

int32_t	TCPSocketWindows::getFD() const
{
  return (_sock);
}

bool	TCPSocketWindows::isConnected() const
{
  return (connected);
}
