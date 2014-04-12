#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <SFML/Graphics.hpp>
#include "Mouse.hh"

class GameWindow
{
private:
  sf::RenderWindow window;
  Mouse mouse;
  GameWindow(const GameWindow &);
  GameWindow & operator=(const GameWindow &);
public:
  enum KeyInfo
    {
      LEFTCLICK,
      DOWN, //s ou bas
      UP, // z ou haut
      LEFT, // q ou gauche
      RIGHT, // d ou droite
      SHOOT, // space
      SHIELD, // shift
      FLASH, // ctrl
      QUIT // escape + fenêtre de confirm'
    };
  GameWindow();
  ~GameWindow();
  void start();
  void cleanWindow();
  bool isButtonPressed(KeyInfo in) const;
  sf::RenderWindow & getWindow();
  Mouse & getMouse();
};

#endif /* ! GAMEWINDOW_HH */

