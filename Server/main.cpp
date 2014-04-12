#include "Server.hh"
#include "Convert.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	Server	serv;
	short port;

	if (ac < 2)
		port = 4242;
	else
		port = Convert<short>::convert(std::string(av[1]));

	try
	{
		serv.start(port);
		serv.stop();
	}
	catch(SocketException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
