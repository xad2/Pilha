/*
 * Stack.h
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#ifndef STACK_H_
#define STACK_H_

#define MAXSTACK 30
#define FULLSTACK_ERROR '\O'
#define EMPTYSTACK_ERROR '\O'


typedef struct {
	int data[MAXSTACK];
	int top;
} STACK;

STACK myStack;

class Stack {
public:

	Stack();
	virtual ~Stack();

	void initializeStack();
	bool fullStack(), emptyStack();
	int push(int newElement), remove();
	char showElements();

};

#endif /* STACK_H_ */
