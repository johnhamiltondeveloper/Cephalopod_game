
#ifndef MONTECARLOPLAYER_H_
#define MONTECARLOPLAYER_H_

#include "player.h"
#include<iostream>
#include "pos.h"
#include "bored.h"
#include<queue>

using namespace std;

const int simulateCount = 50;

class MonteCarloPlayer : public player {

public:

	int Player;

	virtual pos get_input(bored& b,int IN_Player) {

		this->Player = IN_Player;
		priority_queue<pos> moves;

		for(pos index : b.get_available_moves()) {
			bored tempBored(b);

			tempBored.add(index,Player);
			int utility = simulate(tempBored);
			moves.push(pos(index.row,index.col,utility));


		}

		return moves.top();

	}

	double simulate(bored b) {

		int wins = 0;

		for(int i = 0; i < simulateCount; i++) {
			bored TempBored(b);
			wins += simulateGame(TempBored,0-Player);
		}

		return ((double) wins / (double) simulateCount);


	}

	int simulateGame(bored b,int p) {

		if(b.Status() == Player) {
			return 1;
		}

		if(b.Status() == 0-Player){
			return -1;
		}

		if(b.Status() == 0) {
			cout << b.get_available_moves().size() << endl;
			b.add(b.get_rand_pos(),p);
			return simulateGame(b,0-p);
		}

	}


};

#endif /* MONTECARLOPLAYER_H_ */
