//
// UDPSocketUnix.hh for UDPSocketUnix.hh in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 18:44:21 2013 sebastien bequignon
// Last update Mon Jul 22 20:00:14 2013 sebastien bequignon
//

#ifndef UDPSOCKETUNIX_H_
# define UDPSOCKETUNIX_H_

#ifndef __linux__
#error You tried to use unix socket on non-linux OS
#else

#  include <stdint.h>
#  include <arpa/inet.h>
#  include <sys/socket.h>
#  include <sys/types.h>
#  include <unistd.h>
#  include <netdb.h>
#  include <sys/types.h>

# include <string>
# include <iostream>
# include "SocketException.hh"
# include "ISelectable.hh"

class UDPSocketUnix : public ISelectable
{
protected:
  int32_t		_sock;
  struct sockaddr_in    focus;

  bool			opened : 1;
  bool			listening : 1;
  bool			focusing : 1;

private:
  UDPSocketUnix(const UDPSocketUnix &);
  UDPSocketUnix &operator=(UDPSocketUnix const &);

public:
  UDPSocketUnix(void);
  ~UDPSocketUnix(void);

  void		init(void);
  void		listen(int16_t port);
  void		listen(std::string const& host, int16_t port);
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

#endif

#endif /* !UDPSOCKETUNIX_H_ */
