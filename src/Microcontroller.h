/*
 * Microcontroller.h
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#ifndef MICROCONTROLLER_H_
#define MICROCONTROLLER_H_

#include "Utils.h"
using namespace std;

class Microcontroller {

private:
	int pc;
	int msize;
	unsigned char* memory;
	string statusString;
public:
	int getPC() {
		return pc;
	}
	void setPC(int npc) {
		pc = npc;
	}
	int getSize() {
		return msize;
	}
	string getStatusString() {
		statusString = "Program counter is at 0x" + convertIntToHexString(pc);
		return statusString;
	}
	void setStatusString(string ss) {
		statusString = ss;
	}
	unsigned char* getMemory() {
		return memory;
	}


	Microcontroller(int size) {
		pc = 0;
		msize = size;
		statusString = "";
		memory = new unsigned char[size];
		for (int i = 0; i < size; i++)
			*(memory + i) = 0;
	}
	virtual ~Microcontroller() {
		delete[] memory;
	}
	virtual void reset() {}
	virtual void execute(int location) {}
	virtual void writeToFile(){};
	virtual void readFromFile(){};
};

#endif /* MICROCONTROLLER_H_ */
