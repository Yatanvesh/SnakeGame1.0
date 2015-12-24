#include "Block.h"


Block::Block()
{
	BodyTexture.loadFromFile("Data/BodyBlock.png");
	Body.setTexture(BodyTexture);
	Body.setScale(0.4, 0.4);
	Body.setOrigin(23, 24.5);
	Body.setPosition(-233, -32);
	
}


Block::~Block()
{
}
