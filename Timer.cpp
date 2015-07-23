#include "Timer.h"

Timer::Timer()
{
	startTicks = 0;
	pausedTicks = 0;

	bPaused = false;
	bStarted = false;
}

void Timer::start(){

	bStarted = true;
	bPaused = false;

	startTicks = clock.getElapsedTime().asMilliseconds();
}

void Timer::stop(){
	bStarted = false;

	bPaused = false;
}

void Timer::pause(){
	if (bStarted && !bPaused){
		bPaused = true;
		pausedTicks = clock.getElapsedTime().asMilliseconds() - startTicks;
	}
}

void Timer::unpause(){
	if (bPaused){
		bPaused = false;
		startTicks = clock.getElapsedTime().asMilliseconds() - pausedTicks;
	}
}

int Timer::get_ticks(){
	if (bStarted){
		if (bPaused)
			return pausedTicks;
		else
			return clock.getElapsedTime().asMilliseconds() - startTicks;
	}
	return 0;
}