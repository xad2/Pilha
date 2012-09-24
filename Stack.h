/*
 * Stack.h
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#ifndef _STACK_H_
#define _STACK_H_

#define MAXSTACK 30
#define FULLSTACK_ERROR -2
#define EMPTYSTACK_ERROR -1

class Stack {

private:
	int dataStorage[MAXSTACK];
	int top;

public:

	Stack();
	~Stack();

	void initializeStack();
	bool isFull() const;
	bool isEmpty() const;
	int push(int newElement);
	int remove();
	int getElement(int pos) const;
	int currentTop() const;

};

#endif /* _STACK_H_ */
