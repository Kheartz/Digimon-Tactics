#pragma once

class Match{
private:
	enum PHASE{
		P1DRAW,
		P2DRAW
	};
public:
	Match();
	~Match();
	void update();
};