#include "stdafx.h"
#include "VectorMath.h"

namespace Math
{
	float InvSqrt(float x)
	{
		float xhalf = 0.5f * x;
		int i = *reinterpret_cast<int*>(&x);
		i = 0x5f375a86 - (i >> 1);
		x = *reinterpret_cast<float*>(&i);
		x = x * (1.5f - xhalf * x * x);
		return x;
	}

	float FastLength(const sf::Vector2f & aVector)
	{
		return 1.f / InvSqrt(aVector.x * aVector.x + aVector.y * aVector.y);
	}

	float Length(const sf::Vector2f& aVector)
	{
		return sqrtf(aVector.x * aVector.x + aVector.y * aVector.y);
	}

	sf::Vector2f NormalizeImpl(const sf::Vector2f & aVector, const float aLength)
	{
		if (aLength == 0.f)
		{
			return sf::Vector2f(0.f, 0.f);
		}
		return aVector / aLength;
	}

	sf::Vector2f FastNormalize(const sf::Vector2f& aVector)
	{
		return NormalizeImpl(aVector, FastLength(aVector));
	}

	sf::Vector2f Normalize(const sf::Vector2f& aVector)
	{
		return NormalizeImpl(aVector, Length(aVector));
	}

	sf::Vector2f Normal(const sf::Vector2f& aVector)
	{
		return sf::Vector2f(-aVector.y, aVector.x);
	}
}
