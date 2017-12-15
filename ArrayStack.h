#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "Stack.h"
//#include "Object.h"

class ArrayStack: public Stack{

	private:
		string** array;
		int size;
		int availPos;


	public:
		ArrayStack(int);
		virtual bool push(string*);
		virtual string* pop();
		virtual bool isEmpty();
		~ArrayStack();

};

#endif
