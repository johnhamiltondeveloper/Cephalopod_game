
#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "player.h"
#include <iostream>
#include "pos.h"
#include "display.h"
#include "RandomPlayer.h"

using namespace std;

class HumanPlayer : public player {

public:

	display display;

	virtual pos get_input(bored& b, int player) {

		display.MessageAskInput();

		pos move;
		cin >> move.row;
		cin >> move.col;
		move.row--;
		move.col--;


		return move;

	}


};



#endif /* HUMANPLAYER_H_ */
