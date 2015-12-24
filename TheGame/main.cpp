#include "SFML/Graphics.hpp"
#include <iostream>
#include "Freedom.h"
#include "Snake.h"
#include "MusicManager.h"
void MusicLoader(int num=-1);
void BackGroundLoader(sf::Sprite *Background, sf::Texture *BackTexture,int n=-1);
using namespace std;
int main()
{
	MusicManager music(GameWindow);
	sf::Clock GameKillClock;
	srand(time(NULL));
	GameWindow.setKeyRepeatEnabled(false);
//	MusicLoader();
	Snake Player;
	sf::Sprite *Background=new sf::Sprite; 
	sf::Texture *BackTexture = new sf::Texture;
	BackGroundLoader(Background,BackTexture);
	while (GameWindow.isOpen())
	{
		
		sf::Event GameEvent;
		while (GameWindow.pollEvent(GameEvent))
		{
			switch (GameEvent.type)
			{
			case sf::Event::Closed:		
				GameWindow.close();
				break;
			
			}
				
		}
		music.Handler();
		GameWindow.clear();
		GameWindow.draw(*Background);
		Player.Move();
		
	
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))GameWindow.close();
		if (ItsOver){
			
			BackGroundLoader(Background, BackTexture, 10);
			Player.Kill();
		}
		music.DisplayPlayer();
		GameWindow.display();
	}
}

void BackGroundLoader(sf::Sprite *Background, sf::Texture *BackTexture,int n)
{
	if (n == -1)n = 1 + rand() % 2;
	
	switch (n)
	{
	case 1:BackTexture->loadFromFile("Data/Background/S1.png"); break;
	
	case 2:	BackTexture->loadFromFile("Data/Background/S3.png"); break;

	
	case 10: BackTexture->loadFromFile("Data/Background/GOver.png"); break;
	}
	delete Background; Background = nullptr; Background = new sf::Sprite;
	Background->setTexture(*BackTexture);
	Background->setScale(ScreenDimensions.x / Background->getLocalBounds().width, ScreenDimensions.y / Background->getGlobalBounds().height);
	Background->scale(1.2, 1.2);  Background->move(0, -ScreenDimensions.y * 0.2);
	
}

void MusicLoader(int num)
{
	if (num == -1)
		num = 1 + rand() % 4;
	switch (num)
	{
	
	case 3:GameMusic.openFromFile("Data/Music/RandomEncounterMusic.ogg"); break;
	case 4:GameMusic.openFromFile("Data/Music/BassDrop.ogg"); break;
	case 1:GameMusic.openFromFile("Data/Music/Minoru187.ogg"); break;
	case 2:GameMusic.openFromFile("Data/Music/Blisters&Coffee.ogg"); break;
	default:GameMusic.openFromFile("Data/Music/RandomEncounterMusic.ogg"); break;
	}
	GameMusic.play();
}

