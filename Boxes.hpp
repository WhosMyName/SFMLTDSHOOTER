#ifndef BOXES_HPP
#define BOXES_HPP

#include <iostream>
#include "SFML/Graphics.hpp"

class Boxes
{

public:
	Boxes(std::string texturePath, sf::Vector2f position);

	void update(float frametime, sf::RenderWindow *rw);
	void render(sf::RenderWindow *rw);
	void handle();

private:

	//void loadPlayer();
	sf::Texture *pTexture;
	sf::Sprite  *pSprite;
};

#endif // !BOXES_HPP#pragma once
