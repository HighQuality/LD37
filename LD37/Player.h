#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(const sf::Vector2f & aPosition);
	~Player();
};

