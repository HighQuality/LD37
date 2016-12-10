#pragma once

class Room
{
public:
	Room();
	~Room();

	void Update(float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget) const;

private:
	sf::Sprite mySprite;
};

