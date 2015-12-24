#include "Freedom.h"

//sf::Time Freedom = sf::seconds(0.005);
//sf::Vector2f GlobalScaleFactor(1,1);
sf::Vector2f ScreenDimensions(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
//sf::Vector2f ViewDimensions(0, 0);
//sf::Vector2f GlobalMousePosition(ScreenDimensions.x / 2, ScreenDimensions.y / 2);
//sf::View GameView; 
//float GameViewRotation = 0;
//float GameViewZoom = 1;
//sf::Vector2f GameViewCenter(0.0,0.0);

sf::RenderWindow GameWindow(sf::VideoMode(1024, 768), "TheGame", sf::Style::Default);
sf::Music GameMusic;
bool ItsOver=false;
	