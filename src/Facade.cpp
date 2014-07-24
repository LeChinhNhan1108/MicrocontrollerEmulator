/*
 * Facade.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#include "Facade.h"

using namespace std;

Microcontroller* connectToMicrocontroller() {
	cout << "Choose micro-controller:\n" << "\t-R500\n" << "\t-PIC32F42\n"
			<< "\t-34HC22\n" << endl;
	cout << "type? ";

	bool valid = false;
	string micro_type;

	while (!valid) {

		getline(cin, micro_type);
		convertToLowerCase(micro_type);
		valid = true;

		if (micro_type == "r500") {
			cout << "R500 selected" << endl;
			return new Mops;
		} else if (micro_type == "pic32f42") {
			cout << "PIC32F42 selected" << endl;
			return new Macrochip;
		} else if (micro_type == "34hc22") {
			cout << "34HC22 selected" << endl;
			return new Rotamola;
		} else {
			valid = false;
			cout << "Invalid input. Please try again" << endl;
			return NULL;
		}
	}
	return NULL;

}

void displayAllMemory(Microcontroller& mcontroller) {
	unsigned char* memory = mcontroller.getMemory();

	for (int i = 0; i < mcontroller.getSize(); i += 16) {
		if (i % 16 == 0) {
			cout << setw(4) << setfill('0') << right << convertIntToHexString(i) << "  ";
			for (int j = 0; j < 16; j++) {
				cout << setw(2) << setfill('0') << right
						<< convertIntToHexString(*(memory + i + j)) << " ";
				if (j == 7)
					cout << " ";
			}
			cout << endl;
		}
	}

}
void executeFromCurrentPC(Microcontroller& mcontroller) {
	executeFromLocation(mcontroller, mcontroller.getPC());
}
void executeFromLocation(Microcontroller& mcontroller, int location) {
	if (location == -1) {
		cout << "location? ";
		string input;
		getline(cin, input);
		location = convertHexToInt(input);
	}

	if (location == -1) {
		cerr << "Invalid input" << endl;
		return;
	}
	mcontroller.execute(location);
}
void displayHelp() {
	int width1 = 4;
	int width2 = 50;
	cout << "---------------------------------------------------" << endl;
	cout << setw(width1) << setfill(' ') << left << "c" << setw(width2) << left
			<< "# connect to micro-controller ('create')" << endl;
	cout << setw(width1) << left << "d" << setw(width2) << left
			<< "# display all memory" << endl;
	cout << setw(width1) << left << "e" << setw(width2) << left
			<< "# execute from current PC" << endl;
	cout << setw(width1) << left << "g" << setw(width2) << left
			<< "# execute from specific location ('go')" << endl;
	cout << setw(width1) << left << "h" << setw(width2) << left
			<< "# display help" << endl;
	cout << setw(width1) << left << "l" << setw(width2) << left
			<< "# look at memory" << endl;
	cout << setw(width1) << left << "m" << setw(width2) << left
			<< "# modify memory" << endl;
	cout << setw(width1) << left << "r" << setw(width2) << left
			<< "# reset micro-controller" << endl;
	cout << setw(width1) << left << "s" << setw(width2) << left
			<< "# display PC and register ('status')" << endl;
	cout << setw(width1) << left << "w" << setw(width2) << left
				<< "# save the micro controller to file" << endl;
	cout << setw(width1) << left << "z" << setw(width2) << left
				<< "# load the micro controller to program" << endl;
	cout << setw(width1) << left << "q" << setw(width2) << left
			<< "# quit the program" << endl;
	cout << "---------------------------------------------------" << endl;

}
void lookAtMemory(Microcontroller& mcontroller) {
	string input;
	cout << "location? ";
	getline(cin, input);

	int location = convertHexToInt(input);

	if (location == -1 || location < 0 || location > mcontroller.getSize()) {
		cerr << "Invalid input" << endl;
		return;
	}

	cout << "Value " << "0x"
			<< convertIntToHexString(
					(int) *(mcontroller.getMemory() + location)) << endl;
}
void modifyMemory(Microcontroller& mcontroller) {
	string input;
	cout << "location? ";
	getline(cin, input);

	int location = convertHexToInt(input);

	if (location == -1 || location < 0 || location > mcontroller.getSize()) {
		cerr << "Invalid input" << endl;
		return;
	}

	cout << "Old value " << "0x"
			<< convertIntToHexString(
					(int) *(mcontroller.getMemory() + location)) << endl;

	cout << "new? ";
	string data;
	getline(cin, data);

	int value = convertHexToInt(data);
	if (value == -1) {
		cerr << "Invalid input" << endl;
	} else {
		*(mcontroller.getMemory() + location) = value;
	}
}
void reset(Microcontroller& mcontroller) {
	mcontroller.reset();
}
void displayPCAndRegister(Microcontroller& mcontroller) {

	Macrochip* macro = dynamic_cast<Macrochip*>(&mcontroller);
	Rotamola* rotamola = dynamic_cast<Rotamola*>(&mcontroller);

	if (macro != NULL) {
		cout << mcontroller.getStatusString() << " -- Register W Value 0x"
				<< convertIntToHexString(macro->getW()) << endl;
	} else if (rotamola != NULL) {
		cout << mcontroller.getStatusString() << " -- Register A Value 0x"
				<< convertIntToHexString(rotamola->getA())
				<< " -- Register B Value 0x"
				<< convertIntToHexString(rotamola->getB()) << endl;
	} else {
		cout << mcontroller.getStatusString() << endl;
	}

}

void writeToFile(Microcontroller& mcontroller) {
	mcontroller.writeToFile();
}

void readFromFile(Microcontroller& mcontroller) {
	mcontroller.readFromFile();
}

