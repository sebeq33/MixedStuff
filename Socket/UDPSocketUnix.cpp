//
// UDPSocketUnix.cpp for UDPSocketUnix.cpp in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jul 19 16:03:14 2013 sebastien bequignon
// Last update Wed Jul 24 16:14:15 2013 sebastien bequignon
//

#ifdef __linux__
#include "UDPSocketUnix.hh"

UDPSocketUnix::UDPSocketUnix(void)
  : opened(false), listening(false), focusing(false)
{
}

UDPSocketUnix::~UDPSocketUnix(void)
{
  tryClose();
}

void	UDPSocketUnix::init(void)
{
  if (this->opened)
    throw (SocketException("Error socket already initialized."));
  struct protoent       *pen;

  if ((pen = getprotobyname("UDP")) == NULL)
    throw (SocketException("Error while retrieving UDP protocol."));
  if ((this->_sock = socket(PF_INET, SOCK_DGRAM, pen->p_proto)) == -1)
    throw (SocketException("Error while creating the socket."));
  opened = true;
}

void	UDPSocketUnix::listen(int16_t port)
{
  if (this->listening)
    throw (SocketException("Error socket already listening, close before changing it."));
  char i = 1;
  setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
  struct sockaddr_in sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(this->_sock, reinterpret_cast<struct sockaddr *>(&sin), sizeof(sin)) == -1)
    throw (SocketException("Error while binding the socket."));
  listening = true;
}

void	UDPSocketUnix::listen(std::string const& host, int16_t port)
{
  char i = 1;
  if (!this->listening)
    throw (SocketException("Error socket already listening, close before changing it."));
  setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
  struct sockaddr_in sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(host.c_str());
  if (bind(this->_sock, reinterpret_cast<struct sockaddr *>(&sin), sizeof(sin)) == -1)
    throw (SocketException("Error while binding the socket."));
  listening = true;
}

int32_t	UDPSocketUnix::recv(char *buf, int32_t blocksize) const
{
  int32_t bytes_received;

  if (!this->listening)
    throw (SocketExceptionIO("Error, listening not initialized."));
  if ((bytes_received = ::recv(this->_sock, buf, blocksize, MSG_NOSIGNAL)) == -1)
    throw (SocketExceptionIO("Error while reading."));
  std::cout << "I just read " << bytes_received << " bytes" << std::endl;
  return (bytes_received);
}

void	UDPSocketUnix::focusSend(std::string const& host, int16_t port)
{
  focus.sin_family = AF_INET;
  focus.sin_port = htons(port);
  focus.sin_addr.s_addr = inet_addr(host.c_str());
  focusing = true;
}

int32_t	UDPSocketUnix::send(const char *buf, int32_t blocksize) const
{
  int32_t sent;

  if (!this->focusing)
    throw (SocketException("Error socket not actually focusing on someone."));
  if ((sent = ::sendto(_sock, buf, blocksize, MSG_NOSIGNAL,
		       reinterpret_cast<const struct sockaddr *>(&this->focus),
		       sizeof(this->focus))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

int32_t	UDPSocketUnix::send(const std::string &str) const
{
  int32_t sent;

  if (!this->focusing)
    throw (SocketException("Error socket not actually focusing on someone."));
  if ((sent = ::sendto(_sock, str.c_str(), str.size(), MSG_NOSIGNAL,
		       reinterpret_cast<const struct sockaddr *>(&this->focus),
		       sizeof(this->focus))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

int32_t	UDPSocketUnix::send(std::string const& host, int16_t port,
	     const char *buf, int32_t blocksize) const
{
  struct sockaddr_in    target;
  int32_t sent;

  target.sin_family = AF_INET;
  target.sin_port = htons(port);
  target.sin_addr.s_addr = inet_addr(host.c_str());
  if ((sent = ::sendto(_sock, buf, blocksize, MSG_NOSIGNAL,
		       reinterpret_cast<struct sockaddr *>(&target), sizeof(target))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);

}

int32_t	UDPSocketUnix::send(std::string const& host, int16_t port,
	     const std::string &str) const
{
  struct sockaddr_in    target;
  int32_t sent;

  target.sin_family = AF_INET;
  target.sin_port = htons(port);
  target.sin_addr.s_addr = inet_addr(host.c_str());
  if ((sent = ::sendto(_sock, str.c_str(), str.size(), MSG_NOSIGNAL,
		       reinterpret_cast<struct sockaddr *>(&target), sizeof(target))) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

void	UDPSocketUnix::tryClose(void)
{
  if (this->opened && close(_sock) == -1)
    throw (SocketException("Error while closing the socket."));
  this->opened = false;
  this->listening = false;
  this->focusing = false;
}

int32_t	UDPSocketUnix::getFD() const
{
  return (_sock);
}

#endif
