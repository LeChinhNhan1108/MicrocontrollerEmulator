/*
 * Rotamola.h
 *
 *  Created on: Jul 17, 2014
 *      Author: root
 */

#ifndef ROTAMOLA_H_
#define ROTAMOLA_H_

#include "Microcontroller.h"

class Rotamola: public Microcontroller {
private:

	unsigned char a;
	unsigned char b;

	static const unsigned char MOVE_A_TO_MEM = 0x0c;
	static const unsigned char LOAD_A = 0x37;
	static const unsigned char LOAD_B = 0x38;
	static const unsigned char INCREASE_A = 0x53;
	static const unsigned char ALWAYS_BRANCH = 0x5a;
	static const unsigned char BRANCH_IF_A_LESS_THAN_B = 0x5b;
	static const unsigned char BRANCH_IF_LESS_THAN_A = 0x5d;
	static const unsigned char HALT = 0x64;

	void moveAToMem(int location);
	void loadA(int location);
	void loadB(int location);
	void increaseA(int location);
	void alwaysBranch(int location);
	void branchIfALessThanB(int location);
	void branchIfLessThanA(int location);
	void halt(int location);

public:

	Rotamola() :
			Microcontroller(512) {
		a = 0;
		b = 0;
	}

	int getA(){return a;}
	int getB(){return b;}
	void setA(int a_){a = a_;}
	void setB(int b_){b = b_;}

	void reset();
	void execute(int location);

};

#endif /* ROTAMOLA_H_ */
