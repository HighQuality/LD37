#include "stdafx.h"
#include "Game.h"

Game Game::ourInstance;

Game::Game()
{
}

void Game::Intialize()
{
}

void Game::Update(float aDeltaTime)
{
}

void Game::Render(sf::RenderTarget& aRenderTarget)
{
}

void Game::Start()
{
	myRenderWindow = std::make_unique<sf::RenderWindow>();
	myRenderWindow->setVisible(false);
	myRenderWindow->create(sf::VideoMode(640, 480), "Ludum Dare 37", sf::Style::Default);

	Intialize();

	GameLoop();
}

void Game::GameLoop()
{
	sf::Clock clock;
	
	float deltaTime = 1.f / 60.f;

	while (myRenderWindow->isOpen())
	{
		sf::Event event;
		while (myRenderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				myRenderWindow->close();
		}
		
		Update(deltaTime);

		myRenderWindow->clear();
		Render(*myRenderWindow);
		myRenderWindow->display();

		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

Game::~Game()
{
}

Game& Game::GetInstance()
{
	return ourInstance;
}
