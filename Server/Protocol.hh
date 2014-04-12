#ifndef		PROTOCOL_HH_
# define	PROTOCOL_HH_

# include	<iostream>
# include	<stdexcept>
# include	<list>
# include	<map>
# include	<string>
# include	<stdint.h>
# include	<string.h>

# include "Client.hh"

class Server;

class	Protocol
{
public:
	Protocol();
	~Protocol();

	int32_t	executeRequest(Server *, Client *, char *);

private:
	Protocol(Protocol const&);
	Protocol&	operator=(Protocol const&);

	int32_t	createGame(Server *, Client *, char *);
	int32_t joinGame(Server *, Client *, char *);

	typedef int32_t	(Protocol::*funcPtr)(Server *, Client *, char *);
	static std::map<int8_t, funcPtr>	_binProtocol;
};

#endif /* !PROTOCOL_HH_ */
