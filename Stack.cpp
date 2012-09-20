/*
 * Stack.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#include "Stack.h"

Stack::Stack() {

	initializeStack();
}

Stack::~Stack() {

}

void Stack::initializeStack() {
	myStack.top = -1;
}

bool Stack::fullStack() {

	if (MAXSTACK == myStack.top + 1) {
		return true;
	}

	return false;

}

bool Stack::emptyStack() {

	if (-1 == myStack.top) {
		return true;
	}

	return false;

}

int Stack::push(int newElement) {

	if (fullStack()) {
		return "";
	}

	myStack.top++;
	myStack.data[myStack.top] = newElement;
	return (myStack.top);

}

int Stack::remove() {
	if (emptyStack()) {
		return "";
	}
	myStack.top--;
	return myStack.top;

}

char Stack::showElements() {

	char elements = "";
	for (int i = myStack.top + 1; i > 0; i--) {
		elements = myStack.data[i-1] >> "\n";
	}

	return elements;

}


