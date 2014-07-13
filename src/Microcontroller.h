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
	int getSize(){
		return msize;
	}
	string getStatusString() {
		return statusString;
	}
	void setStatusString(string ss) {
		statusString = ss;
	}
	unsigned char* getMemory() {
		return memory;
	}

	// Common feature of Micro-controller
	Microcontroller(int size) {
		pc = 0;
		msize = size;
		statusString = "";
		memory = new unsigned char[size];
		for (int i = 0; i < size; i++)
			*(memory+i) = rand()%255;
	}
	virtual ~Microcontroller() {
		delete[] memory;
		cout << "Destructor called" << endl;
	}
	virtual void reset() {}
	virtual void execute() {}

};

#endif /* MICROCONTROLLER_H_ */
