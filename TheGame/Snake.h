#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "Freedom.h"
#include "Bait.h"
#include "Block.h"
#include <iostream>

using namespace std;

class Snake
{
public:
	Snake();
	sf::Sprite Head; sf::Texture HeadTexture;
	sf::Sprite Tail; sf::Texture TailTexture;
	sf::Sprite HeadCollSpr; sf::Texture HeadCollSprTexture;
	sf::Sound Gulp; sf::SoundBuffer GulpBuffer;
	sf::Sound MoveSound; sf::SoundBuffer MoveBuffer;
	list<Bait*> TheBaitList;
	list<Bait*>::iterator Baititr, Baitenditr;
	int SnakeSize = 0;

	list<Block*> Body;
	list<Block*>::iterator itr, enditr,testitr;
	char Direction;
	float Speed,MaxSpeed,OriginalSpeed;

	bool JustAddedABlock = false;
	bool JustMadeATurn;                                  
	float PixelMoveDistance = 0;
	void Move();
	void Kill()
	{
		for (itr = Body.begin(); itr != Body.end(); itr++)
			(*itr)->Body.setColor(sf::Color::Red);
		Head.setColor(sf::Color::Red);
		OriginalSpeed = 0;
	}
	void GenBlock();
	bool SelfCollision();
	sf::Clock GameClock;
	~Snake();
	
};








