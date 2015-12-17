#pragma once
#include "stdafx.h"
using namespace std;

struct PEER{
	string name; //Name
	int sessionID; //Each peer given one during entrance
	int elo; //Matchmaking ranking
};
class Lobby{
private:
	sf::TcpSocket lobbySocket;
	sf::Socket::Status lobbySocketStatus;
	sf::IpAddress lobbyIP;
	unsigned short lobbyPort;

	bool connected;
public:
	Lobby();
	~Lobby();

	void connect();

};