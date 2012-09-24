/*
 * Stack.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#include "Stack.h"


Stack::Stack()
	: top(-1)
{

}

Stack::~Stack() {

}

void Stack::initializeStack() {
	top = -1;

}

bool Stack::fullStack() const {

	if (MAXSTACK == (top + 1)) {
		return true;
	}

	return false;

}

bool Stack::emptyStack() const {

	if (-1 == top) {
		return true;
	}

	return false;

}

int Stack::push(int newElement) {

	if (fullStack()) {
		return FULLSTACK_ERROR;
	}
	top++;
	dataStorage[top] = newElement;
	return (top);

}

int Stack::remove() {
	if (emptyStack()) {
		return EMPTYSTACK_ERROR;
	}
	top--;
	return top;

}

int Stack::getElement(int pos) const {

	if(emptyStack()){
		return EMPTYSTACK_ERROR;
	}

	return dataStorage[pos];
}

int Stack::currentTop() const {

	return top;

}

