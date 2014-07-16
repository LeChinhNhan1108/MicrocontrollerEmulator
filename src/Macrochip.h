/*
 * Macrochip.h
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#ifndef MACROCHIP_H_
#define MACROCHIP_H_

#include "Microcontroller.h"

class Macrochip:public Microcontroller{
public:
	Macrochip():Microcontroller(1536){
		setStatusString("Macrochip");
	};
	void reset();
	void execute(int location);
};
#endif /* MACROCHIP_H_ */
