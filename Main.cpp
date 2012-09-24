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


static void commandInsert(std::istream &stream, std::istream &file, Stack &stack)
{
	int number;
	stream >> number;

	std::string line;

	for (int i = 0; i < number; i++)
	{
		std::getline(file, line);
		std::stringstream stream(line);
		int element;
		stream >> element;
		stack.push(element);
	}
}

static void commandShow(Stack &stack)
{
	for (int i = stack.currentTop(); i >= 0; i--)
	{
		std::cout << stack.getElement(i) << std::endl;
	}

}

//void menu() {
//
//	// WHAT TO DO HERE
//	bool isOn = true;
//	while (isOn) {
//
//
//		cin >> input >> input2;
//
//		//Initializes the stack.
//		if (input == "CRIAR") {
//			cout << stack.currentTop() << endl;
//
//			stack.initializeStack();
//
//		} // Inserts certain amount of data after it's informed as the parameter 'input2'. The command is INSERIR <size>.
//		else if (input == "INSERIR") {
//
//			stringstream stream;
//			int number;
//			stream << input2;
//			stream >> number;
//
//			for (int i = 0; i < number; i++) {
//				stack.push(i);
//			}
//
//		} //Removes data from the top of the Stack.Only.
//		else if (input == "REMOVER") {
//
//			stack.remove();
//
//		} //Shows all data within the Stack, according to its properties. (Top element is the first and bottom is the last one).
//		else if (input == "MOSTRAR") {
//			for (int i = stack.currentTop(); i >= 0; i--) {
//				cout << stack.getElement(i) << endl;
//			}
//
//		} //Exits the program.
//		else if (input == "SAIR") {
//			isOn = false;
//			break;
//		}
//
//	}
//
//}

int main(int argc, char** argv)
{
	Stack stack;

	// If number of parameters is lesser to 2, it runs menu(), else it reads the TESTCASE subroutine.
	if (argc < 2)
	{
//		menu();
		return -1;
	}
	else
	{
		std::ifstream file(argv[1]);
		std::string line;

		//While file is not finished
		while (std::getline(file, line))
		{
			std::stringstream stream(line);
			std::string command = line;
			stream >> command;

			if (command == "CRIAR")
			{
				stack.initializeStack();
			}
			else if (command == "INSERIR")
			{
				commandInsert(stream, file, stack);
			}
			else if (command == "REMOVER")
			{
				stack.remove();

			}
			else if (command == "MOSTRAR")
			{
				commandShow(stack);

			}
			else if (command == "SAIR")
			{
				file.close();
				break;
			}

		}
	}
}

