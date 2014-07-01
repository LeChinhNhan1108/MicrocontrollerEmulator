/*
 * Facade.h
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#ifndef FACADE_H_
#define FACADE_H_

#include "../Utilities/Utils.h"

void connectToMicrocontroller();
void displayAllMemory();
void executeFromCurrentPC();
void executeFromLocation();
void displayHelp();
void lookAtMemory();
void modifyMemory();
void reset();
void displayPCAndRegister();
void quit();


#endif /* FACADE_H_ */
