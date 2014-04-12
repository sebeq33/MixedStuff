#include "Library.hh"
#include <iostream>

int	main()
{
	Library	library;
	void	(*func)(const std::string &);

	if (!library.load("libTest"))
	{
		std::cerr << library.getLastError() << std::endl;
		return (1);
	}
	if ((func = reinterpret_cast<void (*)(const std::string &)>(library.getSymbol("libFunction"))) == NULL)
	{
		std::cerr << library.getLastError() << std::endl;
		return (1);
	}
	func("Hello World !");
	return (0);
}
