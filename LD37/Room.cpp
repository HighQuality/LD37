#include "stdafx.h"
#include "Room.h"
#include "Game.h"
#include "GameObject.h"


Room::Room()
{
	myGameObjects.emplace_back(new GameObject("bag.png", sf::Vector2f(0.f, 0.f)));
	myGameObjects.emplace_back(new GameObject("bag.png", sf::Vector2f(128.f, 300)));
}

void Room::Update(float aDeltaTime)
{
	for (auto && object : myGameObjects)
	{
		object->Update(aDeltaTime);
	}
}

void Room::Render(sf::RenderTarget& aRenderTarget) const
{
	for (auto && object : myGameObjects)
	{
		object->Render(aRenderTarget);
	}
}

Room::~Room()
{
}
