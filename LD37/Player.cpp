#include "stdafx.h"
#include "Player.h"


Player::Player(const sf::Vector2f & aPosition)
	: GameObject("Resources/Textures/player.png", aPosition)
{
	mySprite.setOrigin(static_cast<float>(mySprite.getTexture()->getSize().x) / 2.f, static_cast<float>(mySprite.getTexture()->getSize().y));
}


Player::~Player()
{
}
