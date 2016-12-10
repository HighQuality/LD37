#pragma once

class Layout
{
public:
	Layout(const std::string & aImage);
	~Layout();

	bool CheckCollision(const sf::FloatRect & aRectangle) const;

	void Update(const float aDeltaTime);
	void Render(sf::RenderTarget & aRenderTarget) const;

private:
	sf::Vector2f FindVectorToNearestWall(const sf::Vector2i & aPoint, const int aRadius) const;

	sf::Sprite mySprite;
	sf::Texture myTexture;
	sf::Image myImage;
	std::vector<sf::Vector2f> myNormals;
};
