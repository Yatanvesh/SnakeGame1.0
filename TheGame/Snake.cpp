#include "Snake.h"


Snake::Snake()
{
	HeadTexture.loadFromFile("Data/Head.png");
	Head.setTexture(HeadTexture);
	Head.setOrigin(48, 23);
	Head.setScale(0.6, 0.6);

	HeadCollSprTexture.loadFromFile("Data/CollBlock.png"); HeadCollSpr.setTexture(HeadCollSprTexture);
	Speed = 0.4;
	OriginalSpeed = Speed;
	MaxSpeed = Speed * 1.5;
	Direction = 'D';
	
	GulpBuffer.loadFromFile("Data/Sound/Gulp.ogg");
	MoveBuffer.loadFromFile("Data/Sound/Snake.ogg");
	Gulp.setBuffer(GulpBuffer);
	MoveSound.setBuffer(MoveBuffer);
	MoveSound.setVolume(70);

	JustMadeATurn = true;
	Body.push_back(new Block());
	
	Body.push_back(new Block());
	
	Body.push_back(new Block());
	Head.setPosition(0, 0);
	TheBaitList.push_back(new Bait);
	
	TheBaitList.push_back(new Bait(LowSpeed));
	TheBaitList.push_back(new Bait(LowSpeed));
	TheBaitList.push_back(new Bait(LowSpeed));
	TheBaitList.push_back(new Bait(MedSpeed));
	TheBaitList.push_back(new Bait(MedSpeed));
	TheBaitList.push_back(new Bait(HighSpeed));
	TheBaitList.push_back(new Bait(HighSpeed));
}


Snake::~Snake()
{
	Gulp.resetBuffer();
	MoveSound.resetBuffer();
	
}
void Snake::Move()
{
	
	if (MoveSound.getStatus() != sf::Sound::Playing)
		MoveSound.play();
	switch (Direction)
	{
	case 'W':Head.move(0, -1 * Speed);break;
	case 'S':Head.move(0, 1 * Speed); break;
	case 'A':Head.move(-1 * Speed, 0); break;
	case 'D':Head.move(1 * Speed, 0); break;
	}
	
	if (Direction != 'W')
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (Direction != 'S')
			{
				Direction = 'W'; Head.setRotation(-90);
				JustMadeATurn = true;
			}

		}
	}

	if (Direction != 'S')
	{

	
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (Direction != 'W')
			{
				Direction = 'S'; Head.setRotation(90);
				JustMadeATurn = true;
			}
		
		}

	}
	if (Direction != 'A')
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{

			if (Direction != 'D')
			{
				Direction = 'A'; Head.setRotation(180);
			JustMadeATurn = true;
			}


		}
	}
	if (Direction != 'D')
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (Direction != 'A')
			{
				Direction = 'D'; Head.setRotation(0);
				JustMadeATurn = true;
			}

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))Speed = MaxSpeed;
	else Speed = OriginalSpeed;
	if (Head.getPosition().x < 0)Head.move(ScreenDimensions.x, 0);
	else if (Head.getPosition().x>ScreenDimensions.x)Head.move(-ScreenDimensions.x, 0);
	else if (Head.getPosition().y < 0)Head.move(0, ScreenDimensions.y);
	else if (Head.getPosition().y>ScreenDimensions.y) Head.move(0, -ScreenDimensions.y);
	
	HeadCollSpr.setPosition(Head.getPosition());
	
	for (Baititr = TheBaitList.begin(); Baititr != TheBaitList.end(); Baititr++)
	{
		if (Head.getGlobalBounds().intersects((*Baititr)->TheBait.getGlobalBounds()))
		{
			Gulp.play();
			(*Baititr)->SetRandPos();
			GenBlock();
		}
		(*Baititr)->BaitHandler();
		
	}
	
	
	if (PixelMoveDistance > Body.back()->Body.getLocalBounds().width&&JustAddedABlock==0)
	{
		Body.back()->Body.setPosition(Head.getPosition().x, Head.getPosition().y);
		PixelMoveDistance = 0;
		Body.push_front(Body.back()); Body.pop_back();

	}
	JustAddedABlock = false;
	for (itr = Body.begin(), enditr = Body.end(); itr != enditr; itr++)
	{
		
		GameWindow.draw((*itr)->Body);
	}
	
	
	GameWindow.draw(Head);
		
	
		if (GameClock.getElapsedTime().asSeconds() > 1)
		{
			if (SelfCollision())ItsOver=1;
			PixelMoveDistance += Speed*2.5;
		}
		else PixelMoveDistance+=1;
		OriginalSpeed += 0.000006;
		
		MaxSpeed += 0.000006;
	
}



void Snake::GenBlock()
{

	Body.push_front(new Block);
	JustAddedABlock = true;
	SnakeSize++;
}
bool Snake::SelfCollision()
{
	int i;
	for (i = 0, enditr = Body.end(),  testitr = Body.begin(), testitr++; testitr != enditr; testitr++, i++)
			if (HeadCollSpr.getGlobalBounds().intersects((*testitr)->Body.getGlobalBounds())&&i>3)
			return true;
	
	return false;
}



