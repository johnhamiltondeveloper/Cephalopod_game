
#ifndef POS_H_
#define POS_H_
#include<iostream>
using namespace std;

class pos {

public:

	int row;
	int col;
	int Heuristic;

	pos(int row, int col) {
		this->row = row;
		this->col = col;
		this->Heuristic = 0;
	}

	pos(int row, int col, double Heuristic)
	{
		this->row = row;
		this->col = col;
		this->Heuristic = Heuristic;
	}

	pos() {
		this->row = 0;
		this->col = 0;
		this->Heuristic = 0;
	}

	pos(const pos& old_pos) {
		this->row = old_pos.row;
		this->col = old_pos.col;
		this->Heuristic = old_pos.Heuristic;
	}

	bool operator<(const pos& other) const {
		if (this->Heuristic > other.Heuristic) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const pos& other) const {
		if(row == other.row && col == other.col) {
			return true;
		}

		return false;
	}

	int id(){
		return ((row*10)+col);
	}

	void print() {
		cout << row << " " << col << endl;
	}

};

#endif /* POS_H_ */
