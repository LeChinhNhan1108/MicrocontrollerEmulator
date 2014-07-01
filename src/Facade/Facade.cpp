/*
 * Facade.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#include "Facade.h"

using namespace std;

void connectToMicrocontroller() {
	cout << "Hello" << endl;
}


void displayHelp() {
	int width1 = 4;
	int width2 = 50;
	cout << "---------------------------------------------------" << endl;
	cout << setw(width1) << left << "c" << setw(width2) << left << "# connect to micro-controller ('create')" << endl;
	cout << setw(width1) << left << "d" << setw(width2) << left << "# display all memory" << endl;
	cout << setw(width1) << left << "e" << setw(width2) << left << "# execute from current PC" << endl;
	cout << setw(width1) << left << "g" << setw(width2) << left << "# execute from specific location ('go')" << endl;
	cout << setw(width1) << left << "h" << setw(width2) << left << "# display help" << endl;
	cout << setw(width1) << left << "l" << setw(width2) << left << "# look at memory" << endl;
	cout << setw(width1) << left << "m" << setw(width2) << left << "# modify memory" << endl;
	cout << setw(width1) << left << "r" << setw(width2) << left << "# reset micro-controller" << endl;
	cout << setw(width1) << left << "s" << setw(width2) << left << "# display PC and register ('status')" << endl;
	cout << setw(width1) << left << "q" << setw(width2) << left << "# quit the program" << endl;
	cout << "---------------------------------------------------" << endl;

}
