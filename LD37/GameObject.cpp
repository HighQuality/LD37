#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& aTexturePath, const sf::Vector2f& aPosition)
{
	mySprite.setTexture(Game::GetInstance().GetTextureFactory().GetTexture(aTexturePath));
	SetPosition(aPosition);
}

GameObject::~GameObject()
{
}

void GameObject::Update(const float aDeltaTime)
{
	AddPosition(myVelocity * aDeltaTime);
}

void GameObject::Render(sf::RenderTarget& aRenderTarget) const
{
	aRenderTarget.draw(mySprite);
}

void GameObject::SetPosition(const sf::Vector2f& aPosition)
{
	mySprite.setPosition(aPosition);
}

const sf::Vector2f& GameObject::GetPosition() const
{
	return mySprite.getPosition();
}

void GameObject::AddPosition(const sf::Vector2f& aPosition)
{
	SetPosition(GetPosition() + aPosition);
}
