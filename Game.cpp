#include "Game.h"

void Game::init()
{
	//Set Gamestate to splash
	_gs = GAMESTATE::SPLASH;
	//Random Number Generator
	srand((unsigned int)time(NULL));
	//Create window. Set for no ability to resize.
	mainWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Digimon Tactics CCG", sf::Style::Close);

	//sf::Music music;
	/*if (!music.openFromFile("music.ogg"))
	{

	}
	music.play();
	*/


}

void Game::run(){

	
	playerMat->addToDigimonRow(new DigiCard("001"));//Adding Agumon for test 
	playerMat->addToDigimonRow(new DigiCard("003"));
	playerMat->addToDigimonRow(new DigiCard("007"));
	playerMat->addToDigimonRow(new DigiCard("009"));
	playerMat->addToDigimonRow(new DigiCard("053"));
	playerMat->addToSupportRow(new SupportCard("133"));
	playerMat->addToSupportRow(new SupportCard("146"));
	playerMat->addToSupportRow(new SupportCard("173"));
	playerMat->addToSupportRow(new SupportCard("216"));
	playerMat->addToSupportRow(new SupportCard("232"));
	//DigiCard Agumon("001");

	//Main loop while window is active
	while (mainWindow->isOpen()){
		//Check for events on window
		while (mainWindow->pollEvent(event)){
			//Check for close event
			if (event.type == sf::Event::Closed)
				mainWindow->close();
			switch (_gs){
			case GAMESTATE::SPLASH: 
				pollInputSplash(event);
				break;
			case GAMESTATE::OPTIONS:
				pollInputOptions(event);
				break;
			case GAMESTATE::GAME:
				pollInputGame(event);
				break;
			}
		}
		//Perform Updates
		switch (_gs){
		case GAMESTATE::SPLASH:
			updateSplash();
			break;
		case GAMESTATE::OPTIONS:
			updateOptions();
			break;
		case GAMESTATE::GAME:
			updateGame();
			break;
		}
		//Clear the buffer
		mainWindow->clear();
		//Draw Sprites
		switch (_gs){
		case GAMESTATE::SPLASH:
			drawSplash();
			break;
		case GAMESTATE::OPTIONS:
			drawOptions();
			break;
		case GAMESTATE::GAME:
			drawGame();
			break;
		}
		//drawGame();
		//Display
		mainWindow->display();
	}
	
	//Exit game
	return;
}

Game::Game()
{
	//playerMat = new Mat(0, 0, false);
	playerMat = new Mat(SCREEN_WIDTH, SCREEN_HEIGHT, true);
	enemyMat = new Mat(SCREEN_WIDTH, SCREEN_HEIGHT, true);
}
Game::~Game()
{
	if (playerMat != NULL)
		delete playerMat;
	if (mainWindow != NULL)
		delete mainWindow;
}

void Game::pollInputSplash(sf::Event& event){
	for (auto choices : splash.getChoices()){
		choices->active = false;
		choices->sprite.setTexture(choices->texture);
		if (sf::Mouse::getPosition(*mainWindow).x > choices->sprite.getPosition().x &&
			sf::Mouse::getPosition(*mainWindow).x < choices->sprite.getPosition().x + choices->sprite.getTextureRect().width &&
			sf::Mouse::getPosition(*mainWindow).y > choices->sprite.getPosition().y &&
			sf::Mouse::getPosition(*mainWindow).y < choices->sprite.getPosition().y + choices->sprite.getTextureRect().height)
			choices->active = true;
	}
}
void Game::pollInputGame(sf::Event& event){

}
void Game::pollInputOptions(sf::Event& event){

}
void Game::updateSplash(){
	for (auto choices : splash.getChoices()){
		if (choices->active){
			choices->sprite.setTexture(choices->textureActive);
		}
	}
}
void Game::updateGame(){
}
void Game::updateOptions(){

}
void Game::drawSplash(){
	mainWindow->draw(splash.getBGSprite());
	for (auto choices : splash.getChoices()){
		mainWindow->draw(choices->sprite);
	}
}
void Game::drawGame(){
	//draw Mat
	mainWindow->draw(playerMat->getMatSprite());
	mainWindow->draw(playerMat->getDeckSprite());
	for (auto digimon : playerMat->getDigimonRow()){
		mainWindow->draw(digimon->getSSprite());
	}
	for (auto support : playerMat->getSupportRow()){
		mainWindow->draw(support->getSSprite());
	}
}
void Game::drawOptions(){
}