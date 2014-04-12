#include <iostream>
#include <SFML/Graphics.hpp>
#include "RType.hh"
#include "GameWindow.hh"
#include "Time.hh"

int main()
{
  Time::updateStart();

  try
    {
      RType r;

      r.startLoop();
    }
  catch (std::exception & e)
    {
      std::cout << e.what() << std::endl;
    }

  return (0);
}
