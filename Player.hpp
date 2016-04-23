#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{

public:
	Player(std::string texturePath, sf::Vector2f position);

	void update(float frametime, sf::RenderWindow *rw);
	void render(sf::RenderWindow *rw);
	void handle();

private:

	//void loadPlayer();
	sf::Texture *pTexture;
	sf::Sprite  *pSprite;
};

#endif // !PLAYER_HPP#pragma once
