
#ifndef NEIGHBOUR_H_
#define NEIGHBOUR_H_

#include<iostream>
#include<vector>
#include <stdlib.h>

using namespace std;

class NeighbourCell {

public:
	int pipCount;

	int left;
	int right;
	int up ;
	int down;

	vector<pos> capturelist;

	NeighbourCell(int left, int right, int up, int down, pos p){
		this->left = left;
		this->right = right;
		this->up = up;
		this->down = down;
		this->pipCount = 0;

		if(range(1,5,abs(right))) {
			capturelist.push_back(pos(p.row,p.col + 1));
			pipCount += abs(right);
		}

		if(range(1,5,abs(left))) {
			capturelist.push_back(pos(p.row,p.col - 1));
			pipCount += abs(left);
		}

		if(range(1,5,abs(up))) {
			capturelist.push_back(pos(p.row - 1,p.col));
			pipCount += abs(up);
		}

		if(range(1,5,abs(down))) {
			capturelist.push_back(pos(p.row + 1,p.col));
			pipCount += abs(down);
		}


	}

	NeighbourCell() {
		left = 0;
		right = 0;
		up = 0;
		down = 0;
		pipCount = 0;
	}

	void display() {
		cout << "up " << up << endl;
		cout << "down " << down << endl;
		cout << "left " << left << endl;
		cout << "right " << right << endl;
		cout << "pipCount " << pipCount << endl;
	}

	bool range(int low, int high, int number) {
		if(low <= number && number <= high) {
			return true;
		}
		else {
			return false;
		}
	}

};



#endif /* NEIGHBOUR_H_ */
