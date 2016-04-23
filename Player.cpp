#include <Player.hpp>
#include <math.h>


Player::Player(std::string texturePath, sf::Vector2f position)
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
	pSprite->setScale(0.5, 0.5);
	pSprite->setOrigin(175,50);
	pSprite->setPosition(position);
	
}

void Player::render(sf::RenderWindow *rw)
{
	rw->draw(*pSprite);
}

void Player::handle()
{

}

void Player::update(float frametime, sf::RenderWindow *rw)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		pSprite->move(-200*frametime,0);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		pSprite->move(0, 200 * frametime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		pSprite->move( 200 * frametime, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		pSprite->move(0, -200 * frametime);

	//Mausposi relativ zum window
	sf::Vector2i mousPosition = sf::Mouse::getPosition(*rw);

	//position des "player"
	sf::Vector2f playerPosition = pSprite->getPosition();

	float rotation = pSprite->getRotation();
	//std::cout << position.x << " " << position.y << "\n";

	float angle = atan2((playerPosition.y - mousPosition.y) , (playerPosition.x - mousPosition.x));
	angle = (angle *180) / 3.14159265;

	if(angle <= 0 ) angle = 360+angle;
	std::cout << "angle: " << angle << " "<< rotation <<"\n";

	pSprite->setRotation(angle);
}