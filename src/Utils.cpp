/*
 * Utils.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: root
 */



#include "Utils.h"

int convertHexToInt(string s){
	//Check if input is hex
	int value = -1;

	bool is_hex = s.compare(0,2,"0x") == 0
			&& s.size() > 2
			&& s.find_first_not_of("0123456789abcdefABCDEF",2) == string::npos;

	if (is_hex){
		stringstream ss;
		ss << hex << s;
		ss >> value;
	}
	return value;
}

string convertIntToHexString(int value){
	stringstream ss;
	ss << setw(2) << setfill('0') << hex << value;
	return ss.str();
}

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

