/*
 * Main.h
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */
#include <cctype>

using namespace std;

int  main() {

	Stack stack = new Stack();
	string input;

	cout << "O que deseja fazer ";
	cin >> input;

	switch (input) {
	case "CRIAR":
		stack.initializeStack();
		break;
	case "LIMPAR":
		stack.initializeStack();
		break;
	case "INSERIR":
		int inputSize = strlen(input);
		break;

	}

	return 0;
}
