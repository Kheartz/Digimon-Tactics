#include "Card.h"

Card::Card(string idx)
{
	index = idx; //Developer's index
	width = 574; //Card's native width
	height = 814; //Card's native height
	if (!image.loadFromFile("DATA/CARD/" + index + ".png")) //Load the Image in memory
	{
		//error...
	}
	if (!frontTexture.loadFromImage(image, sf::IntRect(0, 0, width, height)))
	{
		// error...
	}
	frontTexture.setSmooth(true);
	sSprite.setTexture(frontTexture);
	sSprite.setScale(sf::Vector2f(0.25f, 0.25f)); //Set small 30% scale
	mSprite.setTexture(frontTexture);
	mSprite.setScale(sf::Vector2f(0.6f, 0.6f)); //Set medium 60% scale
	lSprite.setTexture(frontTexture);
	/*
	if (!backTexture.loadFromFile("DATA/CARD/back.png", sf::IntRect(0, 0, lWidth, lHeight)))
	{
		// error...
	}
	*/

}
Card::~Card()
{

}
void Card::setPosition(int x, int y, string size){
	if (size == "large"){
		lSprite.setPosition(x, y);
	}
	if (size == "medium"){
		mSprite.setPosition(x, y);
	}
	if (size == "small"){
		sSprite.setPosition(x, y);
	}
	else
		sSprite.setPosition(x, y);
}