#include <BoxesManager.hpp>

BoxesManager::BoxesManager()
{
	
}

void BoxesManager::insert(Boxes *boxes){
	mList.push_back(boxes);
}

void BoxesManager::render(sf::RenderWindow *rw)
{
	for(auto it : mList){
		it->render(rw);
	}
}

void BoxesManager::handle()
{
	for(auto it : mList){
		it->handle();
	}
}

void BoxesManager::update(float frametime)
{
	for(auto it : mList){
		it->update(frametime);
	}
}