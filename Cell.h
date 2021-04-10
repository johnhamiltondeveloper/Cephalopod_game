#ifndef CELL_H_
#define CELL_H_

class Cell {

public:
	int playerIndex;
	int DiceNumber;

	Cell(int player,int number) {
		playerIndex = player;
		DiceNumber = number;
	}

	Cell() {
		playerIndex = -1;
		DiceNumber = 0;
	}


};



#endif /* CELL_H_ */
