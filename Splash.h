#pragma once

using namespace std;

struct CHOICE{
	const char* id;
	sf::Image image;
	sf::Texture texture;
	sf::Texture textureActive;
	sf::Sprite sprite;
	bool active;
};
class Splash{
private:
	
	//Background
	sf::Image bgImage;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;
	/*
	//Start Game
	sf::Texture startTexture;
	sf::Texture startActiveTexture;
	sf::Sprite startSprite;
	//Options
	sf::Texture manageDeckTexture;
	sf::Texture manageDeckActiveTexture;
	sf::Sprite manageDeckSprite;
	//Options
	sf::Texture optionsTexture;
	sf::Texture optionsActiveTexture;
	sf::Sprite optionsSprite;
	//Exit Game
	sf::Texture exitTexture;
	sf::Texture exitActiveTexture;
	sf::Sprite exitSprite;
	*/
	///////////TRYING SOMETHING NEW//////////////
	CHOICE startChoice;
	CHOICE optionsChoice;
	CHOICE manageDeckChoice;
	CHOICE exitChoice;

	
	sf::Vector2f choicePos;
	int choiceWidth;
	int choiceHeight;

	//vector<std::pair<sf::Sprite*, bool>> choiceSprites;
	vector<CHOICE*> choices;
public:
	Splash();
	~Splash();

	sf::Sprite& getBGSprite(){ return bgSprite; }
//	sf::Sprite& getStartSprite(){ return startSprite; }
	//sf::Sprite& getOptionsSprite(){ return optionsSprite; }
	//sf::Sprite& getExiteSprite(){ return optionsSprite; }

	vector<CHOICE*>& getChoices(){ return choices; }
};