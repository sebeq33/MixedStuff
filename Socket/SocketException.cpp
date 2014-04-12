#include "SocketException.hh"

SocketException::SocketException(const char *message):
	_message(message)
{
}

const char*	SocketException::what() const throw()
{
	return (this->_message);
}

SocketExceptionIO::SocketExceptionIO(const char *message):
	SocketException(message)
{
}

const char*	SocketExceptionIO::what() const throw()
{
	return (_message);
}
