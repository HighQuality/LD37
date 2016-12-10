#include "stdafx.h"
#include "TextureFactory.h"

TextureFactory::TextureFactory()
{
}


TextureFactory::~TextureFactory()
{
}

sf::Texture& TextureFactory::GetTexture(const std::string& aTexturePath)
{
	auto && it = myLoadedTextures.find(aTexturePath);

	if (it != myLoadedTextures.end())
	{
		return *it->second;
	}
	
	sf::Texture * texture = new sf::Texture();
	texture->loadFromFile(aTexturePath);
	myLoadedTextures.emplace(aTexturePath, std::unique_ptr<sf::Texture>(texture));
	return *texture;
}
