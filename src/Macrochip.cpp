/*
 * Macrochip.cpp
 *
 *  Created on: Jul 11, 2014
 *      Author: root
 */

#include "Macrochip.h"

void Macrochip::reset(){
	cout << "Macrochip reset " << endl;
}

void Macrochip::execute(int location){
	cout << "Macrochip execute from " << location <<endl;
}
