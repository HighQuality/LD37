#pragma once
class TextureFactory
{
public:
	TextureFactory();
	~TextureFactory();

	sf::Texture & GetTexture(const std::string & aTexturePath);

private:
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> myLoadedTextures;
};

