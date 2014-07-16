/*
 * Mops.h
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#ifndef MOPS_H_
#define MOPS_H_

#include "Microcontroller.h"

class Mops:public Microcontroller{

private:
	static const unsigned char ADD = 0x0a;
	static const unsigned char SUBTRACT = 0x13;
	static const unsigned char GOTO = 0x16;
	static const unsigned char BRANCH = 0x17;
	static const unsigned char HALT = 0xff;

	void add(int location);
	void substract(int location);
	void gotoOpcode(int location);
	void branch(int location);
	void halt(int location);

public:
	Mops():Microcontroller(1024){
		setStatusString("Mops");
	};
	void reset();
	void execute(int location);

};




#endif /* MOPS_H_ */
