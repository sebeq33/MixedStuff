#ifndef SELECT_H_
# define SELECT_H_

#ifdef WIN32
#  include <WinSock2.h>
#else
#  include <sys/socket.h>
#  include <sys/types.h>
#endif

#include <stdint.h>
#include <stddef.h>
#include "SocketException.hh"
#include "ISelectable.hh"

class Select
{
private:
  fd_set        _readfds;
  fd_set	_writefds;
  int32_t       _maxfd;

public:
  void          prepareRead(const ISelectable &s);
  void          prepareWrite(const ISelectable &s);
  void          clearSet(void);
  bool		readable(const ISelectable &s) const;
  bool		writable(const ISelectable &s) const;
  int32_t	select(void);
  int32_t	selectTimeOut(uint32_t second = 0, uint16_t milli = 0);
};

#endif
