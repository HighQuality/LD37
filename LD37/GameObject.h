#pragma once

class GameObject
{
public:
	GameObject(const std::string & aTexturePath, const sf::Vector2f & aPosition);
	virtual ~GameObject();
	
	virtual void Update(const float aDeltaTime);
	virtual void Render(sf::RenderTarget & aRenderTarget) const;

	void SetPosition(const sf::Vector2f & aPosition);
	const sf::Vector2f & GetPosition() const;
	void AddPosition(const sf::Vector2f & aPosition);

protected:
	sf::Sprite mySprite;
	sf::Vector2f myVelocity;
};

