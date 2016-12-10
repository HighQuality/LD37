#pragma once

namespace Math
{
	float InvSqrt(float x);
	float FastLength(const sf::Vector2f & aVector);
	float Length(const sf::Vector2f & aVector);
	sf::Vector2f FastNormalize(const sf::Vector2f & aVector);
	sf::Vector2f Normalize(const sf::Vector2f & aVector);

	sf::Vector2f Normal(const sf::Vector2f & aVector);
}
