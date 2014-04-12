#include "RType.hh"
#include "StartMenu.hh"
#include "Convert.hpp"

RType::RType()
{
}

RType::~RType()
{

}

bool RType::loadConfig()
{
	std::fstream fs;
	char ip[256];
	char cPort[256];
  	fs.open ("Config.txt", std::fstream::in);
  	fs.getline(ip, 256);
  	fs.getline(cPort, 256);
  	fs.close();
  	std::string sPort(cPort);
  	int port = Convert<int>::convert(sPort);
	std::cout << "CONNECT() : ..." << std::endl;
	socketTCP.connect(ip, port);
	return (socketTCP.isConnected());
}

void RType::startLoop()
{
  if (!loadConfig())
    return ;
  gameWindow.start();
  Timer timer;
  sf::RenderWindow & window = gameWindow.getWindow();
  StartMenu *start = new StartMenu();

  pushGUI(start);
  while (window.isOpen())
    {
      sf::Event e;
      while (window.pollEvent(e))
	{

	  if (e.type == sf::Event::Closed)
	    {
	      window.close();
	      break;
	    }
	}
      (guiList.back())->update(*this, e);
      window.clear();
      (guiList.back())->display(*this);
      window.display();

      timer.update();
      timer.sleepFPS(60);
    }
}

GameWindow & RType::getGameWindow()
{
	return (gameWindow);
}

void RType::pushGUI(IGUI *gui)
{
	guiList.push_back(gui);
}

void RType::popGUI(IGUI *gui)
{
	guiList.remove(gui);
}

const TCPSocket  &RType::getTCPSocket() const
{
	return (socketTCP);
}

const UDPSocket  &RType::getUDPSocket() const
{
	return (socketUDP);
}
