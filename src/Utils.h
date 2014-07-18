/*
 * Utils.h
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <cstring>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;


char convertToLowerCase(char input);
void convertToLowerCase(string& input);

void clearCin();

int convertHexToInt(string input);
string convertIntToHexString(int value, int width = 2);

int convertStringToInt(string input);

vector<string> split(string s, string delim);


#endif /* UTILS_H_ */
