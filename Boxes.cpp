#include <Boxes.hpp>
#include <math.h>


Boxes::Boxes(std::string texturePath, sf::Vector2f position)
{
	pSprite		= new sf::Sprite;
	pTexture	= new sf::Texture;

	/*
	pTexture->loadFromFile("testplayer.png");
	pSprite->setTexture(*pTexture);
	pSprite->setScale(1.4,1.4);
	*/
	sf::Image subImage;
	subImage.loadFromFile(texturePath);
	subImage.createMaskFromColor(sf::Color::White);

	pTexture->loadFromImage(subImage);
	pSprite->setTexture(*pTexture);
	pSprite->setScale(0.3, 0.3);
	pSprite->setOrigin(175,50);
	pSprite->setPosition(position);
	pSprite->setOrigin(pTexture->getSize().x/(rand() % 2 + 1), pTexture->getSize().y/(rand() % 2 + 1));
	
}

void Boxes::render(sf::RenderWindow *rw)
{
	rw->draw(*pSprite);
}

void Boxes::handle()
{

}

void Boxes::update(float frametime)
{
	pSprite->rotate(random * frametime);
	pSprite->move(120*frametime, 0);
	//std::cout << "Random Equals: "<< random << std::endl;
}