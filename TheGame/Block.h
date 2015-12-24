#pragma once
#include "SFML/Graphics.hpp"
#include "Freedom.h"
#include <random>
class Block
{
public:
	Block();

	sf::Sprite Body;
	sf::Texture BodyTexture;
	sf::Vector2f Pos;
	
	~Block();
};

