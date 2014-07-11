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

class Microcontroller{

private:
	int pc;
	unsigned char* memory;
	string statusString;
public:
	int getPC(){return pc;};
	string getStatusString(){return statusString;};
	void setStatusString(string ss){statusString=ss;};
	unsigned char* getMemory(){return memory;};

	// Common feature of Micro-controller
	Microcontroller(){};
	virtual ~Microcontroller(){};
	virtual void reset(){};
	virtual void lookAtMemory(){};
	virtual void modifyMemory(){};
	virtual void displayMemory(){};
	virtual void execute(){};


};



#endif /* MICROCONTROLLER_H_ */
