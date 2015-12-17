#include "Lobby.h"

Lobby::Lobby(){
	connected = false;
	//lobbyIP = "67.194.239.188";
	lobbyIP = "127.0.0.1";
	lobbyPort = 53000;
	lobbySocket.setBlocking(false);
}
Lobby::~Lobby(){
}

void Lobby::connect(){

	sf::Packet testPacket;
	string digiName = "Veemon";
	sf::Uint16 veemonHealth = 500;
	float veeFloat = 12.455;

	testPacket << digiName << veemonHealth << veeFloat;
	while (!connected){
		testPacket << digiName << veemonHealth << veeFloat;
		lobbySocket.send(testPacket);
		lobbySocketStatus = lobbySocket.connect(lobbyIP, lobbyPort);
		if (lobbySocketStatus != sf::Socket::Done)
		{
		}
		else{
			connected = true;
			cout << "CONNECTED!" << endl;
			
		}
	}
}