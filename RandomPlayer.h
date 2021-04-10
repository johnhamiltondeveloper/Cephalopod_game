
#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include "player.h"
#include<iostream>
#include "pos.h"
#include "display.h"
#include "bored.h"

class RandomPlayer : public player {

public:

	display display;

	virtual pos get_input(bored& b, int player) {

		pos temp = b.get_rand_pos();
		return temp;

	}


};


#endif /* RANDOMPLAYER_H_ */
