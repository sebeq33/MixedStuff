//
// TCPSocket.hh for TCPSocket.hh in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 18:57:45 2013 sebastien bequignon
// Last update Mon Jul 22 18:59:02 2013 sebastien bequignon
//

#ifndef TCPSOCKET_H_
# define TCPSOCKET_H_

#ifdef WIN32

#include "TCPSocketWindows.hh"
typedef TCPSocketWindows TCPSocket;

#else

#include "TCPSocketUnix.hh"
typedef TCPSocketUnix TCPSocket;

#endif

#endif /* !TCPSOCKET_H_ */
