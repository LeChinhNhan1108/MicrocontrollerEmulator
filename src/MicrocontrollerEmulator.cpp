//============================================================================
// Name        : MicrocontrollerEmulator.cpp
// Author      : Le Nhan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Facade.h"

int main() {

	Microcontroller* mcontroller = NULL;
	cout << "Microcontroller Emulator. Connect (c) or show help (h) " << endl;
	char input = 's';

	while (input != 'q') {
		cout << "> ";
		cin >> input;
		clearCin();

		input = convertToLowerCase(input);

		switch (input) {
		case 'c':
			if (mcontroller != NULL)
				delete mcontroller;
			mcontroller = connectToMicrocontroller();
			break;
		case 'd':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				displayAllMemory(*mcontroller);
			break;
		case 'e':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				executeFromCurrentPC(*mcontroller);
			break;
		case 'g':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				executeFromLocation(*mcontroller, -1);
			break;
		case 'h':
			displayHelp();
			break;
		case 'l':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				lookAtMemory(*mcontroller);
			break;
		case 'm':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				modifyMemory(*mcontroller);
			break;
		case 'r':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				reset(*mcontroller);
			break;
		case 's':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				displayPCAndRegister(*mcontroller);
			break;
		case 'q':
			break;
		case 'w':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				writeToFile(*mcontroller);
			break;
		case 'z':
			if (mcontroller == NULL)
				cerr << "Micro controller is not connected" << endl;
			else
				readFromFile(*mcontroller);
			break;
		default:
			cerr << "Wrong command. Try again " << endl;
			break;
		}
	}
	delete mcontroller;
	cout << "End Program" << endl;
	return 0;
}
