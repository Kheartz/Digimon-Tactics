#include "Splash.h"

Splash::Splash(){
	//Splash BG
	if (!bgImage.loadFromFile("DATA/MISC/splashbg.png")){
		//error...
	}
	if (!bgTexture.loadFromImage(bgImage, sf::IntRect(0, 0, 1280, 800))){
		//error...
	}
	bgSprite.setTexture(bgTexture);

	choiceWidth = 325;
	choiceHeight = 43;

	//Start Game
	if (!startChoice.texture.loadFromFile(("DATA/MISC/start.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight)) ||
		!startChoice.textureActive.loadFromFile(("DATA/MISC/starta.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight))){
		//error...
	}
	startChoice.sprite.setTexture(startChoice.texture);
	startChoice.active = false;
	choices.push_back(&startChoice);

	//ManageGame
	if (!manageDeckChoice.texture.loadFromFile(("DATA/MISC/managedeck.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight)) ||
		!manageDeckChoice.textureActive.loadFromFile(("DATA/MISC/managedecka.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight))){
		//error...
	}
	manageDeckChoice.sprite.setTexture(manageDeckChoice.texture);
	manageDeckChoice.active = false;
	choices.push_back(&manageDeckChoice);
	//Options
	if (!optionsChoice.texture.loadFromFile(("DATA/MISC/options.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight)) ||
		!optionsChoice.textureActive.loadFromFile(("DATA/MISC/optionsa.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight))){
		//error...
	}
	optionsChoice.sprite.setTexture(optionsChoice.texture);
	choices.push_back(&optionsChoice);
	//Exit Game
	if (!exitChoice.texture.loadFromFile(("DATA/MISC/exit.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight)) ||
		!exitChoice.textureActive.loadFromFile(("DATA/MISC/exita.png"), sf::IntRect(0, 0, choiceWidth, choiceHeight))){
		//error...
	}
	exitChoice.sprite.setTexture(exitChoice.texture);
	choices.push_back(&exitChoice);
	//Set positions
	for (unsigned int i = 0; i < choices.size(); i++){
		choices[i]->sprite.setPosition(sf::Vector2f(450, 400 + i * (choiceHeight + 10)));
	}
}
Splash::~Splash(){

}