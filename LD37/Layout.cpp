#include "stdafx.h"
#include "Layout.h"
#include "VectorMath.h"


Layout::Layout(const std::string& aImage)
{
	myImage.loadFromFile(aImage);
	myTexture.loadFromImage(myImage);
	mySprite.setTexture(myTexture);

	myNormals.resize(myImage.getSize().x * myImage.getSize().y);

	std::cout << "Generating normals..." << std::endl;

	for (int y=0; y<static_cast<int>(myImage.getSize().y); ++y)
	{
		std::cout << y + 1 << " / " << myImage.getSize().y << std::endl;

		for (int x=0; x<static_cast<int>(myImage.getSize().x); ++x)
		{
			myNormals[x + y * myImage.getSize().x] = FindVectorToNearestWall(sf::Vector2i(x, y), 8);
		}
	}

	std::cout << "Done!" << std::endl;
}

Layout::~Layout()
{
}

bool Layout::CheckCollision(const sf::FloatRect& aRectangle) const
{
	const sf::Vector2i from(static_cast<int>(aRectangle.left), static_cast<int>(aRectangle.top));
	const sf::Vector2i size(static_cast<int>(aRectangle.width), static_cast<int>(aRectangle.height));

	for (int y=0; y<size.y; ++y)
	{
		const int row = from.y + y;

		if (row < 0 || row >= static_cast<int>(myImage.getSize().y))
		{
			continue;
		}
		
		for (int x=0; x<size.x; ++x)
		{
			if (x < 0 || x >= static_cast<int>(myImage.getSize().x))
			{
				continue;
			}

			const sf::Color & aColor = myImage.getPixel(from.x + x, row);

			if (aColor.r == 0 && aColor.g == 0 && aColor.b == 0 && aColor.a == 255)
			{
				return true;
			}
		}
	}

	return false;
}

void Layout::Update(const float aDeltaTime)
{
}

void Layout::Render(sf::RenderTarget& aRenderTarget) const
{
	aRenderTarget.draw(mySprite);
}

sf::Vector2f Layout::FindVectorToNearestWall(const sf::Vector2i& aPoint, const int aRadius) const
{
	const sf::Vector2f pointF(static_cast<float>(aPoint.x), static_cast<float>(aPoint.y));
	const int toY = aPoint.y + aRadius;
	const int toX = aPoint.x + aRadius;
	float nearestDistance = static_cast<float>(aRadius);
	sf::Vector2f nearestVector(0.f, 0.f);
	
	for (int y = aPoint.y - aRadius; y < toY; ++y)
	{
		if (y < 0 || y >= static_cast<int>(myImage.getSize().y))
		{
			continue;
		}

		for (int x = aPoint.x - aRadius; x < toX; ++x)
		{
			if (x < 0 || x >= static_cast<int>(myImage.getSize().x))
			{
				continue;
			}

			if (myImage.getPixel(x, y).a > 128)
			{
				const sf::Vector2f vector = sf::Vector2f(static_cast<float>(x), static_cast<float>(y)) - pointF;
				const float distance = Math::FastLength(vector);

				if (distance < nearestDistance)
				{
					nearestDistance = distance;
					nearestVector = vector;
				}
			}
		}
	}

	return nearestVector;
}
