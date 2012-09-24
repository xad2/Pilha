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

static void printPrompt()
{
	std::cout << "Comando: ";
}

static void printInitialHelp()
{
	std::cout << "Supported commands: " << std::endl
			<< "\t\""<< CREATE_STR << "\"" << std::endl
			<< "\t\""<< HELP_STR << "\"" << std::endl
			<< "\t\""<< EXIT_STR << "\"" << std::endl;
}

static void printHelp()
{
	std::cout << "Supported commands: " << std::endl
			<< "\t\""<< INSERT_STR << "\" N (N > 0)" << std::endl
			<< "\t\""<< REMOVE_STR << "\"" << std::endl
			<< "\t\""<< SHOW_STR << "\"" << std::endl
			<< "\t\""<< HELP_STR << "\"" << std::endl
			<< "\t\""<< EXIT_STR << "\"" << std::endl;
}

static void printError(const std::string &command)
{
	std::cout << "!!! Comando inválido: \"" << command << "\"" << std::endl;
}

static void printEmptyStack()
{
	std::cout << "*** Pilha vazia!" << std::endl;
}

// return true if error
bool toInt(int &val, const std::string &string)
{
	const char *start = string.c_str();
	char *end;
	val = strtol(start, &end, 10);
	return end == start|| *end != '\0';
}

static void interactiveExecute(Stack &stack)
{
	bool isCreated = false;
	while (true)
	{
		if (!isCreated)
			printInitialHelp();
		else
			printHelp();

		printPrompt();

		std::string command;
		std::getline(std::cin, command);

		if (strcasecmp(command.c_str(), EXIT_STR) == 0)
		{
			std::cout << "Bye" << std::endl;
			break;
		}
		else if (strcasecmp(command.c_str(), HELP_STR) == 0)
		{
			continue;
		}
		else
		{
			std::stringstream stream(command);

			std::string subCommand;
			stream >> subCommand;

			if (isCreated)
			{
				if (strcasecmp(subCommand.c_str(), INSERT_STR) == 0)
				{
					int n;
					stream >> n;

					for (int i = 0; i < n; ++i)
					{
						int val;
						do
						{
							std::cout << "[" << i << "/" << n << "]: ";
							std::getline(std::cin, subCommand);
						}
						while (toInt(val, subCommand));

						stack.push(val);
					}
				}
				else if (strcasecmp(subCommand.c_str(), REMOVE_STR) == 0)
				{
					stack.remove();
					if (stack.emptyStack())
					{
						isCreated = false;
						printEmptyStack();
					}
				}
				else if (strcasecmp(subCommand.c_str(), SHOW_STR) == 0)
				{
					commandShow(stack);
				}
				else
				{
					printError(command);
				}
			}
			else if (strcasecmp(subCommand.c_str(), CREATE_STR) == 0)
			{
				stack.initializeStack();
				isCreated = true;
			}
			else
			{
				printError(command);
			}
		}
	}
}

static void executeFromFile(Stack &stack, const std::string &filename)
{
	std::ifstream file(filename.c_str());
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

int main(int argc, char** argv)
{
	Stack stack;

	if (argc < 2)
	{
		interactiveExecute(stack);
	}
	else
	{
		executeFromFile(stack, argv[1]);
	}
}

