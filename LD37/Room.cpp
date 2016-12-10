#include "stdafx.h"
#include "Room.h"
#include "Game.h"


Room::Room()
{
	mySprite.setTexture(Game::GetInstance().GetTextureFactory().GetTexture("test.png"));
}

void Room::Update(float aDeltaTime)
{
}

void Room::Render(sf::RenderTarget& aRenderTarget) const
{
	aRenderTarget.draw(mySprite);
}

Room::~Room()
{
}
