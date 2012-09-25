/*
 * Stack.cpp
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#include "Stack.h"

//Initializes stack
Stack::Stack()
	: top(-1)
{

}

Stack::~Stack() {

}

void Stack::initializeStack() {
	top = -1;

}
//check whether is full or not
bool Stack::isFull() const {

	if (MAXSTACK == (top + 1)) {
		return true;
	}

	return false;

}
//check whether is empty or not.
bool Stack::isEmpty() const {

	if (-1 == top) {
		return true;
	}

	return false;

}
//Pushes one element ONLY to the top of the Stack, by definition.
int Stack::push(int newElement) {

	if (isFull()) {
		return FULLSTACK_ERROR;
	}
	top++;
	dataStorage[top] = newElement;
	return (top);

}
//Removes the top element, by definition.
int Stack::remove() {
	if (isEmpty()) {
		return EMPTYSTACK_ERROR;
	}
	top--;
	return top;

}
//Get
int Stack::getElement(int pos) const {

	if(isEmpty()){
		return EMPTYSTACK_ERROR;
	}

	return dataStorage[pos];
}

int Stack::currentTop() const {

	return top;

}

