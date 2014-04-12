#include "Select.hh"
#include <stddef.h>

void          Select::prepareRead(const ISelectable &s)
{
  FD_SET(s.getFD(), &_readfds);
  if (s.getFD() > _maxfd)
    _maxfd = s.getFD();
}

void          Select::prepareWrite(const ISelectable &s)
{
  FD_SET(s.getFD(), &_writefds);
  if (s.getFD() > _maxfd)
    _maxfd = s.getFD();
}

void	Select::clearSet(void)
{
  FD_ZERO(&_readfds);
  FD_ZERO(&_writefds);
  _maxfd = 0;
}

bool	Select::readable(const ISelectable &s) const
{
  return (FD_ISSET(s.getFD(), &_readfds) != 0);
}

bool	Select::writable(const ISelectable &s) const
{
  return (FD_ISSET(s.getFD(), &_writefds) != 0);
}

int32_t	Select::select(void)
{
  int32_t ret;

  if ((ret = ::select(_maxfd + 1, &_readfds, &_writefds, NULL, NULL)) < 0)
    throw (SocketException("Error while monitoring sockets."));
  return (ret);
}

int32_t	Select::selectTimeOut(uint32_t second, uint16_t milli)
{
  struct timeval tv;
  int32_t ret;

  tv.tv_sec = second;
  tv.tv_usec = milli * 100000;
  if ((ret = ::select(_maxfd + 1, &_readfds, &_writefds, NULL, &tv)) < 0)
    throw (SocketException("Error while monitoring sockets."));
  return (ret);
}
