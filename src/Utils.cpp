/*
 * Utils.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */



#include "Utils.h"

char convertToLowerCase(char input){
	return tolower(input);
}

void convertToLowerCase(string& input){
	boost::algorithm::to_lower(input);
}

void clearCin(){
	cin.clear();
	cin.ignore(10000,'\n');
}

