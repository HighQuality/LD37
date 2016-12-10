#pragma once

class GameObject;

class Room
{
public:
	Room();
	~Room();

	void Update(float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget) const;

private:
	std::vector<std::unique_ptr<GameObject>> myGameObjects;
};

