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

};