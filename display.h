#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>

using namespace std;

class display {
public:

	display() {

	}

	void MessageBadInput() {
		cout << "##### This is not a valid input #####" << endl;
	}

	void MessageAskInput() {
		cout << "enter row and column:" << endl;
	}

};



#endif /* DISPLAY_H_ */
