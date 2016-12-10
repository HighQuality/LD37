#pragma once

class Room;

class Game
{
public:
	~Game();

	static Game & GetInstance();

	void Start();

	Room & GetRoom() const;
	TextureFactory & GetTextureFactory() const;
	Input & GetInput() const;

private:
	void Intialize();
	void GameLoop();
	
	void ProcessEvents();
	void Update(float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget) const;

	Game();

	std::unique_ptr<sf::RenderWindow> myRenderWindow;
	std::unique_ptr<Room> myRoom;
	std::unique_ptr<TextureFactory> myTextureFactory;
	std::unique_ptr<Input> myInput;

	static Game ourInstance;
};
