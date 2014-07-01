//============================================================================
// Name        : MicrocontrollerEmulator.cpp
// Author      : Le Nhan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Facade/Facade.h"

int main() {
	cout << "Microcontroller Emulator. Connect (c) or show help (h) " << endl;
	char input = 's';

	while (input != 'q') {
		cout << "> ";
		cin >> input;
		input = convertToLowerCase(input);

		switch (input) {
		case 'c':
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
			break;
		case 's':
			break;
		case 'q':
			cout << "Bye Bye Bye " << endl;
			break;
		default:
			cerr << "Wrong command. Try again" << endl;
			break;
		}
	}

	return 0;
}
