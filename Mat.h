#pragma once
#include "Card.h"

class Mat
{
private:
	vector<Card*> deck;
	vector<Card*> sideDeck;
	vector<Card*> dark;
	vector<Card*> site;
	vector<Card*> digimonRow;
	vector<Card*> supportRow;
	vector<Card*> hand;

	sf::Vector2i matPos;
	sf::Vector2i digimonRowPos;
	sf::Vector2i supportRowPos;
	sf::Vector2i deckPos;
	sf::Vector2i handPos;

	int cardBuffer;

	sf::Image matImage;
	sf::Texture matTexture;
	sf::Sprite matSprite;

	sf::Image deckImage;
	sf::Texture deckTexture;
	sf::Sprite deckSprite;


	int matWidth;
	int matHeight;
	int deckWidth;
	int deckHeight;

	int refX;
	int refY;
	bool reversed;
	int revFact;

public:
	Mat(int _refX, int _refY, bool _reversed);
	~Mat();

	sf::Sprite& getMatSprite(){ return matSprite; }
	sf::Sprite& getDeckSprite(){ return deckSprite; }

	void addToDeck(Card* card);
	void addToSideDeck(Card* card);
	void addToDark(Card* card);
	void addToSite(Card* card);
	void addToDigimonRow(Card* card);
	void addToSupportRow(Card* card);
	void addToHand(Card* card);
	vector<Card*>& getDeck(){ return deck; }
	vector<Card*>& getSideDeck(){ return sideDeck; }
	vector<Card*>& getDark(){ return dark; }
	vector<Card*>& getSite(){ return site; }
	vector<Card*>& getDigimonRow(){ return digimonRow; }
	vector<Card*>& getSupportRow(){ return supportRow; }
	vector<Card*>& getHand(){ return hand; }
	int getDeckSize(){ return deck.size(); }
};