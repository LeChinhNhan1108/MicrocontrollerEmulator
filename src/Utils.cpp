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

	bool is_hex = false;

	if(s.compare(0,2,"0x") == 0){
		s = s.substr(0,2);
	}

	is_hex = s.find_first_not_of("0123456789abcdefABCDEF") == string::npos;

	if (is_hex){
		stringstream ss;
		ss << hex << s;
		ss >> value;
	}
	return value;
}

string convertIntToHexString(int value, int width){
	stringstream ss;
	ss << setw(width) << setfill('0') << hex << value;
	return ss.str();
}

int convertStringToInt(string input){
	stringstream ss(input);
	int value = 0;
	ss >> value;
	return value;
}

vector<string> split(string s, string delim){
	vector<string> elements;
	elements = boost::split(elements,s,boost::is_any_of(delim));
	return elements;
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

