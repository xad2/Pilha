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
string input2;

void menu() {

	// WHAT TO DO HERE
	bool isOn = true;
	while (isOn) {


		cin >> input >> input2;

		//Initializes the stack.
		if (input == "CRIAR") {
			cout << stack.currentTop() << endl;

			stack.initializeStack();

		} // Inserts certain amount of data after it's informed as the parameter 'input2'. The command is INSERIR <size>.
		else if (input == "INSERIR") {

			stringstream stream;
			int number;
			stream << input2;
			stream >> number;

			for (int i = 0; i < number; i++) {
				stack.push(i);
			}

		} //Removes data from the top of the Stack.Only.
		else if (input == "REMOVER") {

			stack.remove();

		} //Shows all data within the Stack, according to its properties. (Top element is the first and bottom is the last one).
		else if (input == "MOSTRAR") {
			for (int i = stack.currentTop(); i >= 0; i--) {
				cout << stack.getElement(i) << endl;
			}

		} //Exits the program.
		else if (input == "SAIR") {
			isOn = false;
			break;
		}

	}

}
int main(int argc, char** argv) {

	// If number of parameters is lesser to 2, it runs menu(), else it reads the TESTCASE subroutine.
	if (argc < 2) {
		menu();
	} else {
		ifstream file(argv[1]);
		char line[256];

		//While file is not finished
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

				for (int i = 0; i < number; i++) {
					file.getline(line, 256);
					stringstream stream(line);
					int element;
					stream >> element;
					stack.push(element);
				}

			} else if (command == "REMOVER") {
				stack.remove();

			} else if (command == "MOSTRAR") {

				for (int i = stack.currentTop(); i >= 0; i--) {

					cout << stack.getElement(i) << endl;
				}

			} else if (command == "SAIR") {
				file.close();
				break;
			}

		}
	}
}

