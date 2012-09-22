/*
 * Stack.h
 *
 *  Created on: Sep 19, 2012
 *      Author: xad
 */

#ifndef _STACK_H_
#define _STACK_H_

#define MAXSTACK 30
<<<<<<< HEAD
#define FULLSTACK_ERROR '\0'
#define EMPTYSTACK_ERROR '\0'
=======
#define FULLSTACK_ERROR '\O'
#define EMPTYSTACK_ERROR '\O'

>>>>>>> 83cfb8f2cec1e4d9a22c304fb56cfac9b0d15ce7

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
