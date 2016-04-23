#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <Boxes.hpp>

class BoxesManager{
public:
	BoxesManager();

	void insert(Boxes *boxes);

	void update(float frametime);

	void handle();

	void render(sf::RenderWindow *rw);
private:
	std::list<Boxes*> mList;

};

#endif