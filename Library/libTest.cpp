#include <iostream>

extern "C"
{
	void	libFunction(const std::string &str)
	{
		std::cout << str << std::endl;
	}
}
