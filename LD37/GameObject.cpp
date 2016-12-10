#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& aTexturePath, const sf::Vector2f& aPosition)
{
	mySprite.setTexture(Game::GetInstance().GetTextureFactory().GetTexture(aTexturePath));
	myPosition = aPosition;
}

GameObject::~GameObject()
{
}

void GameObject::Update(const float aDeltaTime)
{
	myPosition += myVelocity * aDeltaTime;
}

void GameObject::Render(sf::RenderTarget& aRenderTarget)
{
	mySprite.setPosition(myPosition);
	aRenderTarget.draw(mySprite);
}

const sf::Vector2f& GameObject::GetPosition() const
{
	return myPosition;
}
