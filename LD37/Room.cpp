#include "stdafx.h"
#include "Room.h"
#include "Game.h"
#include "GameObject.h"
#include "Layout.h"
#include "Player.h"


Room::Room()
{
	myGameObjects.emplace_back(new Player(sf::Vector2f(640.f, 480.f) / 2.f));

	myLayout = std::make_unique<Layout>("level.png");
}

void Room::Update(float aDeltaTime)
{
	for (auto && object : myGameObjects)
	{
		object->Update(aDeltaTime);
	}

	myLayout->Update(aDeltaTime);
}

void Room::Render(sf::RenderTarget& aRenderTarget) const
{
	myLayout->Render(aRenderTarget);

	for (auto && object : myGameObjects)
	{
		object->Render(aRenderTarget);
	}
}

Room::~Room()
{
}
