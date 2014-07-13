/*
 * Utils.h
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
using namespace std;


char convertToLowerCase(char input);
void convertToLowerCase(string& input);

void clearCin();

int convertHexToInt(string input);
string convertIntToHexString(int value);


#endif /* UTILS_H_ */
