/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: xad
 */

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

Stack stack;
string input;
string numberInput;

int convert(string str) {
	int quantidade;
	stringstream ss;
	ss << str;
	ss >> quantidade;
	ss.str("");
	ss.clear();
	return quantidade;
}

void menu() {

	bool isOn = true;
	while (isOn) {

		cin >> input;

	}
}

void lerCasoDeTestes(char* argv) {

}

int main(int argc, char** argv) {

	ifstream file(argv[1]);

	char line[256];

	while (!file.eof()) {

		file.getline(line, 256);

		stringstream stream(line);
		string command;
		stream >> command;

		if (command == "CRIAR") {

			stack.initializeStack();

		} else if (command == "INSERIR") {
			int number;
			stream >> number;

			for(int i = 0; i < number; i++){
				file.getline(line, 256);
				stringstream stream(line);
				int element;
				stream >> element;
				stack.push(element);
			}

		} else if (command == "MOSTRAR") {

			for(int i = stack.currentTop(); i > 0; i-- ){
				printf("%c", stack.getTopElement());
			}

		} else if (command == "SAIR") {
			break;
		}

	}
//	if (argc < 2) {
//		menu();
//	} else {
//		lerCasoDeTestes(argv[1]);
//	}

}

