/*
 * Stack.h
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#ifndef _STACK_H_
#define _STACK_H_

#define MAXSTACK 30
#define FULLSTACK_ERROR '\0'
#define EMPTYSTACK_ERROR '\0'




class Stack {

private:
	int data[MAXSTACK];
	int top;

public:

	Stack();
	~Stack();

	void initializeStack();
	bool fullStack(), emptyStack();
	int push(int newElement), remove(), getTopElement(), currentTop();


};

#endif /* _STACK_H_ */
