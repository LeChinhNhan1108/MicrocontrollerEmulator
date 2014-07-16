/*
 * Mops.cpp
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#include "Mops.h"

void Mops::reset() {
	cout << "Morps reset " << endl;
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
	case GOTO:
		gotoOpcode(location);
		break;
	case BRANCH:
		branch(location);
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
	cout << "Morps add from " << location << endl;

	int destination = location + 4;
	if (destination > getSize()) {
		cerr << "SIGWEED. Program executed past top of memory" << endl;
		return;
	}

//	*(getMemory() + location) = convertHexToInt("0a");
//	*(getMemory() + location + 1) = convertHexToInt("0b");
//	*(getMemory() + location + 2) = convertHexToInt("03");
//	*(getMemory() + location + 3) = convertHexToInt("0f");
//	*(getMemory() + location + 4) = convertHexToInt("13");
//	*(getMemory() + location + 783) = convertHexToInt("fa");

	int value = *(getMemory() + location + 1);
	int high = *(getMemory() + location + 2);
	int low = *(getMemory() + location + 3);

	int address = (high << 8 | low);

	if (address <= getSize()) {
		int currentValue = *(getMemory() + address);
		int result = currentValue + value;

//		cout << "Current Value " << currentValue << endl;
//		cout << "Result " << result << endl;


		if (result >= 256 )
			result -= 256;

		*(getMemory() + address) = result;
	}

//	cout << "Value " << value << endl;
//	cout << "Address " << address << endl;

	setPC(destination);
	execute(getPC());
}

void Mops::substract(int location){

	cout << "Morps minus from " << location << endl;

		int destination = location + 4;
		if (destination > getSize()) {
			cerr << "SIGWEED. Program executed past top of memory" << endl;
			return;
		}

//		*(getMemory() + location + 1) = convertHexToInt("fa");
//		*(getMemory() + location + 2) = convertHexToInt("03");
//		*(getMemory() + location + 3) = convertHexToInt("0f");
//		*(getMemory() + location + 4) = convertHexToInt("ff");
//		*(getMemory() + location + 783) = convertHexToInt("ff");

		int value = *(getMemory() + location + 1);
		int high = *(getMemory() + location + 2);
		int low = *(getMemory() + location + 3);

		int address = (high << 8 | low);

		if (address <= getSize()) {
			int currentValue = *(getMemory() + address);
			int result = currentValue - value;

//			cout << "Current Value " << currentValue << endl;
//			cout << "Result " << result << endl;

			if (result < 0 )
				result = 0;

			*(getMemory() + address) = result;
		}

		cout << "Value " << value << endl;
		cout << "Address " << address << endl;

		setPC(destination);
		execute(getPC());

}

void Mops::gotoOpcode(int location){

}

void Mops::branch(int location){

}

void Mops::halt(int location){
	cout << "Program halted" << endl;
}

