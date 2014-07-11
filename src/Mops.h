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
public:
	Mops(){};
	~Mops(){};
	void reset();
	void lookAtMemory();
	void modifyMemory();
	void displayMemory();
	void execute();
};




#endif /* MOPS_H_ */
