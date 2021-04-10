#ifndef BORED_H_
#define BORED_H_

#include "pos.h"
#include "Neighbour.h"
#include <stdlib.h>
#include <time.h>

#include<unordered_map>
#include<vector>
#include<list>
#include<Iterator>
#include<vector>

using namespace std;

class bored {

private:

	int **BoredData;
	int row;
	int col;

	list<pos> AvailableMoves;
	list<pos>::iterator it;

	vector<int> PosLeft;

public:

	unordered_map<int, NeighbourCell> Neighbours;

	bored(int row, int col) {

		srand(time(NULL));

		this->row = row;
		this->col = col;

		BoredData = new int*[row];

		for (int i = 0; i < row; i++) {
			BoredData[i] = new int[col];
		}

		for (int Irow = 0; Irow < row; Irow++) {

			for (int Icol = 0; Icol < col; Icol++) {

				BoredData[Irow][Icol] = 0;

				Neighbours[pos(Irow, Icol).id()] = NeighbourCell();

				AvailableMoves.push_back(pos(Irow, Icol));

			}
		}

	}

	bored(const bored &other) {
		this->AvailableMoves = other.AvailableMoves;
		this->col = other.col;
		this->row = other.row;

		BoredData = new int*[row];

		for (int i = 0; i < row; i++) {
			BoredData[i] = new int[col];
		}

		for (int i_row = 0; i_row < row; i_row++) {
			for (int i_col = 0; i_col < col; i_col++) {
				this->BoredData[i_row][i_col] = other.BoredData[i_row][i_col];
			}
		}
	}

	void add(pos p, int player) {

		Neighbours[pos(p.row, p.col).id()] = make_Neighbour(pos(p.row, p.col));

		if (Neighbours[pos(p.row, p.col).id()].capturelist.size() >= 2) {


			for (int i = 0;
					i < Neighbours[pos(p.row, p.col).id()].capturelist.size();
					i++) {

				remove(Neighbours[pos(p.row, p.col).id()].capturelist[i]);
			}

		}


		int pipcount = Neighbours[pos(p.row, p.col).id()].pipCount;

		int number = 1;

		if (pipcount > 1) {
			if (pipcount <= 6) {
				number = Neighbours[pos(p.row, p.col).id()].pipCount;
			}
		}

		if (pipcount < 1 || pipcount > 6) {
			number = 1;
		}

		if (player == -1) {
			number = 0 - number;
		}

		BoredData[p.row][p.col] = number;

		Neighbours[pos(p.row, p.col).id()].display();

		AvailableMoves.remove(p);
	}

	void remove(pos p) {

		if (indexInRange(p)) {
			BoredData[p.row][p.col] = 0;
			Neighbours[pos(p.row, p.col).id()] = make_Neighbour(
					pos(p.row, p.col));
			AvailableMoves.push_back(p);

		}

		AvailableMoves.unique();
	}

	bool isvalid(pos p) {

		if (indexInRange(p)) {

			if (BoredData[p.row][p.col] == 0) {
				return true;
			}
		}

		return false;
	}

	void display() {

		cout << "    ";
		for (int i = 0; i < col; i++) {
			cout << i + 1 << "   ";
		}

		cout << endl;
		cout << "  ";
		for (int i = 0; i < col; i++) {
			cout << " ---";
		}

		cout << endl;

		for (int Irow = 0; Irow < row; Irow++) {

			cout << Irow + 1 << " | ";
			for (int Icol = 0; Icol < col; Icol++) {

				cout << BoredData[Irow][Icol];

				if (BoredData[Irow][Icol] < 0) {
					cout << "| ";
				} else {
					cout << " | ";
				}

			}
			cout << endl;
			cout << "  ";
			for (int i = 0; i < col; i++) {
				cout << " ---";
			}

			cout << " " << endl;

		}

	}

	pos get_rand_pos() {
		it = AvailableMoves.begin();
		std::advance(it, rand() % AvailableMoves.size());

		pos a = *it;

		return a;
	}

	NeighbourCell make_Neighbour(pos p) {
		int right = 0;
		int left = 0;
		int up = 0;
		int down = 0;

		int r = p.row;
		int c = p.col;

		if (c + 1 < col) {
			right = BoredData[p.row][p.col + 1];
		}

		if (c - 1 >= 0) {
			left = BoredData[p.row][p.col - 1];
		}

		if (r - 1 >= 0) {
			up = BoredData[p.row - 1][p.col];
		}

		if (r + 1 < row)
			down = BoredData[p.row + 1][p.col];

		return NeighbourCell(left, right, up, down, p);

	};

	bool full() {
		if (AvailableMoves.size() > 0) {
			return true;
		}
		return false;
	}

	bool indexInRange(pos p) {

		if (p.row >= 0 && p.col >= 0) {
			if (p.col < col && p.row < row) {
				return true;
			}
		}

		return false;

	}

	int Status() {

		int black = 0;
		int white = 0;

		if (full() == false) {
			for (int Irow = 0; Irow < row; Irow++) {

				for (int Icol = 0; Icol < col; Icol++) {

					//white dice
					if (BoredData[Irow][Icol] < 0) {
						white++;
					}

					// black dice

					if (BoredData[Irow][Icol] > 0) {
						black++;
					}

				}
			}

			if (black > white) {
				return 1;
				//cout << "Black player wins" << endl;
			}

			if (white > black)
			{
				return -1;
				//cout << "White player wins" << endl;
			}

		}

	};

	list<pos> get_available_moves() {
		return AvailableMoves;
	}

};

#endif /* BORED_H_ */
