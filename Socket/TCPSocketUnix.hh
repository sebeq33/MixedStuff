//
// TCPSocketUnix.hh for TCPSocketUnix.hh in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 18:41:20 2013 sebastien bequignon
// Last update Mon Jul 22 19:57:15 2013 sebastien bequignon
//

#ifndef TCPSOCKETUNIX_H_
# define TCPSOCKETUNIX_H_

#ifndef __linux__
#error You tried to use unix socket on non-linux OS
#else
#  include <arpa/inet.h>
#  include <sys/socket.h>
#  include <sys/types.h>
#  include <unistd.h>
#  include <netdb.h>

# include <string>
# include <iostream>
# include "SocketException.hh"
# include "ISelectable.hh"

class TCPSocketUnix : public ISelectable
{
protected:
  int32_t		_sock;

  bool			connected : 1;
  bool			opened : 1;

  void			initProto();

private:
  TCPSocketUnix(const TCPSocketUnix &);
  TCPSocketUnix &operator=(TCPSocketUnix const &);

public:
  TCPSocketUnix();
  TCPSocketUnix(int32_t acceptedFD);
  ~TCPSocketUnix(void);

  void		connect(std::string const& host, int16_t port);
  int32_t	recv(char *buf, int32_t blocksize) const;
  int32_t	send(const char *buf, int32_t blocksize) const;
  int32_t	send(const std::string &str) const;
  void		tryClose(void);
  bool		isConnected() const;
  int32_t	getFD() const;
};
#endif

#endif /* !TCPSOCKETUNIX_H_ */
