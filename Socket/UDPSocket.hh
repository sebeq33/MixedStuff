//
// UDPSocket.hh for UDPSocket.hh in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 18:59:18 2013 sebastien bequignon
// Last update Mon Jul 22 19:57:58 2013 sebastien bequignon
//

#ifndef UDPSOCKET_H_
# define UDPSOCKET_H_

#ifdef WIN32

#include "UDPSocketWindows.hh"
typedef UDPSocketWindows UDPSocket;

#else

#include "UDPSocketUnix.hh"
typedef UDPSocketUnix UDPSocket;

#endif

#endif /* !UDPSOCKET_H_ */
