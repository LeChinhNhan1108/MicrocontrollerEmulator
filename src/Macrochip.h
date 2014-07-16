/*
 * Macrochip.h
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#ifndef MACROCHIP_H_
#define MACROCHIP_H_

#include "Microcontroller.h"

class Macrochip: public Microcontroller {
private:
	unsigned char w;
	static const unsigned char MOVE_TO_W = 0x50;
	static const unsigned char MOVE_TO_MEM = 0x51;
	static const unsigned char ADD_TO_W = 0x5a;
	static const unsigned char SUBSTRACT_FROM_W = 0x5b;
	static const unsigned char ALWAYS_BRANCH = 0x6e;
	static const unsigned char BRANCH_NOT_EQUAL = 0x70;
	static const unsigned char HALT = 0xff;

public:
	Macrochip() : Microcontroller(1536) {
		setStatusString("Macrochip");
		w = 0;
	}
	void setW(int w_) {w = w_;}
	int getW(){return w;}

	void reset();
	void execute(int location);
	void moveToW(int location);
	void moveWToMemory(int location);
	void addToW(int location);
	void substractFromW(int location);
	void alwaysBranch(int location);
	void branchNotEqual(int location);
	void halt(int location);
};
#endif /* MACROCHIP_H_ */
