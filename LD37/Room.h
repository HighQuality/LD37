#pragma once

class Layout;
class GameObject;

class Room
{
public:
	Room();
	~Room();

	void Update(float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget) const;

	const sf::Vector2f & GetGravity() const;

private:
	std::vector<std::unique_ptr<GameObject>> myGameObjects;
	std::unique_ptr<Layout> myLayout;
	sf::Vector2f myGravity;
};

