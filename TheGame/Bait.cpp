#include "Bait.h"


Bait::Bait(BaitType _Type)
{
	TheBaitType = _Type;
	switch (TheBaitType)
	{
	case Static:
		break;
	case LowSpeed:TheBaitSpeed = 0.1;
		break;
	case MedSpeed:TheBaitSpeed = 0.5;
		break;
	case HighSpeed:TheBaitSpeed = 1;
		break;
	default:
		break;
	}
	std::uniform_int_distribution<int> distributionX(1, ScreenDimensions.x);
	std::uniform_int_distribution<int> distributionY(1, ScreenDimensions.y);
	
	BaitPos.x = distributionX(generatorX);
	BaitPos.y = distributionY(generatorY);
	TheBait.setPosition(BaitPos.x, BaitPos.y);
	switch (1+rand()%5)
	{
	case 1:TheBaitTexture.loadFromFile("Data/Bait/B1.png");
		break;
	case 2:TheBaitTexture.loadFromFile("Data/Bait/B2.png");
		break;
	case 3:TheBaitTexture.loadFromFile("Data/Bait/B3.png");
		break;
	case 4:TheBaitTexture.loadFromFile("Data/Bait/B4.png");
		break;
	case 5:TheBaitTexture.loadFromFile("Data/Bait/B5.png");
		break;
	default:
		break;
	}
	
	TheBait.setTexture(TheBaitTexture);
	TheBait.setScale(0.7, 0.7);

}


Bait::~Bait()
{
}
void Bait::SetRandPos()
{
	std::uniform_int_distribution<int> distributionX(1, ScreenDimensions.x);
	std::uniform_int_distribution<int> distributionY(1, ScreenDimensions.y);
	BaitPos.x = distributionX(generatorX);
	BaitPos.y = distributionY(generatorY);
	TheBait.setPosition(BaitPos.x, BaitPos.y);

}
void Bait::BaitHandler()
{
	if (TheBaitType == Static)GameWindow.draw(TheBait);
	else {


		if (!(TheMoveDistance > 0))
		{
			switch (rand() % 4)
			{
			case 0:TheMoveDirection = 'w'; break;
			case 1:TheMoveDirection = 's'; break;
			case 2:TheMoveDirection = 'a'; break;
			case 3:TheMoveDirection = 'd'; break;
			}
		}
	
		if (!(TheMoveDistance>0)) TheMoveDistance = rand()%5090;

		switch (TheMoveDirection)
		{
		case 'w':
			
			TheBait.setRotation(-90);
			if (TheMoveDistance>0) TheBait.move(sf::Vector2f(0.f, -TheBaitSpeed));
			TheMoveDistance--;
			break;
		case 's':
			
			TheBait.setRotation(90);
			if (TheMoveDistance>0)  TheBait.move(sf::Vector2f(0.f, TheBaitSpeed));
			TheMoveDistance--;
			break;
		case 'a':
			
			TheBait.setRotation(180);
			if (TheMoveDistance>0)TheBait.move(sf::Vector2f(-TheBaitSpeed, 0.f));
			TheMoveDistance--;
			break;
		case 'd':
			TheBait.setRotation(0);
			if (TheMoveDistance>0)TheBait.move(sf::Vector2f(TheBaitSpeed, 0.f));
			TheMoveDistance--;
			break;
		default: break;

		}


		if (TheBait.getPosition().x < 0)TheBait.move(ScreenDimensions.x, 0);
		else if (TheBait.getPosition().x>ScreenDimensions.x)TheBait.move(-ScreenDimensions.x, 0);
		else if (TheBait.getPosition().y < 0)TheBait.move(0, ScreenDimensions.y);
		else if (TheBait.getPosition().y>ScreenDimensions.y) TheBait.move(0, -ScreenDimensions.y);

	
	GameWindow.draw(TheBait);
	}
}