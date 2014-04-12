//
// mainUDP.cpp for mainUDP.cpp in /home/bequig_s//workspace/c++/rtype/socket/newSocket
//
// Made by sebastien bequignon
// Login   <bequig_s@epitech.net>
//
// Started on  Mon Jul 22 19:39:47 2013 sebastien bequignon
// Last update Mon Jul 22 20:05:05 2013 sebastien bequignon
//

#include <iostream>
#include <string>
#include "UDPSocket.hh"

int		main(int ac, char **av)
{
    std::string	buff;
    UDPSocket	sock;
    char		ret[128];

    try
    {
        if (ac > 1)
        {
            std::cout << "[CLIENT]" << std::endl;

            sock.focusSend("127.0.0.1", 4242);
            sock.listen(4343);

            std::cout << "Input : ";
            std::cin >> buff;
            std::cout << "Send : " << buff << std::endl;
            sock.send(buff);

            ret[sock.recv(ret, 127)] = '\0';
            std::cout << "Read : " << ret << std::endl;
        }
        else
        {
            std::cout << "[SERVER]" << std::endl;

            sock.focusSend("127.0.0.1", 4343);
            sock.listen(4242);

#ifdef WIN32
            Sleep(10000);
#else
            sleep(10);
#endif
            ret[sock.recv(ret, 127)] = '\0';
            std::cout << "Read : " << ret << std::endl;

            std::cout << "Input : ";
            std::cin >> buff;
            std::cout << "Send : " << buff << std::endl;
            sock.send(buff);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
