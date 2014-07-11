//============================================================================
// Name        : MicrocontrollerEmulator.cpp
// Author      : Le Nhan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Facade.h"

int main() {

	Microcontroller* mcontroller;
	cout << "Microcontroller Emulator. Connect (c) or show help (h) " << endl;
	char input = 's';

	while (input != 'q') {
		cout << "> ";
		cin >> input;
		clearCin();

		input = convertToLowerCase(input);

		switch (input) {
		case 'c':
			mcontroller = connectToMicrocontroller();
			break;
		case 'd':
			break;
		case 'e':
			break;
		case 'g':
			break;
		case 'h':
			displayHelp();
			break;
		case 'l':
			break;
		case 'm':
			break;
		case 'r':
			reset(mcontroller);
			break;
		case 's':
			break;
		case 'q':
			cout << "Bye Bye Bye " << endl;
			break;
		default:
			cerr << "Wrong command. Try again " << (int)input << endl;
			break;
		}
	}

	return 0;
}
