#include "stdafx.h"
#include "Game.h"
#include "Room.h"

Game Game::ourInstance;

Game::Game()
{
}

void Game::Intialize()
{
	myTextureFactory = std::make_unique<TextureFactory>();
	myRoom = std::make_unique<Room>();
}

void Game::Update(float aDeltaTime)
{
	myRoom->Update(aDeltaTime);
}

void Game::Render(sf::RenderTarget& aRenderTarget) const
{
	myRoom->Render(aRenderTarget);
}

void Game::Start()
{
	myRenderWindow = std::make_unique<sf::RenderWindow>();
	myRenderWindow->create(sf::VideoMode(640, 480), "Ludum Dare 37", sf::Style::Default ^ sf::Style::Resize);

	Intialize();

	GameLoop();
}

Room& Game::GetRoom() const
{
	return *myRoom;
}

TextureFactory& Game::GetTextureFactory() const
{
	return *myTextureFactory;
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
