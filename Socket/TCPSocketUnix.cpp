//
// TCPSocketUnix.cpp for TCPSocketUnix.cpp in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Fri Jul 19 16:21:22 2013 sebastien bequignon
// Last update Sun Jul 28 21:45:13 2013 sebastien bequignon
//

#ifdef __linux__
#include "TCPSocketUnix.hh"

TCPSocketUnix::TCPSocketUnix()
  : connected(false), opened(false)
{
}

TCPSocketUnix::TCPSocketUnix(int32_t acceptedFD)
  : _sock(acceptedFD), connected(true), opened(true)
{

}

TCPSocketUnix::~TCPSocketUnix(void)
{
  tryClose();
}

void TCPSocketUnix::initProto()
{
  struct protoent       *pen;

  if ((pen = getprotobyname("TCP")) == NULL)
    throw (SocketException("Error while retrieving TCP protocol."));
  if ((this->_sock = socket(PF_INET, SOCK_STREAM, pen->p_proto)) == -1)
    throw (SocketException("Error while creating the socket."));
  opened = true;
}

void	TCPSocketUnix::connect(std::string const& host, int16_t port)
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

int32_t	TCPSocketUnix::recv(char *buf, int32_t blocksize) const
{
  int32_t bytes_received;

  if ((bytes_received = ::recv(_sock, buf, blocksize, MSG_NOSIGNAL)) == -1)
    throw (SocketExceptionIO("Error while reading."));
  std::cout << "I just read " << bytes_received << " bytes" << std::endl;
  return (bytes_received);
}

int32_t	TCPSocketUnix::send(const char *buf, int32_t blocksize) const
{
  int32_t sent;

  if ((sent = ::send(_sock, buf, blocksize, MSG_NOSIGNAL)) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

int32_t	TCPSocketUnix::send(const std::string &str) const
{
  int32_t sent;

  if ((sent = ::send(_sock, str.c_str(), str.size(), MSG_NOSIGNAL)) == -1)
    throw (SocketExceptionIO("Error while writing."));
  return (sent);
}

void	TCPSocketUnix::tryClose(void)
{
  if (this->opened && close(_sock) == -1)
    throw (SocketException("Error while closing the socket."));
  this->opened = false;
  this->connected = false;
}

int32_t	TCPSocketUnix::getFD() const
{
  return (_sock);
}

bool	TCPSocketUnix::isConnected() const
{
  return (connected);
}

#endif
