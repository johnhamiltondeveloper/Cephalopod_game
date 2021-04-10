
#ifndef PLAYERMANAGER_H_
#define PLAYERMANAGER_H_

#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include <string>

#include "player.h"
#include "bored.h"
#include "pos.h"
#include "display.h"
#include "bored.h"
#include"MonteCarloPlayer.h"

class PlayerManager {

private:

	enum {human,smartAi};
	player **players;

public:

	int playerIndex;

	PlayerManager() {

		players = new player*[2];

		cout << "1: Player Vs Player" << endl;
		cout << "2: Player Vs MonteCarlo" << endl;
		cout << "3: Random Vs MonteCarlo" << endl;
		cout << "4: Random Vs Player" << endl;
		cout << "5: Random Vs Random" << endl;

		cout << "enter Mode: ";

		int playmode;

		cin >> playmode;

		if(playmode == 1) {
			players[0] = new HumanPlayer;
			players[1] = new HumanPlayer;
		}

		if(playmode == 2) {
			players[0] = new HumanPlayer;
			players[1] = new MonteCarloPlayer;
		}

		if(playmode == 3) {
			players[0] = new RandomPlayer;
			players[1] = new MonteCarloPlayer;

		}

		if(playmode == 4) {
			players[0] = new RandomPlayer;
			players[1] = new HumanPlayer;

		}

		if(playmode == 5) {
			players[0] = new RandomPlayer;
			players[1] = new RandomPlayer;

		}

		playerIndex = false;
	}

	pos get_move(bored& b,int player) {
		return players[player]->get_input(b,get_player_index());
	}

	int get_player_index() {
		if (playerIndex) {
			return 1;
		}
		else {
			return -1;
		}
	}

	void swap() {
		playerIndex = !playerIndex;
	}

	string get_player_name(int player) {
		if (player == 1) {
			return "White";
		}

		if (player == -1)
		{
			return "Black";
		}
	}

};



#endif /* PLAYERMANAGER_H_ */
