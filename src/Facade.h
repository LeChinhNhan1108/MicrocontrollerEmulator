/*
 * Facade.h
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#ifndef FACADE_H_
#define FACADE_H_

#include "Utils.h"
#include "Microcontroller.h"
#include "Mops.h"

Microcontroller* connectToMicrocontroller();
void displayAllMemory();
void executeFromCurrentPC();
void executeFromLocation();
void displayHelp();
void lookAtMemory();
void modifyMemory();
void reset(Microcontroller* mcontroller);
void displayPCAndRegister();
void quit();


#endif /* FACADE_H_ */
