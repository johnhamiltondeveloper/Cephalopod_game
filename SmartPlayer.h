#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

#include "player.h"
#include <iostream>
#include "pos.h"
#include "display.h"
#include "RandomPlayer.h"

using namespace std;

class SmartPlayer : public player {

public:

	display display;

	virtual pos get_input(bored& b, int player) {

		for(pos index : b.get_available_moves()) {

		}

	}


};

#endif /* SMARTPLAYER_H_ */
