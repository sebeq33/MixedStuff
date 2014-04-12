#ifndef PICTURE_HH_
# define PICTURE_HH_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Picture
{
	sf::Texture		pict;
	sf::Sprite		pictSprite;
public:
	Picture();
	~Picture();
	bool			LoadPicture(const std::string &);
	void			SetSprite();
	void			SetPos(float, float);
	int				DrawPict(sf::RenderWindow &);
	float			GetX() const;
	float			GetY() const;
	sf::Sprite		GetPictSprite()const;

	//void			runBullet(sf::RenderWindow &, float, float);
};

#endif /* !PICTURE_HH_ */