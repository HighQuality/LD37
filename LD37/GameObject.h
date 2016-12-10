#pragma once

class GameObject
{
public:
	GameObject(const std::string & aTexturePath, const sf::Vector2f & aPosition);
	~GameObject();
	
	void Update(const float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget);

	const sf::Vector2f & GetPosition() const;

private:
	sf::Sprite mySprite;
	sf::Vector2f myPosition;
	sf::Vector2f myVelocity;
};

