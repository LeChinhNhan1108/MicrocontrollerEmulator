/*
 * Mops.cpp
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#include "Mops.h"

void Mops::reset() {
	setPC(0);
	memset(getMemory(), 0, getSize());
	cout << "Mops reset successfully" << endl;
}

void Mops::execute(int location) {

	unsigned char opcode = *(getMemory() + location);

	switch (opcode) {
	case ADD:
		add(location);
		break;
	case SUBTRACT:
		substract(location);
		break;
	case ALWAYS_BRANCH:
		alwaysBranch(location);
		break;
	case BRANCH_RELATIVE:
		branchRelative(location);
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

void Mops::add(int location) {
	int destination = location + 4;
	if (destination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int value = *(getMemory() + location + 1);
	int high = *(getMemory() + location + 2);
	int low = *(getMemory() + location + 3);

	int address = (high << 8 | low);
	if (address > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int currentValue = *(getMemory() + address);
	int result = currentValue + value;

	if (result >= 256)
		result -= 256;

	*(getMemory() + address) = result;

	cout << "Add to " << convertIntToHexString(address) << " value " << result << endl;

	setPC(destination);
	execute(getPC());

}

void Mops::substract(int location) {
	int destination = location + 4;
	if (destination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int value = *(getMemory() + location + 1);
	int high = *(getMemory() + location + 2);
	int low = *(getMemory() + location + 3);

	int address = (high << 8 | low);
	if (address > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int currentValue = *(getMemory() + address);
	int result = currentValue - value;

	if (result < 0)
		result = 0;

	*(getMemory() + address) = result;

	cout << "Subtract from " << convertIntToHexString(address) << " value " << result << endl;

	setPC(destination);
	execute(getPC());
}

void Mops::alwaysBranch(int location) {

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

	cout << "Always branch to " << convertIntToHexString(address) << endl;

	setPC(address);
	execute(getPC());
}

void Mops::branchRelative(int location) {

	if (location + 1 > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	int value = *(getMemory() + location + 1);
	if (value >= 128)
		value = value - 256;

	int currentPc = getPC();
	if (currentPc + value > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

	cout << "Branch relative to " << convertIntToHexString(currentPc + value) << endl;

	setPC(currentPc + value);
	execute(getPC());
}

void Mops::halt(int location) {
	cout << "Program halted" << endl;
}

void Mops::writeToFile() {
	ofstream file;
	file.open("mops");
	file << getPC() << endl;
	unsigned char* mem = getMemory();
	for (int i = 0; i < getSize(); i++) {

		int value = *(mem + i);
		file << i << ":" << value << endl;
	}
	cout << "Write successfully" << endl;
	file.close();
}

void Mops::readFromFile() {

	ifstream file;
	string line;
	file.open("mops");
	if (file.is_open()) {

		getline(file, line);

		int pc = convertStringToInt(line);
		setPC(pc);

		vector<string> tokens;
		while (getline(file, line)) {
			tokens = split(line, ":");

			int add = convertStringToInt(tokens[0]);
			int value = convertStringToInt(tokens[1]);

			*(getMemory() + add) = value;
		}
		cout << "Load successfully" << endl;
	} else {
		cerr << "File is either not exist or corrupted" << endl;
	}
	file.close();
}

