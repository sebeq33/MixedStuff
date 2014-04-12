#include "Picture.hh"

Picture::Picture(void){}
Picture::~Picture(void){}

bool			Picture::LoadPicture(const std::string &image)
{
	if (!this->pict.loadFromFile(image))
		return (false);
	return (true);
}	

void			Picture::SetSprite()
{
	pictSprite.setTexture(pict);
}

void			Picture::SetPos(float x, float y)
{
	this->pictSprite.setPosition(x, y);
}

float			Picture::GetX() const
{
	return (this->pictSprite.getPosition().x);
}

float			Picture::GetY() const
{
	return (this->pictSprite.getPosition().y);
}

sf::Sprite		Picture::GetPictSprite() const
{
	return (this->pictSprite);
}

int				Picture::DrawPict(sf::RenderWindow &app)
{
	app.draw(this->GetPictSprite());
	return (0);
}