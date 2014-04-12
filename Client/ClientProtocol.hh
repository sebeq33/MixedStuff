#ifndef		PROTOCOL_HH_
# define	PROTOCOL_HH_

# include	<iostream>
# include	<stdexcept>
# include	<list>
# include	<map>
# include	<string>
# include	<stdint.h>
# include	<string.h>

class	Protocol
{
public:
	Protocol();
	~Protocol();

	int32_t	executeRequest(char *);

private:
	Protocol(Protocol const&);
	Protocol&	operator=(Protocol const&);

	int32_t	createConfirmation(char *);

	typedef int32_t	(Protocol::*funcPtr)(char *);
	static std::map<int8_t, funcPtr>	_binProtocol;
};

#endif /* !PROTOCOL_HH_ */
