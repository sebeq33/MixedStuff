#include "RType.hh"
#include "Picture.hh"
#include "GameGui.hh"

GameGui::GameGui()
{
  this->x = 0;
  this->y = 200;
  this->starship.LoadPicture("Resources/starship.png");
  this->starship.SetSprite();
  this->starship.SetPos(x, y);
  this->background1.LoadPicture("Resources/star.jpg");
  this->background1.SetSprite();
  this->background1.SetPos(-450, 0);
  this->background2.LoadPicture("Resources/star2.jpg");
  this->background2.SetSprite();
  this->background2.SetPos(450, 0);
}

GameGui::~GameGui()
{}

int GameGui::getNumPlayer() const
{
  return (numPlayer);
}

void                    GameGui::update(RType & r, sf::Event &e)
{
  if (this->background1.GetX() > -900)
    {
      this->background1.SetPos(this->background1.GetX() - 1, 0);
    }
  else
    this->background1.SetPos(0, 0);

  if (this->background2.GetX() > 0)
    {
      this->background2.SetPos(this->background2.GetX() - 1, 0);
    }
  else
    this->background2.SetPos(900, 0);
  if ((r.getGameWindow()).isButtonPressed(GameWindow::LEFT))
    {
      if (x != 0)
        {
          starship.SetPos((x - 10), y);
          x -= 10;
        }
    }
  else if ((r.getGameWindow()).isButtonPressed(GameWindow::RIGHT))
    {
      if ((x + 10) < 868)
        {
          starship.SetPos(x + 10, y);
          x += 10;
        }
    }
  else if ((r.getGameWindow()).isButtonPressed(GameWindow::UP))
    {
      if (y != 0)
        {
          starship.SetPos(x, y - 10);
          y -= 10;
        }
    }
  else if ((r.getGameWindow()).isButtonPressed(GameWindow::DOWN))
    {
      if ((y + 10) < 526)
        {
          starship.SetPos(x, y + 10);
          y += 10;
        }
    }
  else if ((r.getGameWindow()).isButtonPressed(GameWindow::QUIT))
    {
      r.getGameWindow().getWindow().close();
    }
  if ((r.getGameWindow()).isButtonPressed(GameWindow::SHOOT))
    {
      Picture                   *bullet = new Picture;

      this->timer.updateCurrent();
      if (this->timer.getEllapsedTime().getSecond() > 1 || this->timer.getEllapsedTime().getMilli() > 100)
        {
          bullet->LoadPicture("Resources/fireball.png");
          bullet->SetSprite();
          bullet->SetPos(x, y);
          lstBullets.push_back(bullet);
          this->timer.update();
        }
    }
  std::list<Picture *>::iterator it (this->lstBullets.begin()), end(this->lstBullets.end());
  for(;it!=end;++it)
    {
      (*it)->SetPos((*it)->GetX() + 15, (*it)->GetY());
    }

}

void                    GameGui::display(RType &r)
{
  ((r.getGameWindow()).getWindow()).draw(this->background1.GetPictSprite());
  ((r.getGameWindow()).getWindow()).draw(this->background2.GetPictSprite());
  ((r.getGameWindow()).getWindow()).draw(this->starship.GetPictSprite());
  std::list<Picture *>::iterator it (this->lstBullets.begin()), end(this->lstBullets.end());
  for(;it!=end;++it)
    {
      ((r.getGameWindow()).getWindow()).draw((*it)->GetPictSprite());
    }
}
