#pragma once
#include "SFML\Graphics.hpp"
#include <random>
#include "Freedom.h"
enum BaitType{Static, LowSpeed, MedSpeed, HighSpeed};
class Bait
{
public:
	Bait(BaitType _type=Static);
	BaitType TheBaitType;
	sf::Sprite TheBait; sf::Texture TheBaitTexture;
	std::default_random_engine generatorX;
	std::default_random_engine generatorY;
	sf::Vector2i BaitPos;
	void BaitHandler();
	void SetRandPos();
	int TheMoveDistance = 0;
	char TheMoveDirection = 'w';
	float TheBaitSpeed=0.4;
	~Bait();
};

