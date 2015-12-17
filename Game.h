#pragma once
#include "DigiCard.h"
#include "Mat.h"
#include "Splash.h"
#include "Lobby.h"

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
		MANAGEDECK,
		OPTIONS
	};
	GAMESTATE _gs;
	sf::Event event;
	Splash splash;
	Lobby clientLobby;
	bool matchStarted;
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
	Mat* getEnemyMat(){ return enemyMat; }


	/*****STATE FUNCTIONS*****/
	//Poll Inputs/Events
	void pollInputSplash(sf::Event& event);
	void pollInputGame(sf::Event& event);
	void pollInputOptions(sf::Event& event);
	void pollInputManageDeck(sf::Event& event);
	//Update Current GAMESTATE
	void updateSplash();
	void updateGame();
	void updateOptions();
	void updateManageDeck();
	//Update Draw
	void drawSplash();
	void drawGame();
	void drawOptions();
	void drawManageDeck();



	void load();
	void save();

};