#include <Framework.hpp>


Framework::Framework()
{
	pRenderWindow	= new sf::RenderWindow(sf::VideoMode(1280, 720, 32), "MyGame");
	pRenderWindow->setFramerateLimit(60);
	pMainEvent		= new sf::Event;
	pClock			= new sf::Clock;
	mRun			= true;
	pBackground		= new sf::Texture;
	pBackground->loadFromFile("background.jpg");

	pSprite			= new sf::Sprite;
	pSprite->setTexture(*pBackground);

	pPlayer			= new Player(std::string("soldiertest.png"),sf::Vector2f(1000,500));
	pBoxes			= new Boxes(std::string("Boxes.png"),sf::Vector2f(1200,400));
}

Framework::~Framework()
{

}

void Framework::run() 
{
	while (mRun == true)
	{
		update(getFrameTime(), pRenderWindow);
		handleEvents();
		render();
		quit();
	}
}
void Framework::quit() 
{
	if (mRun == false)
	{
		pRenderWindow->close();
	}
}

void Framework::update(float frametime, sf::RenderWindow *rw)
{
	pPlayer->update(frametime, rw);
	pBoxes->update(frametime, rw);
}

void Framework::handleEvents()
{
	while (pRenderWindow->pollEvent(*pMainEvent))
	{
		if (pMainEvent->type == sf::Event::Closed)
		{
			mRun = false;
		}
		pPlayer->handle();
		pBoxes->handle();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		mRun = false;
}

void Framework::render()
{
	pRenderWindow->clear(sf::Color(255, 120, 120));
	pRenderWindow->draw(*pSprite);
	pPlayer->render(pRenderWindow);
	pBoxes->render(pRenderWindow);
	pRenderWindow->display();
}

float Framework::getFrameTime()
{
	mFrameTime = pClock->getElapsedTime().asSeconds();
	pClock->restart();	
	//std::cout << "Frametime: " << mFrameTime << std::endl;

	return mFrameTime;

}