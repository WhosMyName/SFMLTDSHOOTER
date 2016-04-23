#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"

class Framework
{
	public:
		Framework();
		~Framework();

		void run();

	private:
	
		void quit();
		void update(float frametime, sf::RenderWindow *rw);
		void handleEvents();
		void render();

		float getFrameTime();

		sf::RenderWindow	*pRenderWindow;
		sf::Event			*pMainEvent;
		sf::Clock			*pClock;
		
		sf::Texture			*pBackground;
		sf::Sprite			*pSprite;

		float				mFrameTime;
		bool				mRun;

		Player				*pPlayer;

};


#endif // !FRAMEWORK_HPP

