/*
 * Main.cpp
 *
 *  Created on: Sep 20, 2012
 *      Authors: Alexandre and Tao
 *
 *
 *
 */

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Stack.h"


static const char CREATE_STR[] = "Criar";
static const char INSERT_STR[] = "Inserir";
static const char REMOVE_STR[] = "Remover";
static const char SHOW_STR[] = "Mostrar";
static const char EXIT_STR[] = "Sair";
static const char HELP_STR[] = "Ajuda";
static const char EMPTY_STR[] = "Pilha Vazia.";


//this is the static method that inserts all data inside the stack, provided by the command INSERIR <quantity>
static void commandInsert(std::istream &stream, std::istream &file, Stack &stack) {
	int number;
	stream >> number;

	std::string line;

	for (int i = 0; i < number; i++) {
		std::getline(file, line);
		std::stringstream stream(line);
		int element;
		stream >> element;
		stack.push(element);
	}
}

//this method we show all data from the stack, starting by the top element and ending with the bottom
static void commandShow(Stack &stack, std::ostream &output) {

	if (stack.isEmpty()) {
		output << EMPTY_STR << std::endl;
		return;
	}

	for (int i = stack.currentTop(); i >= 0; i--) {

		output << stack.getElement(i) << std::endl;
	}

}
// the next 4 methods are simple methods to improve user-terminal interaction
static void printPrompt() {
	std::cout << "Comando: ";
}

static void printInitialHelp() {
	std::cout << "Supported commands: " << std::endl << "\t\"" << CREATE_STR
			<< "\"" << std::endl << "\t\"" << HELP_STR << "\"" << std::endl
			<< "\t\"" << EXIT_STR << "\"" << std::endl;
}

static void printHelp() {
	std::cout << "Supported commands: " << std::endl << "\t\"" << INSERT_STR
			<< "\" N (N > 0)" << std::endl << "\t\"" << REMOVE_STR << "\""
			<< std::endl << "\t\"" << SHOW_STR << "\"" << std::endl << "\t\""
			<< HELP_STR << "\"" << std::endl << "\t\"" << EXIT_STR << "\""
			<< std::endl;
}

static void printError(const std::string &command) {
	std::cout << "!!! Comando inválido: \"" << command << "\"" << std::endl;
}



// return true if error and make the selected parameter string turn into a integer named val
bool toInt(int &val, const std::string &string) {
	const char *start = string.c_str();
	char *end;
	val = strtol(start, &end, 10);
	return end == start || *end != '\0';
}

//this is the method that will launch if the user doesn't run the testcases
static void interactiveExecute(Stack &stack) {
	bool isCreated = false;

	//prints one of these methods if stack was created or not
	while (true) {
		if (!isCreated)
			printInitialHelp();
		else
			printHelp();

		printPrompt();

		std::string command;
		std::getline(std::cin, command);
		//above, it gathers the string input and below the if/else structure compares the input with the constants already defined
		if (strcasecmp(command.c_str(), EXIT_STR) == 0) {
			std::cout << "Bye" << std::endl;
			break;
		} else if (strcasecmp(command.c_str(), HELP_STR) == 0) {
			continue;
		} else {
			std::stringstream stream(command);

			std::string subCommand;
			stream >> subCommand;
			//stream holds the value of subCommand ( in this case, the next argument of INSERIR <quantity>)
			if (isCreated) {
				if (strcasecmp(subCommand.c_str(), INSERT_STR) == 0) {
					int n;
					stream >> n;

					for (int i = 0; i < n; ++i) {
						int val;
						/* Converts data the user sends according to the quantity number previously stated and after the
						 * conversion it pushes it, and so on.
						 */
						do {
							std::cout << "[" << i << "/" << n << "]: ";
							std::getline(std::cin, subCommand);
						} while (toInt(val, subCommand));

						stack.push(val);
					}
					//Removes element from the top
				} else if (strcasecmp(subCommand.c_str(), REMOVE_STR) == 0) {
					stack.remove();
					if (stack.isEmpty()) {
						isCreated = false;
						std::cout << EMPTY_STR;
					}
					//Show all data within Stack.
				} else if (strcasecmp(subCommand.c_str(), SHOW_STR) == 0) {
					commandShow(stack, std::cout);
				} else {
					printError(command);
				}
				//Initializes stack.
			} else if (strcasecmp(subCommand.c_str(), CREATE_STR) == 0) {
				stack.initializeStack();
				isCreated = true;
			} else {
				printError(command);
			}
		}
	}
}
//These methods are part of the casetest. It launches, if number of arguments are greater than 1 or second argument isn't --test.
static void executeFromFile(Stack &stack, std::istream &input, std::ostream &output) {
	std::string line;

	//While file is not finished
	while (std::getline(input, line)) {
		std::stringstream stream(line);
		std::string command = line;
		stream >> command;

		//Much like the previous method, though simpler.
		if (command == "CRIAR") {
			stack.initializeStack();
		} else if (command == "INSERIR") {
			commandInsert(stream, input, stack);
		} else if (command == "REMOVER") {
			stack.remove();
		} else if (command == "MOSTRAR") {
			commandShow(stack, output);

		} else if (command == "SAIR") {
			break;
		}
	}
}

static void executeFromFile(Stack &stack, const std::string &filename) {
	std::ifstream file(filename.c_str());
	executeFromFile(stack, file, std::cout);
}

/*An experimental method, that makes it easier to run casetests. Requires a test_data folder with all of them inside and the
 *argument --test. Example: ./main.cc --test
 */
static void runTestCases() {
	static const char* inputFiles[] = { "test_data/Caso1.in",
			"test_data/Caso2.in", "test_data/Caso3.in",
			"test_data/PilhaCheia.in", "test_data/PilhaVazia.in" };

	int nfiles = sizeof(inputFiles) / sizeof(inputFiles[0]);

	for (int i = 0; i < nfiles; ++i)
	{
		Stack stack;

		std::ifstream inputData(inputFiles[i]);
		if (!inputData)
		{
			std::cerr << "Não pude abrir " << inputFiles[i] << std::endl;
			continue;
		}

		std::cout << "Testing file: " << inputFiles[i];

		std::string expectedDataFilename = inputFiles[i];
		std::string::size_type pos = expectedDataFilename.find_first_of(".in", 0);
		expectedDataFilename.replace(pos, pos + 3, ".out");
		std::ifstream expectedData(expectedDataFilename.c_str());

		std::stringstream resultData;

		executeFromFile(stack, inputData, resultData);

		std::string expectedBuffer, resultBuffer;
		while (std::getline(expectedData, expectedBuffer))
		{
			if (!std::getline(resultData, resultBuffer)) {
				std::cout << "\tERRO; expected: " << expectedBuffer << ", result: [empty]" << std::endl;
				break;
			}

			if (expectedBuffer != resultBuffer) {
				std::cout << "\tERRO; expected: " << expectedBuffer << ", result: " << resultBuffer << std::endl;
				break;
			}
		}

		std::cout << "\tOK!" << std::endl;

	}

}

int main(int argc, char** argv) {
	Stack stack;

	if (argc < 2) {
		interactiveExecute(stack);
	} else {
		if (strcasecmp(argv[1], "--test") == 0) {
			runTestCases();
		} else {
			executeFromFile(stack, argv[1]);
		}
	}
}

