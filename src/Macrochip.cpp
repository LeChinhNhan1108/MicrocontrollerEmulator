/*
 * Macrochip.cpp
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#include "Macrochip.h"

void Macrochip::reset() {
	cout << "Macrochip reset " << endl;
}

void Macrochip::execute(int location) {
	unsigned char opcode = *(getMemory() + location);
	switch (opcode) {
	case MOVE_TO_W:
		moveToW(location);
		break;
	case MOVE_TO_MEM:
		moveWToMemory(location);
		break;
	case ADD_TO_W:
		addToW(location);
		break;
	case SUBSTRACT_FROM_W:
		substractFromW(location);
		break;
	case ALWAYS_BRANCH:
		alwaysBranch(location);
		break;
	case BRANCH_NOT_EQUAL:
		branchNotEqual(location);
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

void Macrochip::moveToW(int location) {

	if (location + 2 > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setW(*(getMemory() + location + 1));
	setPC(location + 2);
	execute(getPC());
}
void Macrochip::moveWToMemory(int location) {

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

	*(getMemory() + address) = getW();

	setPC(destination);
	execute(getPC());
}
void Macrochip::addToW(int location) {
	int destination = location + 2;
	if (destination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int value = *(getMemory() + location + 1);
	int result = getW() + value;

	if (result >= 256)
		result -= 256;

	setW(result);

	setPC(destination);
	execute(getPC());

}
void Macrochip::substractFromW(int location) {
	int destination = location + 2;
	if (destination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int value = *(getMemory() + location + 1);
	int result = getW() - value;

	if (result < 0)
		result = 0;

	setW(result);

	setPC(destination);
	execute(getPC());

}
void Macrochip::alwaysBranch(int location) {

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
void Macrochip::branchNotEqual(int location) {

	int comparision = *(getMemory() + location + 1);

	int high = *(getMemory() + location + 2);
	int low = *(getMemory() + location + 3);

	int address = (high << 8) | low;

	int finalDestination = (getW() != comparision) ? address : (location + 4);

	if (finalDestination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	setPC(address);
	execute(getPC());
}

void Macrochip::halt(int location) {
	cout << "Program halted" << endl;
}
