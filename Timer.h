#pragma once

class Timer{
private:
	int startTicks;

	int pausedTicks;

	bool bPaused;
	bool bStarted;

	sf::Clock clock;

public:

	Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	int get_ticks();

	bool isPaused(){ return bPaused; }
	bool isStarted(){ return bStarted; }


};