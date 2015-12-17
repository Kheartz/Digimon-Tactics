#include "Mat.h"

Mat::Mat(int _refX, int _refY, bool _reversed)
{
	refX = _refX;
	refY = _refY;
	reversed = _reversed;
	if (!reversed)
		revFact = -1;
	else
		revFact = 1;

	matPos.x = reversed * refX - 0 * revFact;
	matPos.y = reversed * refY - 0 * revFact;
	cardBuffer = 5; //size in between adjacent cards
	digimonRowPos.x = reversed * refX - 240 * revFact;
	digimonRowPos.y = reversed * refY - 25 * revFact;
	supportRowPos.x = reversed * refX - 240 * revFact;
	supportRowPos.y = reversed * refY - 250 * revFact;
	handPos.x = reversed * refX - 240 * revFact;
	handPos.y = reversed * refY - 500 * revFact;
	deckPos.x = reversed * refX - 1050 * revFact;
	deckPos.y = reversed * refY - 500 * revFact;

	matWidth = 1200;
	matHeight = 800;
	deckWidth = 137;
	deckHeight = 204;
	
	if (!matImage.loadFromFile("DATA/MISC/mat.png")){ //Load the Image in memory
		//error...
	}
	if (!matTexture.loadFromImage(matImage, sf::IntRect(0, 0, matWidth, matHeight))){
		// error...
	}
	matSprite.setColor(sf::Color(255, 255, 255, 75));
	matSprite.setTexture(matTexture);
	matSprite.setPosition(sf::Vector2f(matPos.x, matPos.y));
	if (reversed)
		matSprite.rotate(180);
	if (!deckImage.loadFromFile("DATA/CARD/deck.png")){ //Load the Image in memory
		//error...
	}
	deckImage.createMaskFromColor(sf::Color(255, 0, 255));
	if (!deckTexture.loadFromImage(deckImage, sf::IntRect(0, 0, deckWidth, deckHeight))){
		// error...
	}
	deckSprite.setTexture(deckTexture);
	deckSprite.setPosition(sf::Vector2f(deckPos.x, deckPos.y));
	if (reversed)
		deckSprite.rotate(180);
}

Mat::~Mat()
{

}

void Mat::addToDeck(Card* card){
	deck.push_back(card);
}
void Mat::addToDigimonRow(Card* card){
	if (digimonRow.size() < 5){
		card->getSSprite().setPosition(digimonRowPos.x - revFact * (digimonRow.size()*(card->getSSprite().getTextureRect().width*card->getSSprite().getScale().x + cardBuffer)), digimonRowPos.y);
		
		if (reversed)
			card->getSSprite().setRotation(180);
		digimonRow.push_back(card);
	}
}
void Mat::addToSupportRow(Card* card){
	if (supportRow.size() < 5){
		card->getSSprite().setPosition(supportRowPos.x - revFact *  (supportRow.size()*(card->getSSprite().getTextureRect().width*card->getSSprite().getScale().x + cardBuffer)), supportRowPos.y);
		
		if (reversed)
			card->getSSprite().setRotation(180);		
		supportRow.push_back(card);
	}
}
void Mat::addToHand(Card* card){
	if (hand.size() < 5){
		card->getSSprite().setPosition(handPos.x - revFact *  (hand.size()*(card->getSSprite().getTextureRect().width*card->getSSprite().getScale().x + cardBuffer)), handPos.y);

		if (reversed)
			card->getSSprite().setRotation(180);
		hand.push_back(card);
	}
}