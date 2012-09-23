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
			stringstream stream2;
			stream2 >> number;

			for (int i = 0; i < number; i++) {
				file.getline(line, 256);
				stringstream stream(line);
				char element;
				stream >> element;
				stack.push(element);
			}

		} else if (command == "MOSTRAR") {

			for (int i = stack.currentTop(); i >= 0; i--) {
				cout << stack.getTopElement() << endl;
			}

		} else if (command == "SAIR") {
			file.close();
			break;
		}

	}

}

