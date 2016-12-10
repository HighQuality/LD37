#pragma once

class Game
{
public:
	~Game();

	static Game & GetInstance();

	void Start();

private:
	void Intialize();
	void GameLoop();
	
	void Update(float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget);

	Game();

	std::unique_ptr<sf::RenderWindow> myRenderWindow;

	static Game ourInstance;
};
