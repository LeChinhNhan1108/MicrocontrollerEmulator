/*
 * Rotamola.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: root
 */

#include "Rotamola.h"

void Rotamola::reset() {
	setPC(509);
}

void Rotamola::execute(int location) {

	unsigned char opcode = *(getMemory() + location);

	switch (opcode) {
	case MOVE_A_TO_MEM:
		moveAToMem(location);
		break;
	case LOAD_A:
		loadA(location);
		break;
	case LOAD_B:
		loadB(location);
		break;
	case INCREASE_A:
		increaseA(location);
		break;
	case ALWAYS_BRANCH:
		alwaysBranch(location);
		break;
	case BRANCH_IF_A_LESS_THAN_B:
		branchIfALessThanB(location);
		break;
	case BRANCH_IF_LESS_THAN_A:
		branchIfLessThanA(location);
		break;
	case HALT:
		halt(location);
		break;
	default:
		cerr << "No opcode exist at 0x" + convertIntToHexString(location)
				<< endl;
		break;
	}

}

void Rotamola::moveAToMem(int location) {
	int destination = location + 3;
	if (destination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int high = *(getMemory() + location + 1);
	int low = *(getMemory() + location + 2);

	int address = (high << 8 | low);
	if (address > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	*(getMemory() + address) = getA();

	setPC(destination);
	execute(getPC());

}
void Rotamola::loadA(int location) {
	if (location + 2 > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setA(*(getMemory() + location + 1));
	setPC(location + 2);
	execute(getPC());
}
void Rotamola::loadB(int location) {
	if (location + 2 > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setB(*(getMemory() + location + 1));
	setPC(location + 2);
	execute(getPC());

}
void Rotamola::increaseA(int location) {
	if (location + 1 > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int currentA = getA();
	int result = currentA + 1;

	if (result > 255)
		result = 0;

	setA(result);
	setPC(location + 1);
	execute(getPC());

}
void Rotamola::alwaysBranch(int location) {
	if (location + 2 > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int high = *(getMemory() + location + 1);
	int low = *(getMemory() + location + 2);

	int address = (high << 8 | low);
	if (address > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setPC(address);
	execute(getPC());
}
void Rotamola::branchIfALessThanB(int location) {

	int high = *(getMemory() + location + 1);
	int low = *(getMemory() + location + 2);

	int address = (high << 8) | low;

	int finalDestination = (getA() < getB()) ? address : (location + 3);

	if (finalDestination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setPC(address);
	execute(getPC());
}
void Rotamola::branchIfLessThanA(int location) {

	int comparision = *(getMemory() + location + 1);

	int high = *(getMemory() + location + 2);
	int low = *(getMemory() + location + 3);

	int address = (high << 8) | low;

	int finalDestination = (comparision < getA()) ? address : (location + 4);

	if (finalDestination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setPC(address);
	execute(getPC());
}
void Rotamola::halt(int location) {
	cout << "Program halted" << endl;
}


void Rotamola::writeToFile(){
	cout << "Rotamola write file " << endl;
}

void Rotamola::readFromFile(){
	cout << "Rotamola read file " << endl;
}



