#pragma once


using namespace std;

class Card
{
private:
	string name;
	string index;
	int width;
	int height;


	//SFML rect
	sf::Image image;
	sf::Texture frontTexture;
	sf::Texture backTexture;
	sf::Sprite sSprite;
	sf::Sprite mSprite;
	sf::Sprite lSprite;
	
public:
	//Card();
	Card(string idx);
	~Card();
	
	string getName() { return name; }
	string getIndex() { return index; }
	sf::Sprite& getSSprite(){ return sSprite; }
	sf::Sprite& getMSprite(){ return mSprite; }
	sf::Sprite& getLSprite(){ return lSprite; }

	void setPosition(int x, int y, string size);

};