//
// ServerSocketUnix.cpp for ServerSocketUnix.cpp in /home/bequig_s//workspace/c++/rtype/socket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Thu Jul 18 16:09:55 2013 sebastien bequignon
// Last update Wed Jul 24 16:12:48 2013 sebastien bequignon
//

#include "TCPServer.hh"

TCPServer::TCPServer()
  : TCPSocket()
{
}

TCPServer::~TCPServer()
{

}

void		TCPServer::init(short listenPort)
{
  struct sockaddr_in    sin;
  char  i = 1;

  this->initProto();
  sin.sin_family = AF_INET;
  sin.sin_port = htons(listenPort);
  sin.sin_addr.s_addr = INADDR_ANY;
  setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
  if (bind(this->_sock, (struct sockaddr *) &sin, sizeof(sin)) == -1)
    throw (SocketException("Error while binding the server socket."));
  if (listen(this->_sock, 5) == -1)
    throw (SocketException("Error while listening for connections on the server socket."));
  this->clearSet();
  this->prepareRead(*this);
}

void		TCPServer::init(std::string const & listenHost, short listenPort)
{
  struct sockaddr_in    sin;
  char  i = 1;

  this->initProto();
  sin.sin_family = AF_INET;
  sin.sin_port = htons(listenPort);
  sin.sin_addr.s_addr = inet_addr(listenHost.c_str());
  setsockopt(this->_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
  if (bind(this->_sock, (struct sockaddr *) &sin, sizeof(sin)) == -1)
    throw (SocketException("Error while binding the server socket."));
  if (listen(this->_sock, 5) == -1)
    throw (SocketException("Error while listening for connections on the server socket."));
  this->clearSet();
  this->prepareRead(*this);
}

TCPSocket	*TCPServer::accept()
{
  int32_t               sockfd;
  struct sockaddr_in    sin_client;
  socklen_t             client_size;

  client_size = sizeof(sin_client);
  if ((sockfd = ::accept(this->_sock,
                         (struct sockaddr *) &sin_client, &client_size)) == -1)
    throw (SocketException("Error while accepting a new socket."));
  else
    return (new TCPSocket(sockfd));
}

bool	TCPServer::hasPendingConnection() const
{
  return (this->readable(*this));
}
