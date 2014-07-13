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
#include "Macrochip.h"

Microcontroller* connectToMicrocontroller();
void displayAllMemory(Microcontroller& mcontroller);
void executeFromCurrentPC(Microcontroller& mcontroller);
void executeFromLocation(Microcontroller& mcontroller);
void displayHelp();
void lookAtMemory(Microcontroller& mcontroller);
void modifyMemory(Microcontroller& mcontroller);
void reset(Microcontroller& mcontroller);
void displayPCAndRegister();
void quit();


#endif /* FACADE_H_ */
