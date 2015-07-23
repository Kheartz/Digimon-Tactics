#pragma once
#include "DigiCard.h"
#include "Mat.h"
#include "Splash.h"

class Game
{
private:
	/*****WINDOW*****/
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 800;
	sf::RenderWindow* mainWindow;
	Mat* playerMat;
	Mat* enemyMat;
	/*****TECHNICAL*****/
	enum GAMESTATE{
		SPLASH,
		GAME,
		OPTIONS
	};
	GAMESTATE _gs;
	sf::Event event;
	Splash splash;
	/*****CONFIGURATIONS*****/
	int musicVolume;
	int soundEffVolume;
	bool bFullscreen;
	/*****PERSONALS*****/
	string playerName;
	int rank;
public:
	Game();
	~Game();
	void init();
	void run();
	
	Mat* getPlayerMat() { return playerMat; }


	/*****STATE FUNCTIONS*****/
	//Poll Inputs/Events
	void pollInputSplash(sf::Event& event);
	void pollInputGame(sf::Event& event);
	void pollInputOptions(sf::Event& event);
	//Update Current GAMESTATE
	void updateSplash();
	void updateGame();
	void updateOptions();
	//Update Draw
	void drawSplash();
	void drawGame();
	void drawOptions();



	void load();
	void save();

};