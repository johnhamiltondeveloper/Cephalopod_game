
#include <iostream>
#include "bored.h"
#include "PlayerManager.h"
#include "HumanPlayer.h"
#include "display.h"
#include "string"

using namespace std;

int main() {

	int BoredRow;
	int Boredcol;
	int BoredIn;

	cout << "White = 1 Black = -1" << endl;

	cout << "1. 3x3" << endl;
	cout << "2. 3x5" << endl;
	cout << "3. 5x5" << endl;

	cout << "Bored Size:";
	cin >> BoredIn;

	if(BoredIn == 1){BoredRow = 3; Boredcol = 3;}
	if(BoredIn == 2){BoredRow = 3; Boredcol = 5;}
	if(BoredIn == 3){BoredRow = 5; Boredcol = 5;}

	bored b(BoredRow,Boredcol);

	display d;
	PlayerManager p;

	b.display();

	do {

		cout << p.get_player_name(p.get_player_index()) << " Players move: symbol = " << p.get_player_index() << endl;

		pos temp = p.get_move(b,p.playerIndex);

		if(b.isvalid(temp)) {

			b.add(temp,p.get_player_index());
			p.swap();
		}
		else {
			d.MessageBadInput();
		}

		b.display();

	}

	while(b.full());

	b.display();
	cout << "The " << p.get_player_name(b.Status()) << " player wins the game" << endl;

}
