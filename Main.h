/*
 * Main.h fazer Main.cc
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */
#include <cctype>

using namespace std;

Stack stack;


int  main(int argc, char** argv) {

	if(argc < 2 ){
		
	}else{
		
	}
	

	string input; // char [] ???

	cout << "O que deseja fazer ? "; //certo?
	cin >> input;
	cout << endl;
	
	switch (input) {
	case "CRIAR":
		stack.initializeStack();
		break;
	case "LIMPAR":
		stack.initializeStack();
		break;
	case "INSERIR":
		
		break;

	}

	return 0;
}
