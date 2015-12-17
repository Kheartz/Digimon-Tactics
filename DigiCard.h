#pragma once
#include "Card.h"
#include "stdafx.h"

class DigiCard : public Card
{
private:
	int HP;
	string rank; //Child; Adult; Perfect
	string type; //Plant
	string attribute; //Vaccine; Data; Virus
public:
	DigiCard(string idx);
	~DigiCard();

	int getHP(){ return HP; }
	string getRank(){ return rank; }
	string getType(){ return type; }
	string getAttribute(){ return attribute; }

};

class SupportCard : public Card
{
private:
	int HP;
	string rank; //Child; Adult; Perfect
	string type; //Plant
	string attribute; //Vaccine; Data; Virus
public:
	SupportCard(string idx);
	~SupportCard();

	int getHP(){ return HP; }
	string getRank(){ return rank; }
	string getType(){ return type; }
	string getAttribute(){ return attribute; }
};