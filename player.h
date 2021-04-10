
#ifndef PLAYER_H_
#define PLAYER_H_

#include "pos.h"
#include<iostream>

class player {

public:

	player() {

	}

	virtual pos get_input(bored& b,int player) = 0;

	virtual ~player() {

	}

};



#endif /* PLAYER_H_ */
