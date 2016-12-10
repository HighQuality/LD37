#include "stdafx.h"
#include "Game.h"
#include "Room.h"

Game Game::ourInstance;

Game::Game()
{
}

void Game::Intialize()
{
	myInput = std::make_unique<Input>();
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

Input& Game::GetInput() const
{
	return *myInput;
}

void Game::GameLoop()
{
	sf::Clock clock;
	
	float deltaTime = 1.f / 60.f;

	while (myRenderWindow->isOpen())
	{
		ProcessEvents();
		
		Update(deltaTime);

		myRenderWindow->clear(sf::Color(255, 255, 255));
		Render(*myRenderWindow);
		myRenderWindow->display();

		myInput->Update();

		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (myRenderWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			myRenderWindow->close();
			break;
		case sf::Event::KeyPressed:
			myInput->Press(event.key.code);
			break;
		case sf::Event::KeyReleased:
			myInput->Release(event.key.code);
			break;
		case sf::Event::MouseButtonPressed:
			myInput->Press(event.mouseButton.button);
			break;
		case sf::Event::MouseButtonReleased:
			myInput->Release(event.mouseButton.button);
			break;
		default:
			break;
		}
	}

	myInput->SetMousePosition(sf::Mouse::getPosition(*myRenderWindow));
}

Game::~Game()
{
}

Game& Game::GetInstance()
{
	return ourInstance;
}
